#include "rotate.h"

rotater::rotater()
{

}

/**
 * @brief Rota el canvass 90°
 * @param oldMatrix     Matriz con los pixeles que se desean voltear
 * @param oldWidth      Ancho de la matriz inicial
 * @param oldHeight     Alto de la matriz inicial
 * @return La nueva matriz ya rotada 90°
 */
pixel **rotater::rotate90(pixel **oldMatrix, int oldWidth, int oldHeight)
{
    pixel **newMatrix = matrixCreator(oldHeight, oldWidth);

    int imgX = 0, imgY = oldWidth;

    for (int y = 0; y < oldHeight; y++) {
        for (int x = 0; x < oldWidth; x++) {
            newMatrix[imgX][imgY] = oldMatrix[x][y];
            imgY--;
        }
        imgY = oldWidth;
        imgX++;
    }
    return newMatrix;
}

/**
 * @brief Realiza un flip vertical al canvas
 * @param oldMatrix     Matriz con los pixeles que se desean voltear
 * @param oldWidth      Ancho de la matriz inicial
 * @param oldHeight     Alto de la matriz inicial
 * @return la nueva matriz con el flip vertical ya realizado
 */
pixel **rotater::flipVertical(pixel **oldMatrix, int oldWidth, int oldHeight)
{
    pixel **newMatrix = matrixCreator(oldWidth, oldHeight);

    for (int y = 0; y < oldHeight; y++) {
        for (int x = 0; x < oldWidth; x++) {
            newMatrix[x][oldHeight - y] = oldMatrix[x][y];
        }
    }
    return newMatrix;
}

/**
 * @brief Realiza un flip horizontal al canvas
 * @param oldMatrix     Matriz con los pixeles que se desean voltear
 * @param oldWidth      Ancho de la matriz inicial
 * @param oldHeight     Alto de la matriz inicial
 * @return la nueva matriz con el flip horizontal ya realizado
 */
pixel **rotater::flipHorizontal(pixel **oldMatrix, int oldWidth, int oldHeight)
{
    pixel **newMatrix = matrixCreator(oldWidth, oldHeight);

    for (int y = 0; y < oldHeight; y++) {
        for (int x = 0; x < oldWidth; x++) {
            newMatrix[oldWidth - x - 1][y] = oldMatrix[x][y];
        }
    }

    return newMatrix;
}

/**
 * @brief crea una matriz con el ancho y algo deseados
 * @param width     Ancho para la nueva matriz
 * @param height    Alto para la nueva matriz
 * @return La nueva matriz vacía
 */
pixel **rotater::matrixCreator(int width, int height)
{
    pixel **matrix = new pixel*[width];

    for (int i = 0; i < width; i++) {
        matrix[i] = new pixel[height];
    }
    return matrix;
}
