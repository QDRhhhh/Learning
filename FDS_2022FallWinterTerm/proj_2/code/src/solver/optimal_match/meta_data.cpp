#include "meta_data.h"

/*
 * <[ Class Methods Implementations ]>
 * [ Class Name ]:
 * - Point2D
 */

Point2D::Point2D(double x, double y): x(x), y(y){
    ++uid;
}

double Point2D::getX(){
    return this->x;
}

double Point2D::getY(){
    return this->y;
}

double Point2D::getDis(Point2D &that){
    double dx = this->x - that.getX();
    double dy = this->y - that.getY();
    return sqrt(dx * dx + dy * dy);
}

int Point2D::getUid(){
    return uid;
}

/*
 * <[ Class Methods Implementations ]>
 * [ Class Name ]:
 * - Polygon2D
 */

Polygon2D::Polygon2D(std::vector<Point2D> cps): cornerPoints(cps){}
