#include "pixel.h"
#include <QtDebug>

pixel::pixel()
{

}

uint32_t pixel::getColor() const
{
    return color;
}

void pixel::setColor(uint32_t newColor)
{
    color = newColor;
}

void pixel::setFigura(int figura)
{
    this->figura = figura;
}

int pixel::getFigura()
{
    return this->figura;
}

int pixel::getId() const
{
    return id;
}

void pixel::setId(int newId)
{
    id = newId;
}
