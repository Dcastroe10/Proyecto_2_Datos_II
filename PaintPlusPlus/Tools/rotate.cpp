#include "rotate.h"

rotater::rotater()
{

}

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

pixel **rotater::matrixCreator(int width, int height)
{
    pixel **matrix = new pixel*[width];

    for (int i = 0; i < width; i++) {
        matrix[i] = new pixel[height];
    }
    return matrix;
}
