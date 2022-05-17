#include "square.h"

#include <QtDebug>

Square::Square()
{

}


void Square::draw_square_in_canvas(pixel **canvas, int start[2], int end[2], uint32_t color, int grosor){
    int startx= start[0];
    int starty = start[1];
    int endx = end[0];
    int endy = end[1];

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


            }
        }
        ciclo_startx+=1;
    }

    for(int x = starty; x<endy;x++){
        for (int i = -grosor; i < grosor; i++){
            for(int j = -grosor; j < grosor; j++){
                canvas[startx + i ][ciclo_starty + j].setColor(color);
                canvas[ciclo_endx + i][ciclo_starty + j].setColor(color);
            }
        }
        ciclo_starty+=1;
    }



}

