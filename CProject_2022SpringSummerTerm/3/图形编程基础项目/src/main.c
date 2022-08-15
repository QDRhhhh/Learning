#include <stdio.h>
#include <math.h>

//#include "libgraphics/graphics.h"
#include "turtlePencil.h"
#include "utils.h"

static double pi = 3.1415926;
static double scale = 0.4;
static int nn = 6; // the number of petals
static int nt = 3; // the number of offset flowers

void drawFlowersInside(double r){
    double ang, alpha = 360 / nn;
    for(ang = 0; ang <= 360; ang += alpha){
        drawPetalsInside(alpha, r);
        turn(alpha);
    }
    return;
}

void drawPetalsInside(double alpha, double r){
    double dis = r * 0.5 / cos( AtoR( alpha / 2 ) );
    turn( -alpha / 2 );
    forward(dis);
    turn( alpha );
    forward(dis);
    turn( 180-alpha );
    forward(dis);
    turn( alpha );
    forward(dis);
    turn(-alpha / 2 + 180);
}

void drawFlowersOutside(double dr){
    double ang, alpha = 360 / nn;
    for(ang = 0; ang <= 360; ang += alpha){
        drawPetalsOutside(alpha, dr);
        turn(alpha);
    }
    return;
}

void drawPetalsOutside(double alpha, double dr){
    double dis = dr * tan( AtoR( alpha / 2 ) );
    move(dr);
    turn(90);
    forward(dis);
    turn(180);
    move(dis);
    forward(dis);
    turn(180);
    move(dis);
    turn(90);
    move(dr);
    turn(180);
    return;
}

void Main(){
    init();
    double L = min(getScreenY(), getScreenX());
    double r = L * scale;
    double alpha = 360 / nn;
    int t = nt, i;
    for(i = 0; i < t;++i){
        drawFlowersInside(r);
        turn( alpha / t );
    }
    for(i = 0; i< t;++i){
        drawFlowersOutside(r);
        turn( alpha / t );
    }
    return;

}
