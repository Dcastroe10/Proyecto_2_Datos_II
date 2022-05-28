#include "canvasimage.h"
#include <QtDebug>

canvasImage::canvasImage(QWidget* parent) :
    QLabel(parent)
{

}

canvasImage::~canvasImage()
{

}

/**
 * @brief canvasImage::createNewMatrix
 * @param x
 * @param y
 */
void canvasImage::createNewMatrix(int x, int y)
{
    matrix = new pixel*[x];

    for (int i = 0; i < y; i++) {
        matrix[i] = new pixel[y];
    }
}

/**
 * @brief canvasImage::mouseMoveEvent
 * @param event
 */
void canvasImage::mouseMoveEvent(QMouseEvent *event)
{
    this->x = event->pos().x();
    this->y = event->pos().y();

    if (this->x <= this->size().width() && this->y <= this->size().height()) {
        if (this->x >= 0 && this->y >= 0) {
            emit sendMousePosition(this->x, this->y);
        }
    }
}

/**
 * @brief canvasImage::mousePressEvent
 * @param event
 */
void canvasImage::mousePressEvent(QMouseEvent *event)
{
     qDebug() << x << y << "clicked";
     emit sendMouseClicked(this->x, this->y);
}

/**
 * @brief canvasImage::mouseReleaseEvent
 * @param event
 */
void canvasImage::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << x << y << "released";
    emit sendMouseReleased(this->x, this->y);
}

/**
 * @brief canvasImage::setMatrix
 * @param newMatrix
 */
void canvasImage::setMatrix(pixel **newMatrix)
{
    matrix = newMatrix;
}

/**
 * @brief canvasImage::getMatrix
 * @return
 */
pixel **canvasImage::getMatrix() const
{
    return matrix;
}







