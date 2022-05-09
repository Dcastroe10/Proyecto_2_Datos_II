#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    ui->gridLayout->setGeometry(QRect(x, y, x, y));
    fillCanvas(255, 255, 255, x, y, ui->canvasLabel);
}

void MainWindow::fillCanvas(int r, int g, int b, int x, int y, QLabel *label)
{
    QImage *image = new QImage(x, y, QImage::Format_RGB32);

    for (int xi = 0; xi < x; xi++) {
        for (int yi = 0; yi < y; yi++) {
            image->setPixel(xi, yi, qRgb(r, g, b));
        }
    }

    label->setPixmap(QPixmap::fromImage(*image));
    delete image;
}

void MainWindow::on_actionNuevo_triggered()
{
    createcanvasDialog = new createCanvasDialog();
    connect(createcanvasDialog, SIGNAL(accept(int&, int&)), this, SLOT(receiveCanvas(int&, int&)));
    createcanvasDialog->setModal(true);
    createcanvasDialog->exec();
}

