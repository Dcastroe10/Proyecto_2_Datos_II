#include "pen.h"

Pen::Pen()
{

}

void Pen::drawInCanvas(pixel **canvas, int posx, int posy, uint32_t color,int id)
{
    canvas[posx][posy].setColor(color);
    canvas[posx][posy].setId(id);
}
