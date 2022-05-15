#include "tools.h"

void Tools::setMatrixPointer(pixel **newMatrixPointer)
{
    matrixPointer = newMatrixPointer;
}

Tools::Tools()
{

}

Pen Tools::getPen()
{
    return pen;
}

void Tools::drawWithPen(int posx, int posy, uint32_t color)
{
    pen.drawInCanvas(matrixPointer, posx, posy, color);
}

void Tools::drawWithPencil(int start[2], int end[2], uint32_t color) {
    //pencil.drawALineInCanvas(this->matrixPointer, start, end, color);
}
