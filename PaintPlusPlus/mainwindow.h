#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CanvasDialog/createcanvasdialog.h"
#include <QLabel>
#include "tools.h"

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

    void setPixelInCanvas(int x, int y);
    void trueAllButtons();
    void drawALine(int start[], int end[]);
    void updateCanvas();
private slots:
    void on_actionNuevo_triggered();

    // Para crear lienzo con datos del dialogo.
    void receiveCanvas(int& x, int& y);

    // Para pintar el canvas con el mouse.
    void mouseIsPressed(int& x, int& y);
    void mouseIsReleased(int& x, int& y);
    void mouseMove(int& x, int& y);

    void on_penButton_clicked();

    void falseAllTools();



    void on_pencilButton_clicked();

private:
    Ui::MainWindow *ui;
    createCanvasDialog *createcanvasDialog;
    Tools tools;

    bool penF = false;
    bool pencilF = false;

    int firstClick[2] = {0, 0};
    int clickReleased[2] = {0, 0};

    int imageDimensions[2] = {0, 0};

    void createNewCanvas(int x, int y);
    void fillCanvas(int r, int g, int b, int x, int y);

    bool mousePressedInCanvas = false;

};
#endif // MAINWINDOW_H
