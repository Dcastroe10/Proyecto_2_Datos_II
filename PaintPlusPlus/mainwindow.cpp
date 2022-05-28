#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QColorDialog>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->canvasLabel, SIGNAL(sendMousePosition(int&, int&)), this, SLOT(mouseMove(int&, int&)));
    connect(ui->canvasLabel, SIGNAL(sendMouseClicked(int&, int&)), this, SLOT(mouseIsPressed(int&, int&)));
    connect(ui->canvasLabel, SIGNAL(sendMouseReleased(int&, int&)), this, SLOT(mouseIsReleased(int&, int&)));
    color = rgbToHex(0,0,0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Crea un canvas con las dimensiones ingresadas por el usuario
 * @param x     Ancho del canvas
 * @param y     Alto del canvas
 */
void MainWindow::receiveCanvas(int& x, int& y) {
    createNewCanvas(x, y);
}

/**
 * @brief Crea un canvas con las dimensiones ingresadas por el usuario
 * @param x     Ancho deseado
 * @param y     Alto deseado
 */
void MainWindow::createNewCanvas(int x, int y)
{

    ui->zoomSpin->setValue(1.0);

    ui->canvasLabel->setEnabled(true);
    ui->canvasLabel->createNewMatrix(x, y);

    this->tools.setMatrixPointer(ui->canvasLabel->getMatrix());

    this->imageDimensions[0] = x;
    this->imageDimensions[1] = y;

    ui->gridLayout->setGeometry(QRect(x, y, x, y));
    fillCanvas(255, 255, 255, x, y);

    on_zoomSpin_valueChanged(1.1);
    on_zoomSpin_valueChanged(1.0);

}

/**
 * @brief Convierte un color en valores de red green blue a un color hexadecimal
 * @param r     Valor del red
 * @param g     Valor del green
 * @param b     Valor del blue
 * @return  El color en hexadecimal
 */
uint32_t MainWindow::rgbToHex(int r, int g, int b) {
    return ((r & 0xFF) << 16) + ((g & 0xFF) << 8) + ((b & 0xFF));
}

/**
 * @brief Rellena el canvas de las dimensiones asignadas del color deseado
 * @param r     Valor del red
 * @param g     Valor del green
 * @param b     Valor del blue
 * @param x     Ancho del canvas
 * @param y     Alto del canvas
 */
void MainWindow::fillCanvas(int r, int g, int b, int x, int y)
{
    QImage *image = new QImage(x, y, QImage::Format_RGB32);
    uint32_t color = rgbToHex(r, g, b);
    for (int xi = 0; xi < x; xi++) {
        for (int yi = 0; yi < y; yi++) {
            image->setPixel(xi, yi, color);
        }
    }

    ui->canvasLabel->setPixmap(QPixmap::fromImage(*image));
    delete image;
}

/**
 * @brief Detecta cuando el mouse es presionado
 * @param x     Coord x del clik
 * @param y     Coord y del click
 */
void MainWindow::mouseIsPressed(int& x, int& y)
{
    this->mousePressedInCanvas = true;
    this->firstClick[0] = x;
    this->firstClick[1] = y;
    this->color = this->last_color;

    if (this->penF) {
        setPixelInCanvas(x, y, this->id_pen);
    }else if(this->freeEraserF){
        this->last_color = this->color;
        this->color = rgbToHex(255,255,255);
        setPixelInCanvas(x,y, -1);
    }
}

/**
 * @brief Detecta cuando el mouse es presionado y luego liberado
 * @param x     Coord x del click
 * @param y     Coord y del click
 */
void MainWindow::mouseIsReleased(int& x, int& y)
{
    pixel **matrix = ui->canvasLabel->getMatrix();
    this->mousePressedInCanvas = false;
    this->color = this->last_color;
    this->clickReleased[0] = x;
    this->clickReleased[1] = y;

    tools.add_toUndoList(-1,-1,this->id_pen,-1,-1,-1,-1,this->color);
                                                    //CHEEEECK ESTOOO puede ser lo que sube extra
                                                    //ES PARA AGREGAR AL UNDO LAS LINEAS DEL PEN pero
    this->id_pen = this->id_figuras;                //con las figuras agrega otros ids entonces hay que tocar
    this->id_figuras++;                             //varias (2) veces el botón de undo

    if (this->pencilF) {
        drawALine(this->firstClick, this->clickReleased);
    } else if (this->squareF){
        drawSquare(this->firstClick, this->clickReleased);
    } else if(this->circleF){
        drawCircle(this->firstClick, this->clickReleased);
    } else if (this->colorPickerF){
        this->color = tools.getColorColorPicker(x / this->zoom, y / this->zoom);
        this->last_color = this->color;
        on_penButton_clicked();
    } else if (this->paintFillF) {
        usePaintFill(x, y);
    }else if(this->figureEraserF){
        x /= this->zoom;
        y /= this->zoom;
        this->delete_figure(matrix[x][y].getId());
    }else if (this->rectangularSelection){
        tools.set_RectangularSelected_size(this->imageDimensions[0], this->imageDimensions[1]);
        tools.rectangularSelection(this->firstClick, this->clickReleased);
    }

}

/**
 * @brief Detecta el movimiento del mouse
 * @param x     Coord x del click
 * @param y     Coord y del clicl
 */
void MainWindow::mouseMove(int &x, int &y)
{
    std::string location = std::to_string(x) + ", " + std::to_string(y);
    ui->mouseLocationLabel->setText(QString::fromStdString(location));

    setPixelInCanvas(x, y, this->id_pen);

}

/**
 * @brief Actualiza el canvas en la aplicación con los datos de la matriz de pixeles
 */
void MainWindow::updateCanvas() {
    int x = this->imageDimensions[0];
    int y = this->imageDimensions[1];
    pixel **matrix = ui->canvasLabel->getMatrix();
    QImage canvas = ui->canvasLabel->pixmap().toImage();
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            canvas.setPixel(i, j, matrix[i][j].getColor());
        }
    }
    ui->canvasLabel->setPixmap(QPixmap::fromImage(canvas));
}

/**
 * @brief Llama a la función de paintfill para pintar el área  por medio del bfs
 * @param posX      Posición x del pixel
 * @param posY      Posición y del pixel
 */
void MainWindow::usePaintFill(int posX, int posY) {
    posX /= this->zoom;
    posY /= this->zoom;
    tools.drawWithPaintFiller(this->imageDimensions[0], this->imageDimensions[1], this->color, posX, posY,this->id_figuras);
    this->id_figuras++;
    updateCanvas();
}

/**
 * @brief Dibuja una línea recta en el canvass
 * @param start     Posiciones (x,y) iniciales
 * @param end       Posiciones (x,y) finales
 */
void MainWindow::drawALine(int start[], int end[]) {
    start[0] /= this->zoom;
    start[1] /= this->zoom;
    end[0] /= this->zoom;
    end[1] /= this->zoom;
    tools.drawWithPencil(start, end, this->color,ui->spinBox->value(), this->id_figuras, imageDimensions[0], imageDimensions[1]);
    this->id_figuras++;
    this->id_pen = this->id_figuras;
    updateCanvas();
}

/**
 * @brief LLama a la función de dibujar un cuadrado en el canvas
 * @param start     Posiciones (x,y) iniciales
 * @param end       Posiciones (x,y) finales
 */
void MainWindow::drawSquare(int *start, int *end){
    tools.drawSquare(start, end, this->color,ui->spinBox->value(),this->id_figuras, this->imageDimensions[0], this->imageDimensions[1]);
    this->id_figuras++;
    this->id_pen = this->id_figuras;
    updateCanvas();
}

/**
 * @brief Llama a la función de dibujar un círculo en el canvas
 * @param start     Posiciones (x,y) iniciales
 * @param end       Posiciones (x,y) finales
 */
void MainWindow::drawCircle(int *start, int *end){
    start[0] /= this->zoom;
    start[1] /= this->zoom;
    end[0] /= this->zoom;
    end[1] /= this->zoom;
    tools.drawCircle(start, end, this->color,ui->spinBox->value(), this->id_figuras, this->imageDimensions[0], this->imageDimensions[1]);
    this->id_figuras++;
    this->id_pen = this->id_figuras;
    updateCanvas();
}

/**
 * @brief Cambia el color de un pixel dado en el canvas
 * @param x     posición x del pixel
 * @param y     posición y del pixel
 * @param id    identificador para el pixel
 */
void MainWindow::setPixelInCanvas(int x, int y, int id) {
    if ((this->penF || this->freeEraserF)&& this->mousePressedInCanvas) {
        QImage canvas = ui->canvasLabel->pixmap().toImage();
        int grosor = ui->spinBox->value();

        for (int i = -grosor; i < grosor; i++){
            for(int j = -grosor; j < grosor; j++){
                if (!tools.pencil.outOfBounds(this->imageDimensions[0], this->imageDimensions[1], (x + i), (y + j))) {
                    canvas.setPixel((x + i) / this->zoom, (y + j) / this->zoom, this->color);
                    tools.drawWithPen((x + i) / this->zoom, (y + j) / this->zoom, this->color, id);
                }
            }
        }
        ui->canvasLabel->setPixmap(QPixmap::fromImage(canvas));
    }
}

/**
 * @brief Eliminar una figura completa o trazo
 * @param id    Identificador que se desea eliminar
 */
void MainWindow::delete_figure(int id){
    pixel **matrix = ui->canvasLabel->getMatrix();
    int check = id;
    if (check == -1){
        qDebug()<<"NO ES FIGURA";
    }else{
        for (int i = 0; i < imageDimensions[0]; i++){
            for(int j = 0; j < imageDimensions[1];j++){
                if(matrix[i][j].getId() == check){
                    matrix[i][j].setColor(this->rgbToHex(255,255,255));
                    matrix[i][j].setId(-1);
                }
            } 
        }
        this->updateCanvas();
    }
}


void MainWindow::on_actionNuevo_triggered()
{
    createcanvasDialog = new createCanvasDialog();
    connect(createcanvasDialog, SIGNAL(accept(int&, int&)), this, SLOT(receiveCanvas(int&, int&)));
    createcanvasDialog->setModal(true);
    createcanvasDialog->exec();

    on_penButton_clicked();
}

/**
 * @brief cambia a false todas las variables de control que tienen
 * relación con tools
 */
void MainWindow::falseAllTools()
{
    this->penF = false;
    this->pencilF = false;
    this->squareF = false;
    this->circleF = false;
    this->colorPickerF = false;
    this->paintFillF = false;
    this->freeEraserF = false;
    this->figureEraserF = false;
    this->rectangularSelection = false;
    this->magiSelection = false;
    this->freeformSelection = false;
}

/**
 * @brief habilita todos los botones de tools en la aplicación
 */
void MainWindow::trueAllButtons() {
    ui->penButton->setEnabled(true);
    ui->pencilButton->setEnabled(true);
    ui->squareButton->setEnabled(true);
    ui->circle_Button->setEnabled(true);
    ui->colorPickerButton->setEnabled(true);
    ui->paintFillButton->setEnabled(true);
    ui->eraserButton->setEnabled(true);
    ui->figureeraserButton->setEnabled(true);
    ui->Color_button->setEnabled(true);
    ui->spinBox->setEnabled(true);
    ui->RectangularSelectionButton->setEnabled(true);
    ui->FreeFormSelectionButton->setEnabled(true);
    ui->MagicSelectionButton->setEnabled(true);
}

/**
 * @brief Obtiene los colores en valores de rgb para el pixel deseado
 * @param X     posición x del pixel
 * @param Y     posición y del pixel
 */
void MainWindow::getpixelRgb(int X, int Y){
    pixel **matrix = ui->canvasLabel->getMatrix();
    uint32_t color = matrix[X][Y].getColor();
    int decimal = color;
    std::string myHexa[7];
    std::string hexaColor;
    int digito[30];
    int residuo;
    int resultado;
    int i = 0;
    int wow = 0;
    do{
        residuo=decimal%16;
        resultado=decimal/16;
        digito[i]=residuo;
        decimal = resultado;
        i++;
    }while(resultado>15);
    digito[i] = resultado;
    for (int x = i;x>=0;x--){
        if(digito[x] == 10){
            myHexa[wow] = 'A';
        }else{
            if(digito[x] == 11){
                myHexa[wow] = 'B';
            }else{
                if(digito[x] == 12){
                    myHexa[wow] = 'C';
                }
                else{
                    if(digito[x] == 13){
                        myHexa[wow] = 'D';
                    }
                    else{
                        if(digito[x] == 14){
                            myHexa[wow] = 'E';
                        }
                        else{
                            if(digito[x] == 15){
                                myHexa[wow] = 'F';
                            }
                            else{
                                myHexa[wow] = digito[x] + '0';
                            }
                        }
                    }
                }
            }
        }
        wow++;
    }
    for (int w = std::size(myHexa)-1 ; w >0 ; w--){
        myHexa[w] = myHexa [w-1];
    }
    myHexa[0] = '#';
    for(int e = 0 ; e < std::size(myHexa); e++){
        hexaColor += myHexa[e];
    }
    char const *hexColor = hexaColor.c_str();
    std::sscanf(hexColor, "#%02x%02x%02x", &this->red, &this->green, &this->blue);
}

/**
 * @brief reset a los valores globales de rgb de mainwindow
 */
void MainWindow::resetRGB(){
    this->red = 0;
    this->green = 0;
    this->blue = 0;
}

void MainWindow::on_penButton_clicked()
{
    falseAllTools();
    this->penF = true;
    trueAllButtons();
    ui->penButton->setEnabled(false);
}

void MainWindow::on_pencilButton_clicked()
{
    falseAllTools();
    this->pencilF = true;
    trueAllButtons();
    ui->pencilButton->setEnabled(false);
}

void MainWindow::on_squareButton_clicked()
{
    falseAllTools();
    this->squareF = true;
    trueAllButtons();
    ui->squareButton->setEnabled(false);
}

void MainWindow::on_circle_Button_clicked()
{
    falseAllTools();
    this->circleF = true;
    trueAllButtons();
    ui->circle_Button->setEnabled(false);
}

void MainWindow::on_colorPickerButton_clicked()
{
    falseAllTools();
    this->colorPickerF = true;
    trueAllButtons();
    ui->colorPickerButton->setEnabled(false);
}

void MainWindow::on_eraserButton_clicked()
{
    falseAllTools();
    this->freeEraserF = true;
    trueAllButtons();
    ui->eraserButton->setEnabled(false);
}

void MainWindow::on_figureeraserButton_clicked()
{
    falseAllTools();
    this->figureEraserF = true;
    trueAllButtons();
    ui->figureeraserButton->setEnabled(false);
}

void MainWindow::on_Color_button_clicked()
{
    QColor code = QColorDialog::getColor(Qt::blue,this, "Select Color", QColorDialog::DontUseNativeDialog);
    int red = code.red();
    int green = code.green();
    int blue = code.blue();
    this->color = rgbToHex(red, green, blue);
    this->last_color = this->color;

}

void MainWindow::on_pushButton_3_clicked()
{
    this->updateCanvas();

}

void MainWindow::on_paintFillButton_clicked()
{
    falseAllTools();
    this->paintFillF = true;
    trueAllButtons();
    ui->paintFillButton->setEnabled(false);
}

void MainWindow::on_undoButton_clicked()
{  
    if (tools.getUndoSize() != 1){
        qDebug()<<"UNDO DONE -> ";
        //tools.print_listUndo();
        qDebug()<<tools.getUndo();
        tools.add_toRedoList(tools.getStartX_UndoList(),tools.getStartY_UndoList(),
                             tools.getUndo(),tools.getEndX_UndoList(),tools.getEndY_UndoList(),
                             tools.getUndoFigura(),tools.getGrosorUndo(),tools.getColorUndo());

        this->delete_figure(tools.getUndo());
        //this->delete_figure(tools.getUndo());
        tools.deleteUndo();
    }else{
        this->delete_figure(tools.getUndo());
        qDebug()<<"NO MORE TO UNDO";
    }

}

void MainWindow::on_redolistButton_clicked()
{
    if(tools.getRedoSize() != 0){
        int *start = new int[2];
        int *end = new int[2];
        start[0] = tools.getStartX_RedoList();
        start[1] = tools.getStartY_RedoList();
        end[0] = tools.getEndX_RedoList();
        end[1] = tools.getEndY_RedoList();

        if(tools.getRedoFigura() ==0){
            //the pen
        }
        if(tools.getRedoFigura() == 1){
            tools.drawWithPencil(start,end,tools.getColorRedo(),tools.getGrosorRedo(),tools.getRedo(), imageDimensions[0], imageDimensions[1]);
        }
        if(tools.getRedoFigura() == 2){
            tools.drawSquare(start,end, tools.getColorRedo(), tools.getGrosorRedo(),tools.getRedo(), imageDimensions[0], imageDimensions[1]);
        }
        if(tools.getRedoFigura() == 3){
            tools.drawCircle(start,end,tools.getColorRedo(),tools.getGrosorRedo(),tools.getRedo(), this->imageDimensions[0], this->imageDimensions[1]);
        }
        this->updateCanvas();
        tools.deleteRedo();
    }
}

void MainWindow::on_actionAbrir_triggered()
{
    std::string file = QFileDialog::getOpenFileName(this, "Escoge un archivo", QDir::homePath()).toStdString();
    if (file != "") {
        uint32_t** image = tools.BMP.convertToUint32(tools.BMP.readBMP(file));
        if (image != NULL) {
            int width = tools.BMP.getWidth();
            int height = tools.BMP.getHeight();
            createNewCanvas(width, height);

            QImage canvas = ui->canvasLabel->pixmap().toImage();

            for (int y = 0; y < height; y++) {
                for (int x = 0; x < width; x++) {
                    canvas.setPixel(x, height - y, image[x][y]);

                    ui->canvasLabel->getMatrix()[x][height - y].setColor(image[x][y]);
                }
            }

            ui->canvasLabel->setPixmap(QPixmap::fromImage(canvas));

            on_penButton_clicked();
        } else {
            QMessageBox msg;
            msg.setText("El formato de archivo es inválido");
            msg.exec();
        }
    }
}

void MainWindow::on_actionGuardar_como_triggered()
{
    std::string directory = QFileDialog::getSaveFileName(this, "Guardar como...", QDir::homePath(), "Imagen (*.bmp)").toStdString().append(".bmp");
    this->tools.BMP.bmpExport(directory, this->imageDimensions[0], this->imageDimensions[1], ui->canvasLabel->getMatrix());
}

void MainWindow::on_action90_triggered()
{

    int width = this->imageDimensions[0], height = this->imageDimensions[1];
    double spinZoomLastValue = ui->zoomSpin->value();
    pixel **rotatedMatrix = this->tools.getRot().rotate90(ui->canvasLabel->getMatrix(), width, height);
    createNewCanvas(height, width);
    delete ui->canvasLabel->getMatrix();
    ui->canvasLabel->setMatrix(rotatedMatrix);
    this->tools.setMatrixPointer(rotatedMatrix);
    updateCanvas();
    on_zoomSpin_valueChanged(spinZoomLastValue + 0.01);
    on_zoomSpin_valueChanged(spinZoomLastValue - 0.01);
}

void MainWindow::on_action90_izquierda_triggered()
{
    int width = this->imageDimensions[0], height = this->imageDimensions[1];
    double spinZoomLastValue = ui->zoomSpin->value();
    pixel **rotatedMatrix = this->tools.getRot().rotate90(ui->canvasLabel->getMatrix(), width, height);
    rotatedMatrix = this->tools.getRot().rotate90(rotatedMatrix, width, height);
    rotatedMatrix = this->tools.getRot().rotate90(rotatedMatrix, width, height);
    createNewCanvas(height, width);
    delete ui->canvasLabel->getMatrix();
    ui->canvasLabel->setMatrix(rotatedMatrix);
    this->tools.setMatrixPointer(rotatedMatrix);
    on_zoomSpin_valueChanged(spinZoomLastValue + 0.01);
    on_zoomSpin_valueChanged(spinZoomLastValue - 0.01);
    //if (spinZoomLastValue != 1.00) {
    //    on_zoomSpin_valueChanged(spinZoomLastValue);
    //}
    updateCanvas();
}

void MainWindow::on_actionFlip_vertical_triggered()
{
    int width = this->imageDimensions[0], height = this->imageDimensions[1];
    pixel **rotatedMatrix = this->tools.getRot().flipVertical(ui->canvasLabel->getMatrix(), width, height);
    delete ui->canvasLabel->getMatrix();
    ui->canvasLabel->setMatrix(rotatedMatrix);
    this->tools.setMatrixPointer(rotatedMatrix);
    updateCanvas();
}

void MainWindow::on_actionFlip_horizontal_triggered()
{
    int width = this->imageDimensions[0];
    int height = this->imageDimensions[1];
    pixel **rotatedMatrix = this->tools.getRot().flipHorizontal(ui->canvasLabel->getMatrix(), width, height);
    delete ui->canvasLabel->getMatrix();
    ui->canvasLabel->setMatrix(rotatedMatrix);
    this->tools.setMatrixPointer(rotatedMatrix);
    updateCanvas();
}

void MainWindow::on_zoomSpin_valueChanged(double arg1)
{
    ui->canvasLabel->setFixedWidth(arg1 * ui->canvasLabel->pixmap().width());
    ui->canvasLabel->setFixedHeight(arg1 * ui->canvasLabel->pixmap().height());
    this->zoom = arg1;
    this->tools.setZoom(arg1);
}

void MainWindow::on_actionEscala_de_Grisis_triggered()
{
    pixel **matrix = ui->canvasLabel->getMatrix();
    uint32_t Color;
    int grey;
    for (int i = 0; i <this->imageDimensions[0];i++){
        for (int j = 0; j<this->imageDimensions[1];j++){
            if(matrix[i][j].getColor() != 16777215){
                this->getpixelRgb(i,j);
                grey = (red+green+blue)/3;
                Color = this->rgbToHex(grey,grey, grey);
                matrix[i][j].setColor(Color);
                this->resetRGB();
            }
        }
    }
    this->updateCanvas();
}

void MainWindow::on_actionNegativo_triggered()
{
    pixel **matrix = ui->canvasLabel->getMatrix();
    uint32_t negative;
    for (int i = 0; i <this->imageDimensions[0];i++){
        for (int j = 0; j<this->imageDimensions[1];j++){
                this->getpixelRgb(i,j);
                negative = this->rgbToHex(255-red,255-green,255-blue);
                matrix[i][j].setColor(negative);
                this->resetRGB();
        }
    }
    this->updateCanvas();
}

void MainWindow::on_actionSepia_triggered()
{
    pixel **matrix = ui->canvasLabel->getMatrix();
    uint32_t Sepia;
    int sepiaR;
    int sepiaG;
    int sepiaB;
    for (int i = 0; i <this->imageDimensions[0];i++){
        for (int j = 0; j<this->imageDimensions[1];j++){
            this->getpixelRgb(i,j);
            sepiaR= (red*0.393)+(green*0.769)+(blue*0.189);
            sepiaG= (red*0.349)+(green*0.686)+(blue*0.168);
            sepiaB= (red*0.272)+(green*0.534)+(blue*0.131);

            if(sepiaR > 255){sepiaR = 255;}
            if(sepiaR < 0){sepiaR = 0;}

            if(sepiaG > 255){sepiaG = 255;}
            if(sepiaG < 0){sepiaG = 0;}

            if(sepiaB > 255){sepiaB = 255;}
            if(sepiaB < 0){sepiaB = 0;}


            Sepia = this->rgbToHex(sepiaR,sepiaG,sepiaB);
            matrix[i][j].setColor(Sepia);
            this->resetRGB();
        }
    }
    this->updateCanvas();
}

void MainWindow::on_actionPastel_triggered()
{
    pixel **matrix = ui->canvasLabel->getMatrix();
    uint32_t Sepia;
    int pastelR;
    int pastelG;
    int pastelB;
    for (int i = 0; i <this->imageDimensions[0];i++){
        for (int j = 0; j<this->imageDimensions[1];j++){
            this->getpixelRgb(i,j);
            pastelR= (red/2) + 127;
            pastelG= (green/2) + 127;
            pastelB= (blue/2) + 127;


            if(pastelR > 255){pastelR = 255;}
            if(pastelR < 0){pastelR = 0;}

            if(pastelG > 255){pastelG = 255;}
            if(pastelG < 0){pastelG = 0;}

            if(pastelB > 255){pastelB = 255;}
            if(pastelB < 0){pastelB = 0;}


            Sepia = this->rgbToHex(pastelR,pastelG,pastelB);
            matrix[i][j].setColor(Sepia);
            this->resetRGB();
        }
    }
    this->updateCanvas();
}

void MainWindow::on_RectangularSelectionButton_clicked()
{
    falseAllTools();
    this->rectangularSelection = true;
    trueAllButtons();
    ui->RectangularSelectionButton->setEnabled(false);


}
