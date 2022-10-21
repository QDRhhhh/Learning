#ifndef __RANDOM_VECTOR2D_GENERATOR__
#define __RANDOM_VECTOR2D_GENERATOR__


#include <random>
#include <cmath>
#include <ctime>

#define RVG_PI 3.1415926535

class RandomVector2DGenerator{
private:

    std::default_random_engine e;
    double stepSizeLim;
    std::normal_distribution<double> angleDistr, stepDistr;

public:

    RandomVector2DGenerator(double);

    std::pair<double,double> randVec();
    std::pair<double,double> randMove(std::pair<double,double>);
    
};


#endif