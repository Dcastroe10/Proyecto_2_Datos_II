#include "colorpicker.h"

colorpicker::colorpicker()
{

}

uint32_t colorpicker::getColorInMatrix(pixel **matrix, int x, int y)
{
    return matrix[x][y].getColor();
}
