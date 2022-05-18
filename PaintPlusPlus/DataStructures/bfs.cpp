#include "bfs.h"

bfs::bfs()
{

}

int** bfs::neighbours(int width, int height, u_int32_t colorSelected, pixel** matrix, int posX, int posY) {
    int** neighbours = new int*[4];
    for (int i = 0; i < 4; i++) {
        neighbours[i] = new int[2];
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            neighbours[i][j] = -1;
        }

    }

    int indexX = 0;

    if (!outOfBounds(width, height, posX - 1, posY) && matrix[posX - 1][posY].getColor() == colorSelected) {
        neighbours[indexX][0] = posX - 1;
        neighbours[indexX][1] = posY;
        indexX++;
    }
    if (!outOfBounds(width, height, posX + 1, posY) && matrix[posX + 1][posY].getColor() == colorSelected) {
        neighbours[indexX][0] = posX + 1;
        neighbours[indexX][1] = posY;
        indexX++;
    }
    if (!outOfBounds(width, height, posX, posY - 1) && matrix[posX][posY - 1].getColor() == colorSelected) {
        neighbours[indexX][0] = posX;
        neighbours[indexX][1] = posY - 1;
        indexX++;
    }
    if (!outOfBounds(width, height, posX, posY + 1) && matrix[posX][posY + 1].getColor() == colorSelected) {
        neighbours[indexX][0] = posX;
        neighbours[indexX][1] = posY + 1;
        indexX++;
    }

    return neighbours;
}

bool bfs::outOfBounds(int width, int height, int posX, int posY) {
    if (posX < 0 || posX >= width || posY < 0 || posY >= height) {
        return true;
    } else {
        return false;
    }
}

void bfs::initBFS(int width, int height) {
    this->queueX = new queue(width);
    this->queueY = new queue(height);

    visited = new bool*[width];

    for (int i = 0; i < height; i++) {
        visited[i] = new bool[height];
    }
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            visited[i][j] = false;
        }
    }
}

void bfs::doBFS(int width, int height, u_int32_t color, pixel** matrix, int posX, int posY) {
    u_int32_t colorSelected = matrix[posX][posY].getColor();
    initBFS(width, height);
    this->queueX->enQueue(posX);
    this->queueY->enQueue(posY);

    int itera = 0;

    while (!this->queueX->isEmpty()) {

        posX = this->queueX->deQueue();
        posY = this->queueY->deQueue();

        if (!visited[posX][posY]) {
            matrix[posX][posY].setColor(color);
            visited[posX][posY] = true;
        }

        int** neighbourss = neighbours(width, height, colorSelected, matrix, posX, posY);
        int currentX;
        int currentY;
        for(int x = 0; x < 4; x++) {
            currentX = neighbourss[x][0];
            currentY = neighbourss[x][1];

            //qDebug() << currentX << currentY;

            if (currentX != -1) {
                if (!visited[currentX][currentY]) {
                    this->queueX->enQueue(currentX);
                    this->queueY->enQueue(currentY);

                }
            }
        }
        delete[] neighbourss;
    }
}
