#include "colorpicker.h"

colorpicker::colorpicker()
{

}

/**
 * @brief Obtiene el color del pixel presionado
 * @param matrix    Matriz con los pixeles del canvas
 * @param x         posición x del pixel
 * @param y         posición y del pixel
 * @return color del pixel presionado
 */
uint32_t colorpicker::getColorInMatrix(pixel **matrix, int x, int y)
{
    return matrix[x][y].getColor();
}
