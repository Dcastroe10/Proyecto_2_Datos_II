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

void MainWindow::receiveCanvas(int& x, int& y) {
    qDebug() << x << y;
    createNewCanvas(x, y);
}


void MainWindow::createNewCanvas(int x, int y)
{
    ui->canvasLabel->setEnabled(true);
    ui->canvasLabel->createNewMatrix(x, y);
    this->tools.setMatrixPointer(ui->canvasLabel->getMatrix());

    this->imageDimensions[0] = x;
    this->imageDimensions[1] = y;

    ui->gridLayout->setGeometry(QRect(x, y, x, y));
    fillCanvas(255, 255, 255, x, y);
}


uint32_t MainWindow::rgbToHex(int r, int g, int b) {
    return ((r & 0xFF) << 16) + ((g & 0xFF) << 8) + ((b & 0xFF));
}

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

void MainWindow::mouseIsReleased(int& x, int& y)
{
    pixel **matrix = ui->canvasLabel->getMatrix();
    this->mousePressedInCanvas = false;
    this->color = this->last_color;
    this->clickReleased[0] = x;
    this->clickReleased[1] = y;

    //this->id_figuras++;
    tools.add_toUndoList(-1,-1,this->id_pen,-1,-1,-1,-1);//CHEEEECK ESTOOO puede ser lo que sube extra //ES PARA AGREGAR AL UNDO LAS LINEAS DEL PEN pero
    this->id_pen = this->id_figuras;                //con las figuras agrega otros ids entonces hay que tocar
    this->id_figuras++;                             //varias (2) veces el botón de undo

    if (this->pencilF) {
        drawALine(this->firstClick, this->clickReleased);
    } else if (this->squareF){
        drawSquare(this->firstClick, this->clickReleased);
    } else if(this->circleF){
        drawCircle(this->firstClick, this->clickReleased);
    } else if (this->colorPickerF){
        this->color = tools.getColorColorPicker(x, y);
        this->last_color = this->color;
        on_penButton_clicked();
    } else if (this->paintFillF) {
        usePaintFill(x, y);
    }else if(this->figureEraserF){
        this->delete_figure(matrix[x][y].getId());
    }

}

void MainWindow::mouseMove(int &x, int &y)
{
    std::string location = std::to_string(x) + ", " + std::to_string(y);
    ui->mouseLocationLabel->setText(QString::fromStdString(location));

    setPixelInCanvas(x, y, this->id_pen);

}

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

void MainWindow::usePaintFill(int posX, int posY) {
    tools.drawWithPaintFiller(this->imageDimensions[0], this->imageDimensions[1], this->color, posX, posY,this->id_figuras);
    this->id_figuras++;
    updateCanvas();
}

void MainWindow::drawALine(int start[], int end[]) {
    tools.drawWithPencil(start, end, this->color,ui->spinBox->value(), this->id_figuras);
    this->id_figuras++;
    this->id_pen = this->id_figuras;
    updateCanvas();
}

void MainWindow::drawSquare(int *start, int *end){
    tools.drawSquare(start, end, this->color,ui->spinBox->value(),this->id_figuras);
    this->id_figuras++;
    this->id_pen = this->id_figuras;
    updateCanvas();
}

void MainWindow::drawCircle(int *start, int *end){
    tools.drawCircle(start, end, this->color,ui->spinBox->value(), this->id_figuras);
    this->id_figuras++;
    this->id_pen = this->id_figuras;
    updateCanvas();
}

void MainWindow::setPixelInCanvas(int x, int y, int id) {
    if ((this->penF || this->freeEraserF)&& this->mousePressedInCanvas) {
        QImage canvas = ui->canvasLabel->pixmap().toImage();
        int grosor = ui->spinBox->value();

        for (int i = -grosor; i < grosor; i++){
            for(int j = -grosor; j < grosor; j++){
                 canvas.setPixel(x + i , y +j, this->color);
                 tools.drawWithPen(x + i, y + j, this->color, id);
            }

        }
        ui->canvasLabel->setPixmap(QPixmap::fromImage(canvas));
    }
}

void MainWindow::delete_figure(int id){
    pixel **matrix = ui->canvasLabel->getMatrix();
    int check = id;
    if (check == -1){
        qDebug()<<"NO ES FIGURA";
    }else{
        for (int i = 0; i < imageDimensions[0]; i++){
            for(int j = 0; j < imageDimensions[1];j++){
                if(matrix[i][j].getId() == check){
                    matrix[i][j].setColor(this->rgbToHex(255,255,255));//matrix[imageDimensions[0]][imageDimensions[1]].getColor());
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
}

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
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            qDebug() << this->ui->canvasLabel->getMatrix()[i][j].getColor();
        }
    }
    this->updateCanvas();
    //print the colors on the matrix
    /*
    pixel **matrix = ui->canvasLabel->getMatrix();
    for (int i = 0;i<500; i++){
        for (int j= 0; j<500;j++){
            qDebug()<<matrix[i][j].getId();
        }
    }
    */

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
                              tools.getUndoFigura(),tools.getGrosorUndo());

        this->delete_figure(tools.getUndo());
        tools.deleteUndo();
    }else{
        this->delete_figure(tools.getUndo());
        qDebug()<<"NO MORE TO UNDO";
    }

}



void MainWindow::on_redolistButton_clicked()
{
    if(tools.getRedoSize() != 0){
        qDebug()<<tools.getRedo()<< "EL REDOOOO";
        if(tools.getRedoFigura() == 2){
            qDebug()<<"EL MEJOR DÍA DE MI VIDAAAA";
            int *start = new int[2];
            int *end = new int[2];
            start[0] = tools.getStartX_RedoList();
            start[1] = tools.getStartY_RedoList();
            end[0] = tools.getEndX_RedoList();
            end[1] = tools.getEndY_RedoList();
            tools.drawSquare(start,end, this->rgbToHex(216,235,52), tools.getGrosorRedo(),tools.getRedo());
            this->updateCanvas();
        }
        tools.deleteRedo();
    }else{
        //VER QUE inventarse aquí JJAJAJAJ

    }
}


void MainWindow::on_actionAbrir_triggered()
{
    std::string file = QFileDialog::getOpenFileName(this, "Escoge un archivo", QDir::homePath()).toStdString();
    uint32_t** image = tools.BMP.convertToUint32(tools.BMP.readBMP(file));
    //tools.BMP.readBMP(file);
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
}


void MainWindow::on_actionGuardar_como_triggered()
{
    //bool ready;
    //std::string fileName = QInputDialog::getText(this, "Guardar como...", "Nombre:", QLineEdit::Normal, "", &ready).toStdString();
    //fileName.append(".bmp");
    std::string directory = QFileDialog::getSaveFileName(this, "Guardar como...", QDir::homePath(), "Imagen (*.bmp)").toStdString().append(".bmp");
    qDebug() << directory.c_str();
    this->tools.BMP.bmpExport(directory, this->imageDimensions[0], this->imageDimensions[1], ui->canvasLabel->getMatrix());
}


void MainWindow::on_action90_triggered()
{
    int width = this->imageDimensions[0], height = this->imageDimensions[1];
    pixel **rotatedMatrix = this->tools.getRot().rotate90(ui->canvasLabel->getMatrix(), width, height);
    createNewCanvas(height, width);
    delete[] ui->canvasLabel->getMatrix();
    ui->canvasLabel->setMatrix(rotatedMatrix);
    updateCanvas();
}


void MainWindow::on_action90_izquierda_triggered()
{
    int width = this->imageDimensions[0], height = this->imageDimensions[1];
    pixel **rotatedMatrix = this->tools.getRot().rotate90(ui->canvasLabel->getMatrix(), width, height);
    rotatedMatrix = this->tools.getRot().rotate90(rotatedMatrix, width, height);
    rotatedMatrix = this->tools.getRot().rotate90(rotatedMatrix, width, height);
    createNewCanvas(height, width);
    delete[] ui->canvasLabel->getMatrix();
    ui->canvasLabel->setMatrix(rotatedMatrix);
    updateCanvas();
}


void MainWindow::on_actionFlip_vertical_triggered()
{
    int width = this->imageDimensions[0], height = this->imageDimensions[1];
    pixel **rotatedMatrix = this->tools.getRot().flipVertical(ui->canvasLabel->getMatrix(), width, height);
    //createNewCanvas(height, width);
    delete[] ui->canvasLabel->getMatrix();
    ui->canvasLabel->setMatrix(rotatedMatrix);
    updateCanvas();
}


void MainWindow::on_actionFlip_horizontal_triggered()
{
    int width = this->imageDimensions[0], height = this->imageDimensions[1];
    pixel **rotatedMatrix = this->tools.getRot().flipHorizontal(ui->canvasLabel->getMatrix(), width, height);
    //createNewCanvas(height, width);
    delete[] ui->canvasLabel->getMatrix();
    ui->canvasLabel->setMatrix(rotatedMatrix);
    updateCanvas();
}




