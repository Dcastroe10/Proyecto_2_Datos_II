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
    pen.drawInCanvas(this->matrixPointer, posx, posy, color);
}

void Tools::drawWithPencil(int start[2], int end[2], uint32_t color, int grosor) {
    pencil.drawALineInCanvas(this->matrixPointer, start, end, color, grosor);
}

void Tools::drawSquare(int *start, int *end, uint32_t color, int grosor){
    square.draw_square_in_canvas(this->matrixPointer,start, end, color, grosor);
}

void Tools::drawCircle(int *start, int *end, uint32_t color, int grosor){
    circle.draw_circle(this->matrixPointer,start, end, color, grosor);
}

void Tools::set_grosor(int num){
    this->grosor = num;
}

int Tools::get_grosor(){
    return grosor;
}
