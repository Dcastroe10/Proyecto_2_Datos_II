#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->canvasLabel, SIGNAL(sendMousePosition(int&, int&)), this, SLOT(mouseMove(int&, int&)));
    connect(ui->canvasLabel, SIGNAL(sendMouseClicked(int&, int&)), this, SLOT(mouseIsPressed(int&, int&)));
    connect(ui->canvasLabel, SIGNAL(sendMouseReleased()), this, SLOT(mouseIsReleased()));
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
    setPixelInCanvas(x, y);
}

void MainWindow::mouseIsReleased()
{
    this->mousePressedInCanvas = false;
}

void MainWindow::mouseMove(int &x, int &y)
{
    setPixelInCanvas(x, y);
}

void MainWindow::setPixelInCanvas(int x, int y) {
    if (this->mousePressedInCanvas) {
        QImage canvas = ui->canvasLabel->pixmap()->toImage();
        uint32_t color1 = rgbToHex(0, 0, 0);

        canvas.setPixel(x, y, color1);

        ui->canvasLabel->setPixmap(QPixmap::fromImage(canvas));
    }
}


void MainWindow::on_actionNuevo_triggered()
{
    createcanvasDialog = new createCanvasDialog();
    connect(createcanvasDialog, SIGNAL(accept(int&, int&)), this, SLOT(receiveCanvas(int&, int&)));
    createcanvasDialog->setModal(true);
    createcanvasDialog->exec();
}

