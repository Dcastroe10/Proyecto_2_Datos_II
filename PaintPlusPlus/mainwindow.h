#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CanvasDialog/createcanvasdialog.h"
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNuevo_triggered();

    // Para crear lienzo
    void receiveCanvas(int& x, int& y);

private:
    Ui::MainWindow *ui;
    createCanvasDialog *createcanvasDialog;

    void createNewCanvas(int x, int y);
    void fillCanvas(int r, int g, int b, int x, int y, QLabel *label);

    int mouseDiffX;
    int mouseDiffY;
};
#endif // MAINWINDOW_H
