#include "pen.h"

Pen::Pen()
{

}

/**
 * @brief Pinta los pixeles en el canvas y les agrega el identificador
 * @param canvas    Canvas en el que se desea dibujar
 * @param posx      Posición x del pixel
 * @param posy      posición y del pixel
 * @param color     Color del pixel
 * @param id        identificador
 */
void Pen::drawInCanvas(pixel **canvas, int posx, int posy, uint32_t color,int id)
{
    canvas[posx][posy].setColor(color);
    canvas[posx][posy].setId(id);
}
