#include "circle.h"

#include <QDebug>

circle::circle()
{

}


void circle::draw_circle(pixel **canvas, int start[2], int end[2], uint32_t color, int grosor){
    int radius = abs((start[0]-end[0])/2);
    int centerx;
    int centery;
    int grados = 0; // para probar hacer la vuelta
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



    qDebug()<<"entroooooooooooooo    "<<radius<<"      radioooo";
    qDebug()<<"entroooooooooooooo    "<<centerx<<"      centeeeer";

    for (int i = -grosor; i < grosor; i++){
        for(int j = -grosor; j < grosor; j++){
            canvas[centerx + i][centery + j].setColor(color);

            //En x
            canvas[centerx + radius + i][centery + j].setColor(color);
            canvas[centerx - radius + i][centery + j].setColor(color);
            //EN Y
            canvas[centerx + i][centery + radius + j].setColor(color);
            canvas[centerx + i][centery - radius + j].setColor(color);

            canvas[centerx + i + 5][centery + radius + j].setColor(color);
            canvas[centerx + i + 5][centery - radius + j].setColor(color);
        }
    }




}




/*
 *     for(int x = startx; x<endx;x++){
        for (int i = -grosor; i < grosor; i++){
            for(int j = -grosor; j < grosor; j++){
                canvas[ciclo_startx + i][ciclo_starty + j].setColor(color);
                canvas[ciclo_startx + i][ciclo_endy + j].setColor(color);


            }
        }
        ciclo_startx+=1;
    }
    */
