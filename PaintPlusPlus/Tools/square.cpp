#include "square.h"

#include <QtDebug>

Square::Square()
{

}


void Square::draw_square_in_canvas(pixel **canvas, int start[2], int end[2], uint32_t color, int grosor, int id, double zoom){
    int startx= start[0] / zoom;
    int starty = start[1] / zoom;
    int endx = end[0] / zoom;
    int endy = end[1] / zoom;

    //para los ciclos
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
                canvas[ciclo_startx + i][ciclo_starty + j].setColor(color);
                canvas[ciclo_startx + i][ciclo_endy + j].setColor(color);

                canvas[ciclo_startx + i][ciclo_starty + j].setId(id);
                canvas[ciclo_startx + i][ciclo_endy + j].setId(id);


            }
        }
        ciclo_startx+=1;
    }

    for(int x = starty; x<endy;x++){
        for (int i = -grosor; i < grosor; i++){
            for(int j = -grosor; j < grosor; j++){
                canvas[startx + i ][ciclo_starty + j].setColor(color);
                canvas[ciclo_endx + i][ciclo_starty + j].setColor(color);

                canvas[startx + i ][ciclo_starty + j].setId(id);
                canvas[ciclo_endx + i][ciclo_starty + j].setId(id);

            }
        }
        ciclo_starty+=1;
    }



}

