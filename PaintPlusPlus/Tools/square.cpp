#include "square.h"

#include <QtDebug>

Square::Square()
{

}

/**
 * @brief Dibuja un cuadrilátero con el ancho y alto deseado en el canvas recibido
 * @param canvas    canvas en el que se desea dibujar
 * @param start     Posiciones (x,y) iniciales
 * @param end       Posiciones (x,y) finales
 * @param color     Color deseado
 * @param grosor    Grosor deseado
 * @param id        Identificador de la figura
 * @param zoom      Zoom deseado
 */
void Square::draw_square_in_canvas(pixel **canvas, int start[2], int end[2], uint32_t color, int grosor, int id, double zoom, int width, int height){
    int startx= start[0] / zoom;
    int starty = start[1] / zoom;
    int endx = end[0] / zoom;
    int endy = end[1] / zoom;
    int ciclo_startx;
    int ciclo_starty;
    int ciclo_endx;
    int ciclo_endy;
    int temp;

    if(startx < endx){
        ciclo_startx = startx;
        ciclo_endx = endx;
    }else{
         ciclo_startx = endx;
         ciclo_endx = startx;
         temp = startx;
         startx = endx;
         endx=temp;
    }

    if(starty<endy){
        ciclo_starty = starty;
        ciclo_endy = endy;
    }else{
        ciclo_starty = endy;
        ciclo_endy = starty;
        temp = starty;
        starty = endy;
        endy=temp;
    }
    for(int x = startx; x<endx;x++){
        for (int i = -grosor; i < grosor; i++){
            for(int j = -grosor; j < grosor; j++){
                if (!outOfBounds(width, height, ciclo_startx + i,ciclo_starty + j)) {
                    canvas[ciclo_startx + i][ciclo_starty + j].setColor(color);
                    canvas[ciclo_startx + i][ciclo_starty + j].setId(id);
                }
                if (!outOfBounds(width, height, ciclo_startx + i, ciclo_endy + j)) {
                    canvas[ciclo_startx + i][ciclo_endy + j].setColor(color);
                    canvas[ciclo_startx + i][ciclo_endy + j].setId(id);
                }


            }
        }
        ciclo_startx+=1;
    }

    for(int x = starty; x<endy;x++){
        for (int i = -grosor; i < grosor; i++){
            for(int j = -grosor; j < grosor; j++){
                if (!outOfBounds(width, height, startx + i, ciclo_starty + j)) {
                    canvas[startx + i ][ciclo_starty + j].setColor(color);
                    canvas[startx + i ][ciclo_starty + j].setId(id);

                }
                if (!outOfBounds(width, height, ciclo_endx + i, ciclo_starty + j)) {
                    canvas[ciclo_endx + i][ciclo_starty + j].setColor(color);
                    canvas[ciclo_endx + i][ciclo_starty + j].setId(id);
                }
            }
        }
        ciclo_starty+=1;
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
bool Square::outOfBounds(int width, int height, int posX, int posY) {
    if (posX < 0 || posX >= width || posY < 0 || posY >= height) {
        return true;
    } else {
        return false;
    }
}


