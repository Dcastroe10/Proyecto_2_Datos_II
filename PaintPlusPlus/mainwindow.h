#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CanvasDialog/createcanvasdialog.h"
#include <QLabel>
#include "tools.h"
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    uint32_t rgbToHex(int r, int g, int b);

    void setPixelInCanvas(int x, int y, int id);
    void trueAllButtons();
    void drawALine(int start[], int end[]);
    void drawSquare(int start[], int end[]);
    void drawCircle(int start[], int end[]);
    void updateCanvas();
    void usePaintFill(int posX, int posY);
    void delete_figure(int id);
    int HexToRGB(uint32_t hexa);
    bool isValid(char valid);
    void getpixelRgb(int X, int Y);
    void resetRGB();
private slots:
    void on_actionNuevo_triggered();

    // Para crear lienzo con datos del dialogo.
    void receiveCanvas(int& x, int& y);

    // Para pintar el canvas con el mouse.
    void mouseIsPressed(int& x, int& y);
    void mouseIsReleased(int& x, int& y);
    void mouseMove(int& x, int& y);


    void falseAllTools();

    void on_penButton_clicked();

    void on_pencilButton_clicked();



    void on_pushButton_3_clicked();

    void on_Color_button_clicked();


    void on_squareButton_clicked();

    void on_circle_Button_clicked();

    void on_colorPickerButton_clicked();

    void on_paintFillButton_clicked();

    void on_eraserButton_clicked();

    void on_figureeraserButton_clicked();

    void on_actionAbrir_triggered();

    void on_actionGuardar_como_triggered();

    void on_action90_triggered();

    void on_action90_izquierda_triggered();

    void on_actionFlip_vertical_triggered();

    void on_actionFlip_horizontal_triggered();

    void on_undoButton_clicked();

    void on_redolistButton_clicked();

    void on_zoomSpin_valueChanged(double arg1);

    void on_actionEscala_de_Grisis_triggered();

    void on_actionNegativo_triggered();

    void on_actionSepia_triggered();

    void on_actionPastel_triggered();

    void on_RectangularSelectionButton_clicked();

    void on_MoveFigureButton_clicked();

private:
    Ui::MainWindow *ui;
    createCanvasDialog *createcanvasDialog;
    Tools tools;

    bool penF = false;
    bool pencilF = false;
    bool squareF = false;
    bool circleF = false;
    bool colorPickerF= false;
    bool paintFillF = false;
    bool freeEraserF = false;
    bool figureEraserF= false;
    bool rectangularSelection = false;
    bool magiSelection = false;
    bool freeformSelection = false;
    bool movefigureF = false;

    int firstClick[2] = {0, 0};
    int clickReleased[2] = {0, 0};

    double zoom = 1.0;

    int red = -1;
    int green = -1;
    int blue = -1;

    int imageDimensions[2] = {0, 0};

    int id_figuras = 0;
    int id_pen = 0;

    void createNewCanvas(int x, int y);
    void fillCanvas(int r, int g, int b, int x, int y);

    bool mousePressedInCanvas = false;

    uint32_t color;
    uint32_t last_color; //for the eraser

};
#endif // MAINWINDOW_H
