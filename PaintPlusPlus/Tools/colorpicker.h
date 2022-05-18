#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <iostream>
#include <pixel.h>


class colorpicker
{
public:
    colorpicker();
    uint32_t getColorInMatrix(pixel** matrix, int x, int y);
};

#endif // COLORPICKER_H
