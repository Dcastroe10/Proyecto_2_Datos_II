#include "canvasimage.h"

canvasImage::canvasImage(QWidget* parent) :
    QLabel(parent)
{

}

canvasImage::~canvasImage()
{

}

void canvasImage::mouseMoveEvent(QMouseEvent *event)
{
    QPoint mousePos = event->pos();

    if (mousePos.x() <= this->size().width() && mousePos.y() <= this->size().height()) {
        emit sendMousePosition(mousePos);
        qDebug() << mousePos.x() << mousePos.y();
    }
}


