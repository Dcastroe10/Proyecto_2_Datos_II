#include "bfs.h"
#include <QDebug>

bool bfs::outOfBounds(int width, int height, int posX, int posY) {
    if (posX < 0 || posX >= width || posY < 0 || posY >= height) {
        return true;
    } else {
        return false;
    }
}


void bfs::initBFS(int posX, int posY, pixel **matrix) {
    this->queueX = new queue();
    this->queueY = new queue();
    this->queueX->enQueue(posX);
    this->queueY->enQueue(posY);
    colorCheck =  matrix[posX][posY].getColor();
}

void bfs::BFS(int width, int height, uint32_t color, pixel **matrix, int posX, int posY){
    if(color == colorCheck){
        qDebug()<<"NO HAY QUE PINTAR";
    }else{
    while(!this->queueX->isEmpty()){
        matrix[posX][posY].setColor(color);
        if(!this->outOfBounds(width, height,posX+1,posY) && matrix[posX +1][posY].getColor()==colorCheck){
            this->queueX->enQueue(posX+1);
            this->queueY->enQueue(posY);
            matrix[posX+1][posY].setColor(color);
        }

        if(!this->outOfBounds(width, height,posX-1,posY) && matrix[posX -1][posY].getColor()==colorCheck){
            this->queueX->enQueue(posX-1);
            this->queueY->enQueue(posY);
            matrix[posX][posY-1].setColor(color);
        }

        if(!this->outOfBounds(width, height,posX,posY+1) && matrix[posX][posY+1].getColor()==colorCheck){
            this->queueX->enQueue(posX);
            this->queueY->enQueue(posY+1);
            matrix[posX][posY+1].setColor(color);
        }

        if(!this->outOfBounds(width, height,posX,posY-1) && matrix[posX][posY-1].getColor()==colorCheck){
            this->queueX->enQueue(posX);
            this->queueY->enQueue(posY-1);
            matrix[posX][posY-1].setColor(color);
        }

        posX = this->queueX->deQueue();
        posY = this->queueY->deQueue();
    }
}
}
