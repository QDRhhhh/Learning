#ifndef __META_DATA__
#define __META_DATA__

#include <cmath>
#include <vector>
#include <iostream>

/* 
 * <[ Class Defination ]>
 * [ Class Name ]:
 * - Point2D
 * [ Description ]: 
 * - The class defines a meta data of a point with two double number that 
 * - represent coordinates.
 * [ Usage ]:
 * - You can initialize the point with the coordinates and use it as a meta
 * - data. And you can set the mark on the point (eg: You can set the mark
 * - as the UUID of the point, the value of the point, etc.) and get it after
 * - check.
 */
class Point2D{
private:

    bool isMarked;
    int mark;
    double x, y;

public:

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
    
    /*
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - Point2D::getX()
     * [ Belonging Class ]:
     * - Point2D
     * [ Description ]:
     * - Get x coordinate value.
     * - [ Params Description ]:
     * - - No params.
     * - [ Return Description ]:
     * - - (double) // The value of x coordinate value of the point.
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
     * - [ Params Description ]:
     * - - No params.
     * - [ Return Description ]:
     * - - (double) // The value of y coordinate value of the point.
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
     * - [ Params Description ]:
     * - - No params.
     * - [ Return Description ]:
     * - - (double) // The distance between this and that.
     * [ Usage ]:
     * - "p1.getDis(p2)" gets a right value represents the distance between
     * - p1 and p2.
     */
    double getDis(Point2D &);
    
    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - Point2D::setMark()
     * [ Belonging Class ]:
     * - Point2D
     * [ Description ]:
     * - Set a mark on the point.
     * - [ Params Description ]:
     * - - [1] (int) // The mark to be set.
     * - [ Return Description ]:
     * - - No retrun.
     * [ Usage ]:
     * - "p1.setMark(1)" sets the mark on p1 is 1.
     */
    void setMark(int);
    
    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - Point2D::hasMark()
     * [ Belonging Class ]:
     * - Point2D
     * [ Description ]:
     * - Query whether the point has a mark.
     * - [ Params Description ]:
     * - - No params.
     * - [ Return Description ]:
     * - - (bool) // Whether the point is marked.
     * [ Usage ]:
     * - "p1.hasMark(1)" returns a boolen value represent whether
     * - the point has a mark or not.
     */
    bool hasMark();

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - Point2D::getMark()
     * [ Belonging Class ]:
     * - Point2D
     * [ Description ]:
     * - Get the mark on the point.
     * - [ Params Description ]:
     * - - No params.
     * - [ Return Description ]:
     * - - (int) // The mark on the point.
     * - Important: you are supposed to check whether it has mark by 
     * - "hasMark()" before "getMark()".
     * - You are not supposed to get the mark if the point hasn't mark.
     * - And I will panic if this happens.
     * [ Usage ]:
     * - "p1.getMark()" gets a integer represents the mark on the point.
     */
    int getMark();
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
 */
class Polygon2D{
private:

    std::vector<Point2D> cornerPoints;

public:
    
    Polygon2D() = default;

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - C'tor
     * [ Belonging Class ]:
     * - Polygon2D
     * [ Description ]:
     * - To initialize the polygon object.
     * [ Usage ]:
     * - "Polygon2D pg((vector<Point2D>)pts);" defines a plane polygon 
     * - graph with the corner points stored in (vector<Point2D>)pts.
     */
    Polygon2D(std::vector<Point2D> cps);

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - Polygon2D::getPointByIdx()
     * [ Belonging Class ]:
     * - Polygon2D
     * [ Description ]:
     * - To get the refference of the point by pass in.
     * - [ Params Description ]:
     * - - [1] (int) // The index of the target point.
     * - [ Return Description ]:
     * - - (Point2D &) // The refference of the target point.
     * - You are not supposed to pass in an invalid point and I will panic
     * - if this happen.
     * [ Usage ]:
     * - "pg.getPointByIdx(idxP)" return the target point of p whose index 
     * - is idxP.
     */
    Point2D &getPointByIdx(int);

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - Polygon2D::getPreByIdx()
     * [ Belonging Class ]:
     * - Polygon2D
     * [ Description ]:
     * - To get the refference of the previous point by pass in.
     * - [ Params Description ]:
     * - - [1] (int) // The index of the current point.
     * - [ Return Description ]:
     * - - (Point2D &) // The refference of the previous point.
     * - You are not supposed to pass in an invalid point and I will panic
     * - if this happen.
     * [ Usage ]:
     * - "pg.getPreByIdx(idxP)" return the previous point of p whose index 
     * - is idxP.
     */
    Point2D &getPreByIdx(int);

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - Polygon2D::getNextByIdx()
     * [ Belonging Class ]:
     * - Polygon2D
     * [ Description ]:
     * - To get the refference of the next point by pass in.
     * - [ Params Description ]:
     * - - [1] (int) // The index of the current point.
     * - [ Return Description ]:
     * - - (Point2D &) // The refference of the next point.
     * - You are not supposed to pass in an invalid point and I will panic
     * - if this happen.
     * [ Usage ]:
     * - "pg.getNextByIdx(idxP)" return the next point of p whose index 
     * - is idxP.
     */
    Point2D & getNextByIdx(int);

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - Polygon2D::reset()
     * [ Belonging Class ]:
     * - Polygon2D
     * [ Description ]:
     * - Reset the point set in the polygon.
     * - [ Params Description ]:
     * - - No params.
     * - [ Return Description ]:
     * - - No params.
     * [ Usage ]:
     * - "pg.reset()" will reset pg.
     */
    void reset();

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - Polygon2D::getSize()
     * [ Belonging Class ]:
     * - Polygon2D
     * [ Description ]:
     * - Get the number of points in the polygon.
     * - [ Params Description ]:
     * - - No params.
     * - [ Return Description ]:
     * - - (int) // The size of points.
     * [ Usage ]:
     * - "pg.getSize()" returns the size of points.
     */
    int getSize();

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - Polygon2D::insertPointBack()
     * [ Belonging Class ]:
     * - Polygon2D
     * [ Description ]:
     * - Insert the point after the end of points, which should be the "previous"
     * - point of the points[0].
     * - [ Params Description ]:
     * - - [1] (Point2D) // The Point to be insert.
     * - [ Return Description ]:
     * - - No params.
     * [ Usage ]:
     * - "pg.insertPointBack(p)" will insert the point after the end of points.
     */
    void insertPointBack(Point2D);

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - Polygon2D::removePointBack()
     * [ Belonging Class ]:
     * - Polygon2D
     * [ Description ]:
     * - Remove the point after the end of points, which should be the "previous"
     * - point of the points[0].
     * - [ Params Description ]:
     * - - No params.
     * - [ Return Description ]:
     * - - No params.
     * [ Usage ]:
     * - "pg.removePointBack(p)" will remove the point after the end of points.
     */
    void removePointBack();
};



// Change it if the elements is not this.
using TableEleType = double;
// Pre declaration. 
class Table2D;

/* 
 * <[ Class Defination ]>
 * [ Class Name ]
 * - TableSlice
 * [ Description ]: 
 * - The class defines a slice in 2d-table.
 * [ Usage ]:
 * - Actually, you shouldn't use it directly.
 */
class TableSlice{
private:

    int idx1;
    Table2D * table2D;

public:

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - C'tor
     * [ Belonging Class ]:
     * - TableSlice
     * [ Description ]:
     * - To initialize the table slice object.
     * [ Usage ]:
     * - "TableSlice tb(&t, 4);" indexed the fifth layer of Table2D t.
     */
    TableSlice(Table2D *, int);

    /* 
     * <[ Class Overload Defination ]>
     * [ Overload Option ]:
     * - []
     * [ Belonging Class ]:
     * - TableSlice
     * [ Description ]:
     * - To get the element of the slice.
     * - Actually, you shouldn't use it directly.
     * - [ Params Description ]:
     * - - [1] (int) // The index of element.
     * - [ Return Description ]:
     * - - (TableEleType) // The slice of the 2d-table.
     * [ Usage ]:
     * - "tb[1]" returns the second layer of 2d-table (start from 0).
     * - "tb[2][3]" returns the element at table[2][3].
     */
    TableEleType & operator[](int);
};



/* 
 * <[ Class Defination ]>
 * [ Class Name ]
 * - Table2D
 * [ Description ]: 
 * - The class defines a 2d-table to store the votes of the match. 
 * [ Usage ]:
 * - You should first set the relevant params before use. Then pass in the 
 * - "Point2D" objects, the relevant function will return the match result.
 */
class Table2D{
// Private elements can be accessed by TableSlice.
friend class TableSlice;
private:

    std::pair<int,int> shape;
    std::vector<TableEleType> table;

public:

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - C'tor
     * [ Belonging Class ]:
     * - Table2D
     * [ Description ]:
     * - To initialize the 2d-table object.
     * [ Usage ]:
     * - "Table2D tb(3, 4);" defines a 3*4 2d-table.
     */
    Table2D(int ,int, TableEleType);

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - Table2D::getShape()
     * [ Belonging Class ]:
     * - Table2D
     * [ Description ]:
     * - To get the shape of the table.
     * - [ Params Description ]:
     * - - No params.
     * - [ Return Description ]:
     * - - (std::pair<int,int>) // The shape of the 2d-table is rt.first * rt.second.
     * [ Usage ]:
     * - "tb.getShape();" returns the shape of the 2d-table.
     */
    std::pair<int,int> getShape();

    /* 
     * <[ Class Overload Defination ]>
     * [ Overload Option ]:
     * - []
     * [ Belonging Class ]:
     * - Table2D
     * [ Description ]:
     * - To get the slice of the table.
     * - Actually, you are supposed to use it with "[x][y]" form.
     * - [ Params Description ]:
     * - - [1] (int) // The layer of slice.
     * - [ Return Description ]:
     * - - (TableSlice) // The slice of the 2d-table.
     * [ Usage ]:
     * - "tb[1]" returns the second layer of 2d-table (start from 0).
     * - "tb[2][3]" returns the element at table[2][3].
     */
    TableSlice operator[](int);
};


#endif