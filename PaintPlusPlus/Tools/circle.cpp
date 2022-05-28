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
void circle::draw_circle(pixel **canvas, int start[2], int end[2], uint32_t color, int grosor, int id){
    int radius = abs((start[0]-end[0])/2);
    int centerx;
    int centery;
    //brensananahbsadmsadjlaksdasd method
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

        this->put_pixel(canvas, x, y, centerx, centery, color, grosor, id);

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
void circle::put_pixel(pixel **canvas,int x, int y, int centerx, int centery, uint32_t color, int grosor, int id){
    for (int i = -grosor; i < grosor; i++){
        for(int j = -grosor; j < grosor; j++){

            canvas[x + centerx + i][ y + centery + j].setColor(color);

            canvas[x + centerx + i][ -y + centery + j].setColor(color);

            canvas[-x + centerx + i][ -y + centery + j].setColor(color);

            canvas[-x + centerx + i][ y + centery + j].setColor(color);

            canvas[y + centerx + i][ x + centery + j].setColor(color);

            canvas[y + centerx + i][ -x + centery + j].setColor(color);

            canvas[-y + centerx + i][ -x + centery + j].setColor(color);

            canvas[-y + centerx + i][ x + centery + j].setColor(color);

            //ids for delete figures:

            canvas[x + centerx + i][ y + centery + j].setId(id);

            canvas[x + centerx + i][ -y + centery + j].setId(id);

            canvas[-x + centerx + i][ -y + centery + j].setId(id);

            canvas[-x + centerx + i][ y + centery + j].setId(id);

            canvas[y + centerx + i][ x + centery + j].setId(id);

            canvas[y + centerx + i][ -x + centery + j].setId(id);

            canvas[-y + centerx + i][ -x + centery + j].setId(id);

            canvas[-y + centerx + i][ x + centery + j].setId(id);


        }
    }
}
