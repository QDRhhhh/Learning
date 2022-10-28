#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <random>

#include "../../lib/meta_data.h"

using namespace std;

#define CANVAS_SIZE 128
#define STEP_LEN 4
#define STEP_LEN_LOWER_LIM 0.1
#define PI 3.1415926536
#define DISTURBANCE_LIM STEP_LEN/4

// Hyperparameter
const double weakenRate = 0.2;

default_random_engine e(time(NULL));

// Get a random number in -1 ~ 1 according to normal distribution.
double getNormalFactor(){
    static normal_distribution<double> distr(0.0, 0.6);
    double factor;
    do {
        factor = distr(e);
    } while(abs(factor) > 5);
    return factor / 5;
}

// Get a random number in 0 ~ 1 according to normal distribution.
double getAbsNormalFactor(){
    return abs(getNormalFactor());
}

// Get a random number in -1 ~ 1 according to uniform distribution.
double getUniformFactor(){
    static uniform_real_distribution<double> distr(-1.0, 1.0);
    return distr(e);
}

double getAbsUniformFactor(){
    return abs(getUniformFactor());
}

Point2D randomMove(Point2D & base){
    double step = STEP_LEN * ( 1 - getAbsNormalFactor()) + STEP_LEN_LOWER_LIM;
    double angle = PI * getUniformFactor();
    double dx = step * cos(angle);
    double dy = step * sin(angle);
    return(Point2D(
        base.getX() + dx,
        base.getY() + dy
    ));
}

Point2D randomTendentMove(Point2D & base, Point2D & preBase, double offsetAngle, Point2D & end, double backRate, double restTasks){
    double dx = base.getX() - preBase.getX();
    double dy = base.getY() - preBase.getY();
    double baseAngle = acos( dx/sqrt(dx*dx+dy*dy) );
    if(dy < 0) baseAngle = 2 * PI - baseAngle;

    double step = STEP_LEN * ( 1 - getAbsNormalFactor()) + STEP_LEN_LOWER_LIM;
    double angle = offsetAngle + baseAngle + PI * getNormalFactor();
    dx = step * cos(angle);
    dy = step * sin(angle);
    return(Point2D(
        (1 - backRate) * (base.getX() + dx) + backRate * (end.getX() - base.getX()) / max(restTasks-2, 1.2),
        (1 - backRate) * (base.getY() + dy) + backRate * (end.getY() - base.getY()) / max(restTasks-2, 1.2)
    ));
}

Polygon2D randPg(int size){
    double offsetAngle = 2 * PI / ( size * PI / 2 ); 
    std::vector<Point2D> pts;
    
    pts.clear();
    double x, y;
    auto base = Point2D(0, 0);
    pts.push_back( base );     // Base point.
    pts.push_back( randomMove( base ) );     // Base point.
    
    while(pts.size() < size){
        auto base = pts[ pts.size()-1 ];
        auto preBase = pts[ pts.size()-2 ];
        
        double backRate = pow(max(0.0, sin((double)pts.size() / size * PI / 2 - PI / 16)), pow(size, 0.5)) 
            * weakenRate 
            * min(
                1.0,
                pow( max(
                    base.getDis(pts[0]) / STEP_LEN / 8,
                    0.0
                ), 0.2)
            );

        int repeatCnt = 0;
        Point2D newPts(0,0);
        do{
            ++repeatCnt;
            newPts = randomTendentMove(base, preBase, offsetAngle, pts[0], pow(backRate, 1.0/repeatCnt), size - pts.size());
        }while( abs(newPts.getX()) > CANVAS_SIZE || abs(newPts.getY()) > CANVAS_SIZE );
    
        pts.push_back( Point2D(
            newPts.getX(),
            newPts.getY()
        ) );
    }

    return Polygon2D(pts);
}


Polygon2D rigidAndDisturbTransPg(Polygon2D & base, int offset){

    double scaleRate = 1 + getNormalFactor();
    double rotateAng = 2 * PI * getAbsUniformFactor();
    double cosAng = cos(rotateAng), sinAng = sin(rotateAng);
    double dx = (1 - getAbsNormalFactor()) * STEP_LEN * (base.getSize());
    double dy = (1 - getAbsNormalFactor()) * STEP_LEN * (base.getSize());

    vector<Point2D> tmp(base.getSize());

    for(int i = 0; i < base.getSize(); ++i){
        auto & pt = base.getPointByIdx(i);
        double x = pt.getX() * cosAng - pt.getY() * sinAng;
        double y = pt.getY() * cosAng + pt.getX() * sinAng;
        x *= scaleRate, y *= scaleRate;
        x += dx, y += dy;

        double distAng = PI * getUniformFactor();
        double distStep = DISTURBANCE_LIM * getAbsNormalFactor() * (getAbsNormalFactor() < 0.05 ? 16 : 1);
        x += distStep * cos(distAng);
        y += distStep * sin(distAng);
        tmp[ (i+offset) % (base.getSize()) ] = Point2D(x, y);
    }

    return Polygon2D(tmp);
}

Polygon2D addNoisePg(Polygon2D base, int num){
    for(int i = 0; i < num; ++i){
        int pos = base.getSize() * getAbsUniformFactor(); // Hidden cast.
        auto pre = base.getPreByIdx(pos);
        auto next = base.getNextByIdx(pos);
        double ang = PI * getUniformFactor();
        double step = STEP_LEN * (1 - getAbsNormalFactor());
        double dx = 2 * step * cos(ang) + 0.5*(pre.getX() + next.getX());
        double dy = 2 * step * sin(ang) + 0.5*(pre.getY() + next.getY());
        base.insertPoint(Point2D(dx, dy), pos);
    }
    return base;
}

int main(int argc, char * argv[]){
    srand((unsigned)time(NULL));

    ofstream ofIn;
    ofIn.open("test_data.in",ios::out | ios::trunc);
    
    vector<int> sizeSeq;
    // sizeSeq.push_back(10);
    // sizeSeq.push_back(10);
    // sizeSeq.push_back(20);
    // sizeSeq.push_back(20);
    // sizeSeq.push_back(25);
    sizeSeq.push_back(20);

    ofIn << sizeSeq.size() << endl;
    
    for(auto it = sizeSeq.begin(); it != sizeSeq.end(); ++it){
        // int oriN = *it * getAbsNormalFactor();
        auto pgA = randPg(*it);
        int offset = rand() % pgA.getSize();
        auto pgB = rigidAndDisturbTransPg(pgA, offset);
        pgA = addNoisePg(pgA, 4 * *it * getAbsNormalFactor());
        pgB = addNoisePg(pgB, 4 * *it * getAbsNormalFactor());

        ofIn << pgA.getSize() << endl;
        for(int i = 0; i < pgA.getSize(); ++i){
            auto & pt = pgA.getPointByIdx(i);
            ofIn << pt.getX() << " " << pt.getY() << endl;
        }
        ofIn << pgB.getSize() << endl;
        for(int i = 0; i < pgB.getSize(); ++i){
            auto & pt = pgB.getPointByIdx(i);
            ofIn << pt.getX() << " " << pt.getY() << endl;
        }

    }


}