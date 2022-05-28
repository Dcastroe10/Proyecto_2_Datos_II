#include "bfs.h"
#include <QDebug>
/**
 * @brief Verifica que un pixel esté dentro de los límites deseados de ancho y alto del canvas
 * @param width     ancho del canvas
 * @param height    altura del canvas
 * @param posX      posición x del pixel
 * @param posY      posición y del pixel
 * @return Boolean indicando si el pixel está dentro del canvas
 */
bool bfs::outOfBounds(int width, int height, int posX, int posY) {
    if (posX < 0 || posX >= width || posY < 0 || posY >= height) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Crea la queue inicial y obtiene el color de referencia para el funcionamiento del BFS
 * @param posX      posición x del pixel
 * @param posY      posición y del pixel
 * @param matrix    matriz de los pixeles
 */
void bfs::initBFS(int posX, int posY, pixel **matrix) {
    this->queueX = new queue();
    this->queueY = new queue();
    this->queueX->enQueue(posX);
    this->queueY->enQueue(posY);
    colorCheck =  matrix[posX][posY].getColor();
}


/**
 * @brief Realiza el BFS visitando los pixeles vecinos del pixel dado y cambia el color de
 * los vecinos que cumplen las condiciones de posición y color inicial
 * @param width     ancho del canvas
 * @param height    alto del canvas
 * @param color     color al que se desea pintar con el paintfill
 * @param matrix    matriz que contiene los pixeles dentro del canvas
 * @param posX      posición x del pixel
 * @param posY      posición y del pixel
 * @param id        identificador del pixel
 *
 */
void bfs::BFS(int width, int height, uint32_t color, pixel **matrix, int posX, int posY, int id){
    if(color == colorCheck){
        qDebug()<<"NO HAY QUE PINTAR";
    }else{
    while(!this->queueX->isEmpty()){
        matrix[posX][posY].setColor(color);
        matrix[posX][posY].setId(id);
        if(!this->outOfBounds(width, height,posX+1,posY) && matrix[posX +1][posY].getColor()==colorCheck){
            this->queueX->enQueue(posX+1);
            this->queueY->enQueue(posY);
            matrix[posX+1][posY].setColor(color);
            matrix[posX][posY].setId(id);
        }

        if(!this->outOfBounds(width, height,posX-1,posY) && matrix[posX -1][posY].getColor()==colorCheck){
            this->queueX->enQueue(posX-1);
            this->queueY->enQueue(posY);
            matrix[posX][posY-1].setColor(color);
            matrix[posX][posY].setId(id);
        }

        if(!this->outOfBounds(width, height,posX,posY+1) && matrix[posX][posY+1].getColor()==colorCheck){
            this->queueX->enQueue(posX);
            this->queueY->enQueue(posY+1);
            matrix[posX][posY+1].setColor(color);
            matrix[posX][posY].setId(id);
        }

        if(!this->outOfBounds(width, height,posX,posY-1) && matrix[posX][posY-1].getColor()==colorCheck){
            this->queueX->enQueue(posX);
            this->queueY->enQueue(posY-1);
            matrix[posX][posY-1].setColor(color);
            matrix[posX][posY].setId(id);
        }

        posX = this->queueX->deQueue();
        posY = this->queueY->deQueue();
    }
}
}
