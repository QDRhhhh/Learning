#include "random_vector2d_generator.h"

RandomVector2DGenerator::RandomVector2DGenerator(double ssl)
    :   e(std::time(0)),
        stepSizeLim(ssl),
        angleDistr(0, 2 * RVG_PI), 
        stepDistr(0, stepSizeLim){}


std::pair<double,double> RandomVector2DGenerator::randVec(){
    double ang = angleDistr(e);
    double step = stepDistr(e);
    return std::pair<double,double>(
        step * std::cos(ang),
        step * std::sin(ang)
    );
}


std::pair<double,double> RandomVector2DGenerator::randMove(std::pair<double,double> base){
    auto delVec = this->randVec();
    return std::pair<double,double>(
        base.first + delVec.first,
        base.second + delVec.second
    );
}