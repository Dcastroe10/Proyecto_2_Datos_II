#include "tools.h"

void Tools::setMatrixPointer(pixel **newMatrixPointer)
{
    matrixPointer = newMatrixPointer;
}

rotater Tools::getRot()
{
    return rot;
}

Tools::Tools()
{

}

Pen Tools::getPen()
{
    return pen;
}

void Tools::drawWithPen(int posx, int posy, uint32_t color, int id)
{
    pen.drawInCanvas(this->matrixPointer, posx, posy, color, id);
}

void Tools::drawWithPencil(int start[2], int end[2], uint32_t color, int grosor, int id) {
    pencil.drawALineInCanvas(this->matrixPointer, start, end, color, grosor, id);
}

void Tools::drawSquare(int *start, int *end, uint32_t color, int grosor, int id){
    square.draw_square_in_canvas(this->matrixPointer,start, end, color, grosor, id);
}

void Tools::drawCircle(int *start, int *end, uint32_t color, int grosor, int id){
    Circle.draw_circle(this->matrixPointer,start, end, color, grosor, id);
}

void Tools::drawWithPaintFiller(int width, int height, uint32_t color, int posX, int posY)
{
    PaintFill.doPaintFill(width, height, color, this->matrixPointer, posX, posY);
}

uint32_t Tools::getColorColorPicker(int x, int y) {
    return this->ColorPicker.getColorInMatrix(this->matrixPointer, x, y);
}

void Tools::set_grosor(int num){
    this->grosor = num;
}

int Tools::get_grosor(){
    return grosor;
}
