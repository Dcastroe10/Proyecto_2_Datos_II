#include "paintfill.h"

paintfill::paintfill()
{

}

/**
 * @brief Pinta todos los pixeles del mismo color al pixel presionado por medio del bfs
 * @param width     ancho del canvas
 * @param height    altura del canvas
 * @param color     color deseado
 * @param matrix    matriz con los pixeles en el canvas
 * @param posX      posición x del pixel
 * @param posY      posición y del pixel
 * @param id        identificador de la figura
 */
void paintfill::doPaintFill(int width, int height, int color, pixel **matrix, int posX, int posY, int id)
{
    this->BFS.initBFS(posX,posY,matrix);
    this->BFS.BFS(width, height, color, matrix, posX, posY,id);
}
