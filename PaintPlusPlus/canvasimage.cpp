#include "canvasimage.h"
#include <QtDebug>

canvasImage::canvasImage(QWidget* parent) :
    QLabel(parent)
{

}

canvasImage::~canvasImage()
{

}

void canvasImage::createNewMatrix(int x, int y)
{
    matrix = new pixel*[x];

    for (int i = 0; i < 5; i++) {
        matrix[i] = new pixel[y];
    }
}

pixel **canvasImage::getMatrix() const
{
    return matrix;
}

void canvasImage::mouseMoveEvent(QMouseEvent *event)
{
    this->x = event->pos().x();
    this->y = event->pos().y();

    if (this->x <= this->size().width() && this->y <= this->size().height()) {
        if (this->x > 0 && this->y > 0) {
            emit sendMousePosition(this->x, this->y);
            qDebug() << this->x << this->y;
        }
    }
}

void canvasImage::mousePressEvent(QMouseEvent *event)
{
     qDebug() << x << y << "clicked";
     emit sendMouseClicked(this->x, this->y);
}

void canvasImage::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << x << y << "released";
    emit sendMouseReleased();
}







