#include "pencil.h"

Pencil::Pencil()
{

}

float Pencil::mResult(int start[2], int end[2]) {
    float xif = start[0];
    float xff = end[0];
    float yif = start[1];
    float yff = end[1];
    float m = (yff - yif) / (xff - xif);
    //printf("%f ", m);
    return m;
}

float Pencil::bResult(int x, int y, float m) {
    float xf = x;
    float yf = y;
    float mf = m;

    float b = yf - (mf * xf);
    //printf("b: %f ", b);
    return b;
}

bool Pencil::outOfBounds(int width, int height, int posX, int posY) {
    if (posX < 0 || posX >= width || posY < 0 || posY >= height) {
        return true;
    } else {
        return false;
    }
}


void Pencil::drawALineInCanvas(pixel **canvas, int start[2], int end[2], uint32_t color, int grosor, int id, double zoom,int width, int height) {
    float m = mResult(start, end);
    float b = -bResult(start[0], start[1], m);
    float y = 0;

    int xi = 0;
    int yi = 0;

    float startX = start[0];
    float endX = end[0];

    //while(star)

    if (start[0] > end[0]) {
        while(startX > endX) {
            y = (m * startX) - b;
            xi = int(startX);
            yi = int(y);
            //qDebug() << "line >";
            for (int i = -grosor; i < grosor; i++){
                for(int j = -grosor; j < grosor; j++){
                    if(!this->outOfBounds(width,height,i,j)){
                        canvas[(xi + i) / (int)zoom][(yi + j) / (int)zoom].setColor(color);
                        canvas[(xi + i) / (int)zoom][(yi + j) / (int)zoom].setId(id);
                    }

                }

            }

            startX -= 0.09;
        }
    } else {
        while(startX < endX) {
            y = (m * startX) - b;
            xi = int(startX);
            yi = int(y);
            //qDebug() << "line <";
            for (int i = -grosor; i < grosor; i++){
                for(int j = -grosor; j < grosor; j++){
                    if(!this->outOfBounds(width,height,i,j)){
                        canvas[(xi + i) / (int)zoom][(yi + j) / (int)zoom].setColor(color);
                        canvas[(xi + i) / (int)zoom][(yi + j) / (int)zoom].setId(id);
                    }
                }
            }
            startX += 0.09;
        }
    }
}

