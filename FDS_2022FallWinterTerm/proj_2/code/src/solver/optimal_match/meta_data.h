#ifndef __META_DATA__
#define __META_DATA__

#include <cmath>
#include <vector>
#include "../utils/CNewbieHelper.h"

/* 
 * <[ Class Defination ]>
 * [ Class Name ]:
 * - Point2D
 * [ Description ]: 
 * - The class defines a meta data of a point with two double number that 
 * - represent coordinates.
 * [ Usage ]:
 * - You can initialize the point with the coordinates and use it as a meta
 * - data.
 * [ Index ]:
 * - C'tor & D'tor
 * - getX();
 * - getY();
 * - getDis();
 * [ Remarks ]:
 * - You are not supposed to use the default C'tor and I had made it private. 
 */
class Point2D{
private:
    static unsigned int uid;
    double x, y;

public:
    Point2D() = delete;

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - C'tor
     * [ Belonging Class ]:
     * - Point2D
     * [ Description ]:
     * - To initialize the points object.
     * [ Usage ]:
     * - "Point2D p(1.0, 2.0);" defines a plane points at (1.0, 2.0).
     */
    Point2D(double, double);
    
    ~Point2D() = default;

    // Functional Methods
    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - Point2D::getX()
     * [ Belonging Class ]:
     * - Point2D
     * [ Description ]:
     * - Get x coordinate value.
     * [ Usage ]:
     * - "p.getX()" gets a right value represents the x coordinate value
     * - of Point2D object p.
     */
    double getX();

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - Point2D::getY()
     * [ Belonging Class ]:
     * - Point2D
     * [ Description ]:
     * - Get y coordinate value.
     * [ Usage ]:
     * - "p.getY()" gets a right value represents the y coordinate value
     * - of Point2D object p.
     */
    double getY();

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - Point2D::getDis()
     * [ Belonging Class ]:
     * - Point2D
     * [ Description ]:
     * - Get the distance between this and that.
     * [ Usage ]:
     * - "p1.getDis(p2)" gets a right value represents the distance between
     * - p1 and p2.
     */
    double getDis(Point2D &);
    
    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - Point2D::getUid()
     * [ Belonging Class ]:
     * - Point2D
     * [ Description ]:
     * - Get the unique id of the point.
     * [ Usage ]:
     * - "p1.getUid()" gets a unsigned integer represents the unique id of
     * - the point.
     */
    int getUid();
};

/* 
 * <[ Class Defination ]>
 * [ Class Name ]:
 * - Polygon2D
 * [ Description ]: 
 * - The class defines a polygon with a set of orderred Point2D.
 * [ Usage ]:
 * - You can initialize the polygon with the vector consists of the 
 * - corner points.
 * [ Index ]:
 * - C'tor & D'tor
 * [ Remarks ]:
 * - You are not supposed to use the default C'tor and I had made it private. 
 */
class Polygon2D{
private:
    std::vector<Point2D> cornerPoints;

public:
    Polygon2D() = delete;

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - C'tor
     * [ Belonging Class ]:
     * - Polygon2D
     * [ Description ]:
     * - To initialize the polygon object.
     * [ Usage ]:
     * - "Polygon2D pg((vector<Point2D>)pts);" defines a plane polygon graph with the
     * - corner points stored in (vector<Point2D>)pts.
     */
    Polygon2D(std::vector<Point2D> cps);

    ~Polygon2D() = default;

    Point2D &getPre(Point2D &);
    Point2D &getNext(Point2D &);

};

#endif