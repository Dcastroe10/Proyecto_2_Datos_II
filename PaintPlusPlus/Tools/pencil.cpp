#include "pencil.h"

Pencil::Pencil()
{

}

/**
 * @brief Calcula el valor de la pendiente para dibujar la linea recta
 * @param start     Posiciones (x,y) iniciales
 * @param end       Posiciones (x,y) finales
 * @return la pendiente de la recta
 */
float Pencil::mResult(int start[2], int end[2]) {
    float xif = start[0];
    float xff = end[0];
    float yif = start[1];
    float yff = end[1];
    float m = (yff - yif) / (xff - xif);
    return m;
}

/**
 * @brief Calcula el valor de b de la ecuación de la recta
 * @param x     Posición x
 * @param y     Posición y
 * @param m     Pendiente
 * @return el valor de b de la ecuación de la pendiente
 */
float Pencil::bResult(int x, int y, float m) {
    float xf = x;
    float yf = y;
    float mf = m;

    float b = yf - (mf * xf);
    return b;
}

/**
 * @brief Verifica si se encuentra fuera de los límites del canvas
 * @param width     Ancho del canvas
 * @param height    Altura del canvas
 * @param posX      Posición x
 * @param posY      Posición y
 * @return
 */
bool Pencil::outOfBounds(int width, int height, int posX, int posY) {
    if (posX < 0 || posX >= width || posY < 0 || posY >= height) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Dibuja una línea recta en el canvas por medio de la ecuación de la recta
 * @param canvas    canvas en el que se desea dibujar
 * @param start     Posiciones (x,y) iniciales
 * @param end       Posiciones (x,y) finales
 * @param color     Color con el que se desea pintar
 * @param grosor    Grosor deseado
 * @param id        Identificador
 * @param zoom      Zoom
 * @param width     Ancho del canvas
 * @param height    Alto del canvas
 */
void Pencil::drawALineInCanvas(pixel **canvas, int start[2], int end[2], uint32_t color, int grosor, int id, double zoom,int width, int height) {
    float m = mResult(start, end);
    float b = -bResult(start[0], start[1], m);
    float y = 0;

    int xi = 0;
    int yi = 0;

    float startX = start[0];
    float endX = end[0];


    if (start[0] > end[0]) {
        while(startX > endX) {
            y = (m * startX) - b;
            xi = int(startX);
            yi = int(y);
            for (int i = -grosor; i < grosor; i++){
                for(int j = -grosor; j < grosor; j++){
                    //qDebug() << i << j;
                    if(!this->outOfBounds(width,height,xi + i, yi + j)){
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
            for (int i = -grosor; i < grosor; i++){
                for(int j = -grosor; j < grosor; j++){
                    if(!this->outOfBounds(width,height,xi + i, yi + j)){
                        canvas[(xi + i) / (int)zoom][(yi + j) / (int)zoom].setColor(color);
                        canvas[(xi + i) / (int)zoom][(yi + j) / (int)zoom].setId(id);
                    }
                }
            }
            startX += 0.09;
        }
    }
}

