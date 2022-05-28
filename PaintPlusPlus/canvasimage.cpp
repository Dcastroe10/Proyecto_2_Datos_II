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
 * @brief Crea una nueva matriz de pixeles.
 * @param x ancho
 * @param y largo
 */
void canvasImage::createNewMatrix(int x, int y)
{
    matrix = new pixel*[x];

    for (int i = 0; i < y; i++) {
        matrix[i] = new pixel[y];
    }
}

/**
 * @brief Evento del movimiento del mouse sobre el canvas.
 * @param event evento del mouse.
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
 * @brief Evento del click del mouse sobre el canvas.
 * @param event evento del mouse
 */
void canvasImage::mousePressEvent(QMouseEvent *event)
{
     qDebug() << x << y << "clicked";
     emit sendMouseClicked(this->x, this->y);
}

/**
 * @brief Evento cuando el click se deja de presionar.
 * @param event evento del mouse.
 */
void canvasImage::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << x << y << "released";
    emit sendMouseReleased(this->x, this->y);
}

/**
 * @brief Colocar una nueva matriz.
 * @param newMatrix matriz
 */
void canvasImage::setMatrix(pixel **newMatrix)
{
    matrix = newMatrix;
}

/**
 * @brief Obtener la matriz
 * @return matriz
 */
pixel **canvasImage::getMatrix() const
{
    return matrix;
}







