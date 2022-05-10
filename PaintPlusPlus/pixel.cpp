#include "pixel.h"

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

int pixel::getId() const
{
    return id;
}

void pixel::setId(int newId)
{
    id = newId;
}
