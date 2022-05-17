#include "square.h"

#include <iostream>
using namespace std;

Square::Square()
{

}


void Square::draw_square_in_canvas(pixel **canvas, int start[2], int end[2], uint32_t color, int grosor){
    int startx= start[0];
    int starty = start[1];
    int endx = end[0];
    int endy = end[1];

    //para los ciclos
    int ciclo_startx = startx;
    int ciclo_starty = starty;

    int ciclo_endx = endx;
    int ciclo_endy = endy;

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

