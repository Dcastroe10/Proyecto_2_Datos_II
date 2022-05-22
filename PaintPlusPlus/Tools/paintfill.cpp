#include "paintfill.h"

paintfill::paintfill()
{

}

void paintfill::doPaintFill(int width, int height, int color, pixel **matrix, int posX, int posY, int id)
{
    this->BFS.initBFS(posX,posY,matrix);
    this->BFS.BFS(width, height, color, matrix, posX, posY,id);
}
