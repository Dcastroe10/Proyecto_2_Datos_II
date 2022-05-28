#include "circle.h"

#include <QDebug>

circle::circle()
{

}

/**
 * @brief Creación de un círculo en el canvas
 * @param canvas    canvas en el que se desea dibujar
 * @param start     Posiciones (x,y) iniciales
 * @param end       Posiciones (x,y) finales
 * @param color     Color deseado
 * @param grosor    Grosor deseado
 * @param id        Identificador de la figura para
 */
void circle::draw_circle(pixel **canvas, int start[2], int end[2], uint32_t color, int grosor, int id, int width, int height){
    int radius = abs((start[0]-end[0])/2);
    int centerx;
    int centery;
    int x=0;
    int y = radius;
    int d = 3-2*radius;

    if (start[0] < end[0]){
        centerx = start[0]+radius;
    }else{
        centerx = start[0] - radius;
    }

    if(start[1]< end[1]){
        centery = start[1] + radius;

    }else{
        centery = start[1] - radius;
    }

    while(x<=y){

        this->put_pixel(canvas, x, y, centerx, centery, color, grosor, id, width, height);

        if(d<0){
            d = d + 4 * x + 6;
        }else{
            d = d + 4 * x - 4 * y + 10;
            y--;
        }
        x++;

    }

}

/**
 * @brief Coloca los pixeles en el canvas para la creación del círculo
 * @param canvas    canvas en el que se desea dibujar
 * @param x         posición x
 * @param y         posición y
 * @param centerx   Coordenada x del centro
 * @param centery   Coordenada y del centro
 * @param color     Color deseado
 * @param grosor    Grosor deseado
 * @param id        Identificador de la figura para
 */
void circle::put_pixel(pixel **canvas, int x, int y, int centerx, int centery, uint32_t color, int grosor, int id, int width, int height){
    for (int i = -grosor; i < grosor; i++){
        for(int j = -grosor; j < grosor; j++){

            if (!outOfBounds(width, height, x + centerx + i, y + centery + j)) {
                canvas[x + centerx + i][ y + centery + j].setColor(color);
                canvas[x + centerx + i][ y + centery + j].setId(id);
            }

            if (!outOfBounds(width, height, x + centerx + i, -y + centery + j)) {
                canvas[x + centerx + i][ -y + centery + j].setColor(color);
                canvas[x + centerx + i][ -y + centery + j].setId(id);
            }


            if (!outOfBounds(width, height, -x + centerx + i, -y + centery + j)) {
                canvas[-x + centerx + i][ -y + centery + j].setColor(color);
                canvas[-x + centerx + i][ -y + centery + j].setId(id);
            }


            if (!outOfBounds(width, height, -x + centerx + i, -y + centery + j)) {
                canvas[-x + centerx + i][ y + centery + j].setColor(color);
                canvas[-x + centerx + i][ y + centery + j].setId(id);
            }


            if (!outOfBounds(width, height, y + centerx + i, x + centery + j)) {
                canvas[y + centerx + i][ x + centery + j].setColor(color);
                canvas[y + centerx + i][ x + centery + j].setId(id);
            }

            if (!outOfBounds(width, height, y + centerx + i, -x + centery + j)) {
                canvas[y + centerx + i][ -x + centery + j].setColor(color);
                canvas[y + centerx + i][ -x + centery + j].setId(id);
            }

            if (!outOfBounds(width, height, -y + centerx + i, -x + centery + j)) {
                canvas[-y + centerx + i][ -x + centery + j].setColor(color);
                canvas[-y + centerx + i][ -x + centery + j].setId(id);
            }

            if (!outOfBounds(width, height, -y + centerx + i, x + centery + j)) {
                canvas[-y + centerx + i][ x + centery + j].setColor(color);
                canvas[-y + centerx + i][ x + centery + j].setId(id);
            }
        }
    }
}

/**
 * @brief Verifica si se encuentra fuera de los límites del canvas
 * @param width     Ancho del canvas
 * @param height    Altura del canvas
 * @param posX      Posición x
 * @param posY      Posición y
 * @return
 */
bool circle::outOfBounds(int width, int height, int posX, int posY) {
    if (posX < 0 || posX >= width || posY < 0 || posY >= height) {
        return true;
    } else {
        return false;
    }
}
