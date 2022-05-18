#include "paintfill.h"

paintfill::paintfill()
{

}

void paintfill::doPaintFill(int width, int height, int color, pixel **matrix, int posX, int posY)
{
    this->BFS.doBFS(width, height, color, matrix, posX, posY);
}
