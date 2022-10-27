# Appendix

## 路径树 | Directory Tree

```shell
$ tree
.
├── Readme.md
├── _auto.sh
├── _clear.sh
└── src
    ├── _clear.sh
    ├── _compile.sh
    ├── _run.sh
    ├── judger
    │   ├── _clear.sh
    │   ├── _judge.sh
    │   ├── _setup.sh
    │   ├── cache
    │   ├── judger.cpp
    │   ├── painter
    │   │   ├── painter.py
    │   │   └── requirements.txt
    │   ├── section_A
    │   │   ├── Readme.md
    │   │   └── maker.cpp
    │   ├── section_B
    │   │   ├── Readme.md
    │   │   └── maker.cpp
    │   └── section_C
    │       ├── Readme.md
    │       └── maker.cpp
    ├── lib
    │   ├── meta_data.cpp
    │   └── meta_data.h
    └── solver
        ├── _clear.sh
        ├── _setup.sh
        ├── main.cpp
        └── optimal_match
            ├── match_referee.cpp
            ├── match_referee.h
            ├── voting_tree.cpp
            └── voting_tree.h
```

- 只有与问题解决有关的代码会被放在这里，如果您想了解其他内容，请自行查看对应的文件。
- Only files related with the solver will be put here. Check others yourself if you want.

## lib

- `meta_data.h`

```cpp
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

    Point2D() = default;

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
     * - "pg.getPointByIdx(idxP)" return the reference of target point of p 
     * - whose index is idxP.
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
     * - Polygon2D::insertPoint()
     * [ Belonging Class ]:
     * - Polygon2D
     * [ Description ]:
     * - Insert the point after the end of points, which should be the "previous"
     * - point of the points[0].
     * - [ Params Description ]:
     * - - [1] (Point2D) // The Point to be insert.
     * - - [2] (int) // The index of the point where will new point where put behind.
     * - [ Return Description ]:
     * - - No params.
     * [ Usage ]:
     * - "pg.insertPoint(p, 0)" will insert the point behind the point of index 0.
     */
    void insertPoint(Point2D, int);

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
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - Table2D::getElements()
     * [ Belonging Class ]:
     * - Table2D
     * [ Description ]:
     * - To get all the elements of the table.
     * - [ Params Description ]:
     * - - No params.
     * - [ Return Description ]:
     * - - (std::vector<TableEleType>) // All the elements of the table.
     * [ Usage ]:
     * - "tb.getElements();" returns all the elements of the table.
     */
    std::vector<TableEleType> getElements();

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
```

- `meta_data.cpp`

```cpp
#include "meta_data.h"

/*
 * <[ Class Methods Implementations ]>
 * [ Class Name ]:
 * - Point2D
 */

// Detail comments are in `.h` file!
Point2D::Point2D(double x, double y): x(x), y(y), isMarked(false){}

// Detail comments are in `.h` file!
double Point2D::getX(){
    return this->x;
}

// Detail comments are in `.h` file!
double Point2D::getY(){
    return this->y;
}

// Detail comments are in `.h` file!
double Point2D::getDis(Point2D &that){
    double dx = this->x - that.getX();
    double dy = this->y - that.getY();
    return sqrt(dx     * dx + dy     * dy);
}

// Detail comments are in `.h` file!
void Point2D::setMark(int m){
    this->mark = m;
    this->isMarked = true;
}

// Detail comments are in `.h` file!
bool Point2D::hasMark(){
    return this->isMarked;
}

// Detail comments are in `.h` file!
int Point2D::getMark(){
    // Panic for invalid option.
    if(!isMarked){
        std::cerr << __FILE__ << "/" << __LINE__ <<  " [FATAL] The point is not marked!\n";
        exit(0);
    }
    return this->mark;
}



/*
 * <[ Class Methods Implementations ]>
 * [ Class Name ]:
 * - Polygon2D
 */

// Detail comments are in `.h` file!
Polygon2D::Polygon2D(std::vector<Point2D> cps)
    :   cornerPoints(cps){
    // Set alias to make codes below briefly.
    std::vector<Point2D> &vec = Polygon2D::cornerPoints;
    // Set the mark of the point to be the index in the vector.
    // It will make the other option more convenient.
    for(int i = 0; i < vec.size(); ++i){
        vec[i].setMark(i);
    }
}

// Detail comments are in `.h` file!
Point2D & Polygon2D::getPointByIdx(int idxP){
    // Store the size to make codes below briefly.
    int pgSize = this->cornerPoints.size();
    // Panic if the param is invalid.
    if(idxP >= pgSize){
        std::cerr << __FILE__ << "/" << __LINE__ << 
            " [FATAL] Invalid idxP! idxP = [ " << idxP << " ] while pgSize = [ " << pgSize << " ]\n";
        exit(0);
    }
    return this->cornerPoints[idxP];
}

// Detail comments are in `.h` file!
Point2D & Polygon2D::getPreByIdx(int idxP){
    // Store the size to make codes below briefly.
    int pgSize = this->cornerPoints.size();
    // Panic if the param is invalid.
    if(idxP >= pgSize){
        std::cerr << __FILE__ << "/" << __LINE__ << 
            " [FATAL] Invalid idxP! idxP = [ " << idxP << " ] while pgSize = [ " << pgSize << " ]\n";
        exit(0);
    }
    // Calculate the next index.
    int nextIdx = (idxP + pgSize - 1) % pgSize;
    return this->getPointByIdx(nextIdx);
}

// Detail comments are in `.h` file!
Point2D & Polygon2D::getNextByIdx(int idxP){

    // Store the size to make codes below briefly.
    int pgSize = this->getSize();
    // Panic if the param is invalid.
    if(idxP >= pgSize){
        std::cerr << __FILE__ << "/" << __LINE__ << 
            " [FATAL] Invalid idxP! idxP = [ " << idxP << " ] while pgSize = [ " << pgSize << " ]\n";
        exit(0);
    }
    // Calculate the next index.
    int nextIdx = (idxP + 1) % pgSize;
    return this->getPointByIdx(nextIdx);
}

// Detail comments are in `.h` file!
void Polygon2D::reset(){
    while(this->getSize()) cornerPoints.pop_back();
    return;
}

// Detail comments are in `.h` file!
int Polygon2D::getSize(){
    return this->cornerPoints.size();
}

// Detail comments are in `.h` file!
void Polygon2D::insertPoint(Point2D p, int idx){
    // Panic if the param is invalid.
    if(idx >= this->getSize()){
        std::cerr << __FILE__ << "/" << __LINE__ << 
            " [FATAL] Invalid idxP! idxP = [ " << idx << " ] while pgSize = [ " << this->getSize() << " ]\n";
        exit(0);
    }
    auto & vec = this->cornerPoints;
    vec.insert( vec.begin() + idx, p );
    return;
}

// Detail comments are in `.h` file!
void Polygon2D::insertPointBack(Point2D p){
    this->cornerPoints.push_back(p);
    ( this->cornerPoints.end()-1 )->setMark( this->cornerPoints.size()-1 );
    return;
}

// Detail comments are in `.h` file!
void Polygon2D::removePointBack(){
    if(this->cornerPoints.size() > 0){
        this->cornerPoints.pop_back();
    }
    return;
}



/*
 * <[ Class Methods Implementations ]>
 * [ Class Name ]:
 * - TableSlice
 */

// Detail comments are in `.h` file!
TableSlice::TableSlice(Table2D * t, int idx): idx1(idx), table2D(t){}

// Detail comments are in `.h` file!
TableEleType & TableSlice::operator[](int idx2){
    int offset = idx1 * table2D->shape.second + idx2;
    return table2D->table[offset];
}



/*
 * <[ Class Methods Implementations ]>
 * [ Class Name ]:
 * - Table2D
 */

// Detail comments are in `.h` file!
Table2D::Table2D(int m, int n, TableEleType dVal): shape(m,n){
    // Reshape the vector to m * n.
    table.resize(m * n);
    for(auto it = table.begin(); it != table.end(); ++it){
        *it = dVal;
    }
}

// Detail comments are in `.h` file!
std::pair<int,int> Table2D::getShape(){
    return this->shape;
}

// Detail comments are in `.h` file!
std::vector<TableEleType> Table2D::getElements(){
    return table;
}

// Detail comments are in `.h` file!
TableSlice Table2D::operator[](int idx){
    return TableSlice(this, idx);
}
```

## solver

- `main.cpp`

```cpp
#include <iomanip>
#include <iostream>
#include <ctime>

#include "optimal_match/voting_tree.h"

#define WIDTH 4

void printResult( std::vector< std::pair<int,int> > & res){
    std::cout << res.size() << std::endl;
    for(auto it = res.begin(); it != res.end(); ++it){
        std::cout << std::setw(WIDTH) << it->first << std::setw(WIDTH) << it->second << std::endl;
    }
}

void solve(){
    MatchReferee judger1(0.1, 0.1, 1.0);
    MatchReferee judger2(0.1, 0.1, 1.0);
    auto inA = VotingTree::readPts(std::cin);
    auto inB = VotingTree::readPts(std::cin);
    VotingTree vTree(inA, inB, judger1, judger2, 5, inA.size()*10);

    vTree.dealOptimalMatch();

    // // Debug::
    // auto vTable = vTree.getVotingTable();
    // std::cerr << "\n\n";
    // for(auto i = 0; i < vTable.getShape().first; ++i){
    //     for(auto j = 0; j < vTable.getShape().second; ++j){
    //         std::cerr << std::setw(WIDTH) << vTable[i][j] << " ";
    //     }
    //     std::cerr << std::endl;
    // }
    // std::cerr << "\n\n";
    
    auto result = vTree.getOptimalMatch();
    printResult(result);
}

int main(){
    std::ios::sync_with_stdio(false);
    int _;
    std::cin >> _;
    for(int i = 1; i <= _; ++i){
        std::cerr << " Test case " << i << " Start.\n";
        solve();
        std::cerr << " Test case " << i << " Finished.\n";
    }
    return 0;
}
```

- `match_referee.h`

```cpp
#ifndef __MATCH_REFEREE__
#define __MATCH_REFEREE__

// Head files.
#include <set>
#include <cmath>
#include <iostream>
#include "../../lib/meta_data.h"

/* 
 * <[ Class Defination ]>
 * [ Class Name ]
 * - MatchReferee
 * [ Description ]: 
 * - The class defines a judement system for optimal match.
 * [ Usage ]:
 * - You should first set the relevant params before use. Then pass in the 
 * - "Point2D" objects, the relevant function will return the match result.
 */
class MatchReferee{
private:

    double angleTolerance;
    double edgeRatioTolerance;
    double weight;

public:

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - C'tor
     * [ Belonging Class ]:
     * - MatchReferee
     * [ Description ]:
     * - To initialize the points object.
     * [ Usage ]:
     * - "MatchReferee p(0.1, 0.2, 1.0);" initialize the referee with
     * - angleTolerance = 0.1 and edgeRatioTolerance = 0.2 and weight = 1.0.
     */
    MatchReferee(double, double, double);

    // Functional Methods

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - MatchReferee::isMatch()
     * [ Belonging Class ]:
     * - MatchReferee
     * [ Description ]:
     * - Get the weight of the juder.
     * - [ Params Description ]:
     * - No params.
     * - [ Return Description ]:
     * - - (double) // The weight of the judger.
     * [ Usage ]:
     * - "mr.getWeight();" gets the weight of the judger.
     */
    double getWeight();

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - MatchReferee::isMatch()
     * [ Belonging Class ]:
     * - MatchReferee
     * [ Description ]:
     * - To judge whether the angle with edge can match.
     * - [ Params Description ]:
     * - - [1-3] (Point2D &) // The points form the first corner.
     * - - [4-6] (Point2D &) // The points form the second corner.
     * - [ Return Description ]:
     * - - (bool) // Whether the two corner can be matched.
     * [ Usage ]:
     * - "mr.isMatch(U, V, W, X, Y, Z);" gets a boolen value 
     * - represents whether the △UVW are approximately similar 
     * - with △XYZ.
     */
    bool isMatch(Point2D &, Point2D &, Point2D &, Point2D &, Point2D &, Point2D &);
};

#endif
```

- `match_referee.cpp`

```cpp
#ifndef __MATCH_REFEREE__
#define __MATCH_REFEREE__

// Head files.
#include <set>
#include <cmath>
#include <iostream>
#include "../../lib/meta_data.h"

/* 
 * <[ Class Defination ]>
 * [ Class Name ]
 * - MatchReferee
 * [ Description ]: 
 * - The class defines a judement system for optimal match.
 * [ Usage ]:
 * - You should first set the relevant params before use. Then pass in the 
 * - "Point2D" objects, the relevant function will return the match result.
 */
class MatchReferee{
private:

    double angleTolerance;
    double edgeRatioTolerance;
    double weight;

public:

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - C'tor
     * [ Belonging Class ]:
     * - MatchReferee
     * [ Description ]:
     * - To initialize the points object.
     * [ Usage ]:
     * - "MatchReferee p(0.1, 0.2, 1.0);" initialize the referee with
     * - angleTolerance = 0.1 and edgeRatioTolerance = 0.2 and weight = 1.0.
     */
    MatchReferee(double, double, double);

    // Functional Methods

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - MatchReferee::isMatch()
     * [ Belonging Class ]:
     * - MatchReferee
     * [ Description ]:
     * - Get the weight of the juder.
     * - [ Params Description ]:
     * - No params.
     * - [ Return Description ]:
     * - - (double) // The weight of the judger.
     * [ Usage ]:
     * - "mr.getWeight();" gets the weight of the judger.
     */
    double getWeight();

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - MatchReferee::isMatch()
     * [ Belonging Class ]:
     * - MatchReferee
     * [ Description ]:
     * - To judge whether the angle with edge can match.
     * - [ Params Description ]:
     * - - [1-3] (Point2D &) // The points form the first corner.
     * - - [4-6] (Point2D &) // The points form the second corner.
     * - [ Return Description ]:
     * - - (bool) // Whether the two corner can be matched.
     * [ Usage ]:
     * - "mr.isMatch(U, V, W, X, Y, Z);" gets a boolen value 
     * - represents whether the △UVW are approximately similar 
     * - with △XYZ.
     */
    bool isMatch(Point2D &, Point2D &, Point2D &, Point2D &, Point2D &, Point2D &);
};

#endif
```

- `voting_tree.h`

```cpp
#ifndef __VOTING_TREE__
#define __VOTING_TREE__

// Head file.
#include <vector>
#include <iostream>
#include "../../lib/meta_data.h"
#include "match_referee.h"

// Pre declaration. 
class VotingTree;

/* 
 * <[ Class Defination ]>
 * [ Class Name ]
 * - CurStage
 * [ Description ]: 
 * - The class store the current stage.
 */
class CurStage{
// Private elements can be accessed by TableSlice.
friend class VotingTree;
private:

    Polygon2D curA, curB;
    std::vector< std::pair<int,int> > curPath;

public:

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - CurStage::reset()
     * [ Belonging Class ]:
     * - CurStage
     * [ Description ]:
     * - It will reset the current stage.
     * - [ Params Description ]:
     * - - No params.
     * - [ Return Description ]:
     * - - No params.
     * [ Usage ]:
     * - "cur.reset()" will do the things above.
     */
    void reset();

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - CurStage::storeStage()
     * [ Belonging Class ]:
     * - CurStage
     * [ Description ]:
     * - It will store the current stage.
     * - [ Params Description ]:
     * - - [1] (VotingTree *) // The voting tree store the data.
     * - - [2-3] (int) // The index of points in pgA and pgB to be store.
     * - [ Return Description ]:
     * - - No params.
     * [ Usage ]:
     * - "cur.storeStage(1, 2)" will store the pA[1] and pB[2] to the stage.
     */
    void storeStage(VotingTree *, int, int);

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - CurStage::recoverStage()
     * [ Belonging Class ]:
     * - CurStage
     * [ Description ]:
     * - It will recover the current stage.
     * - [ Params Description ]:
     * - - No params.
     * - [ Return Description ]:
     * - - No params.
     * [ Usage ]:
     * - "cur.recoverStage()" will do the things above.
     */
    void recoverStage();

};

/* 
 * <[ Class Defination ]>
 * [ Class Name ]
 * - VotingTree
 * [ Description ]: 
 * - The class defines a voting tree object to solve the problem.
 * [ Usage ]:
 * - You should construct the voting tree object with the input that consists of
 * - two vector.
 */
class VotingTree{
// Private elements can be accessed by TableSlice.
friend class CurStage;
public:
    // Define a memeber struct.
    struct MatchPair{
        int x, y;
        double ele;
        // Actually, it DON'T means '<', I actually define the comparation function 
        // for std::sort(), it act just like the custom cmp() you usually defined.
        // After this, the elements will be sorted in monotonically decreasing order.
        bool operator<( const MatchPair & rhs) const;
    };
private: 

    Polygon2D pgA, pgB;
    Table2D votingTable;
    MatchReferee &judger1;
    MatchReferee &judger2;
    std::vector< std::pair<int,int> > optimalMatch;
    int credibleLowerLimit; // At least 3. Because any 2points-2points pair will match.
    double mutationRatio; // The ratio of the mutation in 'matchAccordingTalbe' progress.

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - VotingTree::voteByDfs()
     * [ Belonging Class ]:
     * - VotingTree
     * [ Description ]:
     * - It will dfs the possible matching and get the sum of vote of each match.
     * - [ Params Description ]:
     * - - (CurStage) // The current stage.
     * - [ Return Description ]:
     * - - std::pair<double, bool> // The vote of the current match and the success sign of the path.
     * - - That means, if the path is impossible, the second value will be false, vice versa.
     * [ Usage ]:
     * - "vt.voteByDfs()" will dfs and get the vote of current match (also the son of the match).
     */
    std::pair<double, bool> voteByDfs(CurStage &);

public:
    
    /* 
     * <[ Class Static Methods Defination ]>
     * [ Method Name ]:
     * - VotingTree::readPts()
     * [ Belonging Class ]:
     * - VotingTree
     * [ Description ]:
     * - To get the input data from istream.
     * - [ Params Description ]:
     * - - [1] (std::istream) // The input stream where we get input from.
     * - [ Return Description ]:
     * - - (std::vector<Point2D>) // The points.
     * [ Usage ]:
     * - "VotingTree::readPts(cin)" returns a vector of Points2D read from
     * - cin stream.
     */
    static std::vector<Point2D> readPts(std::istream &);
    
    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - C'tor
     * [ Belonging Class ]:
     * - VotingTree
     * [ Description ]:
     * - To initialize the polygon object.
     * [ Usage ]:
     * - "VotingTree vt(A, B, j1, j2, 5, 1.0);" defines a voting tree solve the situation with 
     * - graph with the corner points stored in (vector<Point2D>)pts A and B, and the match
     * - judgement will be done by j1 and j2. The number of points in polygon shouldn't be 
     * - less than 5. What's more, the mutationRatio is 1.0
     */
    VotingTree(std::vector<Point2D> &, std::vector<Point2D> &, MatchReferee &, MatchReferee &, int, double);

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - VotingTree::searchAndVote()
     * [ Belonging Class ]:
     * - VotingTree
     * [ Description ]:
     * - It will search for the possible matching schemes and vote for them.
     * - The votes will be updated to votingTable.
     * - [ Params Description ]:
     * - - No params.
     * - [ Return Description ]:
     * - - No params.
     * [ Usage ]:
     * - "vt.searchAndVote()" will do the things above.
     */
    void searchAndVote();

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - VotingTree::getVotingTable()
     * [ Belonging Class ]:
     * - VotingTree
     * [ Description ]:
     * - It will return the copy of the voting table.
     * - [ Params Description ]:
     * - - No params.
     * - [ Return Description ]:
     * - - (Table2D) // The copy of the voting table.
     * [ Usage ]:
     * - "vt.getVotingTable()" returns the copy of the voting table.
     */
    Table2D getVotingTable();

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - VotingTree::matchAccordingTalbe()
     * [ Belonging Class ]:
     * - VotingTree
     * [ Description ]:
     * - It will deal the voting table and get the matching relationship.
     * - The answer will be stored into the optimalMatch.
     * - [ Params Description ]:
     * - - No params.
     * - [ Return Description ]:
     * - - No params.
     * [ Usage ]:
     * - "vt.matchAccordingTalbe()" will do the things above.
     */
    void matchAccordingTalbe();

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - VotingTree::dealOptimalMatch()
     * [ Belonging Class ]:
     * - VotingTree
     * [ Description ]:
     * - To calculate the optimal match of the two polygon.
     * - [ Params Description ]:
     * - - No params.
     * - [ Return Description ]:
     * - - No params.
     * [ Usage ]:
     * - "vt.dealOptimalMatch()" calculates the optimal match and store it in
     * - optimalMatch.
     */
    void dealOptimalMatch();

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - VotingTree::getOptimalMatch()
     * [ Belonging Class ]:
     * - VotingTree
     * [ Description ]:
     * - To get the optimal match calculated.
     * - You will get nothing if you getOptimalMatch() before dealOptimalMatch().
     * - [ Params Description ]:
     * - - No params.
     * - [ Return Description ]:
     * - - (std::vector< std::pair<int,int> >) // The optimal match.
     * [ Usage ]:
     * - "vt.getOptimalMatch()" returns the optimal match.
     */
    std::vector< std::pair<int,int> > getOptimalMatch();
};


#endif
```

- `voting_tree.cpp`

```cpp
#include "voting_tree.h"

/*
 * <[ Class Methods Implementations ]>
 * [ Class Name ]:
 * - CurStage
 */

// Detail comments are in `.h` file!
void CurStage::reset(){
    this->curA.reset();
    this->curB.reset();
    this->curPath.resize(0);
}

// Detail comments are in `.h` file!
void CurStage::storeStage(VotingTree * vt, int ia, int ib){
    curA.insertPointBack( vt->pgA.getPointByIdx(ia) );
    curB.insertPointBack( vt->pgB.getPointByIdx(ib) );
    curPath.push_back( std::make_pair(ia, ib) );
}

// Detail comments are in `.h` file!
void CurStage::recoverStage(){
    curA.removePointBack();
    curB.removePointBack();
    curPath.pop_back();
}


/*
 * <[ Class Methods Implementations ]>
 * [ Class Name ]:
 * - VotingTree
 */

// Detail comments are in `.h` file!
bool VotingTree::MatchPair::operator<( const MatchPair & rhs) const { 
    return this->ele > rhs.ele; 
}

// Detail comments are in `.h` file!
std::vector<Point2D> VotingTree::readPts(std::istream & input){
    // Initialize the variable to be used.
    int size;
    double x, y;
    std::vector<Point2D> vec;
    // Read in the size of the polygon.
    input >> size;
    for(int i = 0; i < size; ++i){
        input >> x >> y;
        vec.push_back( Point2D(x, y) );
    }
    return vec;
}

// Detail comments are in `.h` file!
VotingTree::VotingTree(std::vector<Point2D> & A, std::vector<Point2D> & B, MatchReferee & judger1, MatchReferee & judger2, int cll, double mr)
    :   pgA(A), 
        pgB(B), 
        votingTable(A.size(), B.size(), 0),
        judger1(judger1),
        judger2(judger2),
        credibleLowerLimit(cll > 3 ? cll : 3),
        mutationRatio(mr){}

// Detail comments are in `.h` file!
std::pair<double, bool> VotingTree::voteByDfs(CurStage & cur){
    double retVote = 0;
    bool retSuccess = false;
    auto curMatch = *(cur.curPath.end()-1);
    int iaCur = curMatch.first, ibCur = curMatch.second;
    // That is, if we want the current match to be the leaf node, we will check this.
    bool enoughPoints = ( cur.curPath.size() >= this->credibleLowerLimit );
    
    if(cur.curPath.size() >= 3){
         // The pgA and the newest point of pgA in current path.
        auto & curA = cur.curA;
        auto & pA = curA.getPointByIdx( cur.curA.getSize() - 1 );
        // The pgB and the newest point of pgB in current path.
        auto & curB = cur.curB;
        auto & pB = curB.getPointByIdx( cur.curB.getSize() - 1 );

        // Log.
        // std::cerr << "[" << __FILE__ << "/" << __LINE__ << "] : " <<  "Now dfs at :\n" << "id: " << pA.getMark() << ", pos: (" << pA.getX() << ", " << pA.getY() << ")" << std::endl <<  "id: " << pB.getMark() << ", pos: (" << pB.getX() << ", " << pB.getY() << ")" << std::endl;

        // Judge whether the point is matched.
        Point2D * Ap, * Am, * An, * Bp, * Bm, * Bn;

        // Judgement 1.
        // Where cur point is the end of the corner.
        An = &pA,
        Am = &curA.getPreByIdx( An->getMark() ),
        Ap = &curA.getPreByIdx( Am->getMark() );
        Bn = &pB,
        Bm = &curB.getPreByIdx( Bn->getMark() ),
        Bp = &curB.getPreByIdx( Bm->getMark() );

        bool isMatched1 = judger1.isMatch(
            *Ap, *Am, *An,
            *Bp, *Bm, *Bn
        );

        // Judgement 2.
        // Where cur point is the vertex of the corner.
        Am = &pA,
        An = &curA.getNextByIdx( An->getMark() ),
        Ap = &curA.getPreByIdx( Am->getMark() );
        Bm = &pB,
        Bn = &curB.getNextByIdx( Bn->getMark() ),
        Bp = &curB.getPreByIdx( Bm->getMark() );

        bool isMatched2 = judger2.isMatch(
            *Ap, *Am, *An,
            *Bp, *Bm, *Bn
        );
        
        if( isMatched1 && isMatched2 ){
            // Totally match, that means the current match is ok. That means we 
            // should add the vote to the table. But we still want to find deeper
            // match, so we should go on.
            retVote = judger1.getWeight() + judger2.getWeight();
            
            // Update the votes.
            votingTable[iaCur][ibCur] += retVote * retSuccess;
        } else if( isMatched1 || isMatched2 ){
            // Not totally match, so we won't let it go on. But it do has some good 
            // feature, so return but with vote.
            retVote = judger1.getWeight() * isMatched1 + judger2.getWeight() * isMatched2;
            retSuccess = enoughPoints;
            // Update the votes.
            votingTable[iaCur][ibCur] += retVote * retSuccess;
            return std::pair<double,bool>(retVote, enoughPoints);
        } else {
            // Not match.
            return std::pair<double,bool>(0, false);
        }
    }

    // The point is leagal, means we should search more deeper.
    // Here I iterate the following point, be carefull that the boundary of A and B
    // is different. We should iterate all the possible points in B but only points
    // that have not been the endpoint of the root node. So that we can have all the
    // situation.
    // Note that we can't use pA.getMark() or pB.getMark() here because it will get 
    // the index in curPolygon system, but we want to get the index in origin polygon
    // system.

    // iaLast is the index of the point got from cur path history. That is, the last
    // selected point in A. "last" is for the next point. "cur" is for the current 
    // stage.
    int & iaLast = iaCur;
    // iaStart is just the index of point after iaLast in a ring sequence (which means
    // the previous point of the head is the end).
    int iaStart = this->pgA.getNextByIdx(iaLast).getMark();
    // ibLast is the index of the point got from cur path history. That is, the last
    // selected point in B. "last" is for the next point. "cur" is for the current 
    // stage.
    int & ibLast = ibCur;
    // ibEldest is the index of the point got from cur path history. That is, the first
    // selected point in B.
    int ibEldest = cur.curPath.begin()->second;
    // ibStart is just the index of point after iaLast in a ring sequence (which means
    // the previous point of the head is the end).
    int ibStart = this->pgB.getNextByIdx(ibLast).getMark();
    // Now we should iterate all the possible situation.
    // Iterate all the possible ia, that is from the next of iaCur to the bigges index.
    for(int ia = iaStart; ia > iaLast; ia = pgA.getNextByIdx(ia).getMark()){
        // Iterate all the possible ib, that is from the next of ibCur to the previous
        // of the first ib.
        for(int ib = ibStart; ib != ibEldest; ib = pgB.getNextByIdx(ib).getMark()){
            cur.storeStage(this, ia, ib);
            auto response = this->voteByDfs(cur);
            double vote = response.first;
            double success = response.second;
            // The vote of (ia, ib) contribute to the vote of its father match, i.e. 
            // the current point.
            retVote += vote * success;
            // If one way succeed, that means the path will contribute.
            retSuccess = retSuccess || success;
            cur.recoverStage();
        }
    }

    if(retSuccess == 0){
        // No legal son node, so check if cur is legal leaf node or not.
        // Note that reVote will be overloaded because no leagl son node exsits.
        retVote = judger1.getWeight() + judger2.getWeight();
        retSuccess = enoughPoints;
    }

    votingTable[iaCur][ibCur] += retVote * retSuccess;
    return std::pair<double,bool>(retVote, retSuccess);
}

// Detail comments are in `.h` file!
void VotingTree::searchAndVote(){
    // Initialize the variable to be used.
    for(int ia = 0; ia < pgA.getSize(); ++ia){
        for(int ib = 0; ib < pgB.getSize(); ++ib){
            // Create a new current stage.
            CurStage cur;
            cur.storeStage(this, ia, ib);
            // Go deeper.
            this->voteByDfs(cur);
            // The CurStage object will be destructed so we needn't recover stage.
            // cur.recoverStage();
        }
    }
}

// Detail comments are in `.h` file!
Table2D VotingTree::getVotingTable(){
    return this->votingTable;
}

// // Detail comments are in `.h` file!
// void VotingTree::matchAccordingTalbe(){
//     // Reset the result space.
//     this->optimalMatch.clear();
//     // The vector to store the elements in talbe.
//     std::vector<MatchPair> vec;
//     // The set data structure to note whether the point is visited.
//     std::set<int> visA, visB;
//     // Set alias to make code briefly.
//     auto & vt = this->votingTable; 
//     auto shape = vt.getShape();
//     // Extract elements from the table.
//     for(int i = 0; i < shape.first; ++i){
//         for(int j = 0; j < shape.second; ++j){
//             MatchPair te = {i, j, vt[i][j]};
//             vec.push_back(te);
//         }
//     }
//     // The comparation rule is defined in the struct defination.
//     std::sort(vec.begin(), vec.end());
//     double ave = vec[0].ele + vec[ vec.size()-1 ].ele;
//     ave /= 2;
//     for(int i = 0; i < vec.size(); ++i){
//         if(vec[i].ele < ave) break;
//         auto cur = vec[i];
//         if(visA.find(cur.x) == visA.end() && visB.find(cur.y) == visB.end()){
//             visA.insert(cur.x), visB.insert(cur.y);
//             this->optimalMatch.push_back(std::pair<int,int>(cur.x+1, cur.y+1));
//         }
//     }
//     // Sort it in accressment order.
//     std::sort(optimalMatch.begin(), optimalMatch.end());
//     // this->checkOrderUsingLIS();
//     if(optimalMatch.size() < this->credibleLowerLimit) optimalMatch.clear();
//     return;
// }

// Detail comments are in `.h` file!
void VotingTree::matchAccordingTalbe(){
    // Reset the result space.
    this->optimalMatch.clear();
    auto & vt = this->votingTable; 
    auto shape = vt.getShape();
    double maxEle = -1e9+9, minEle = 1e9+9;
    // Extract elements from the table.
    for(int i = 0; i < shape.first; ++i){
        for(int j = 0; j < shape.second; ++j){
            maxEle = std::max(maxEle, vt[i][j]);
            minEle = std::min(minEle, vt[i][j]);
        }
    }
    // Find the optimal match.
    double ave = (maxEle + minEle) * 0.5;
    bool oneRound = false;

    std::vector< std::pair<int,int> > tmp;
    int tmpN = -1;
    // Iterate the bound, that is, where the second index will from n-1 to 0.
    // But actually, bound is the dividing line of the first index.
        // 'j' is not mutated yet.
    for(int bound = 0; bound < shape.first; ++bound){
        // J ~ last chosen j.
        // fJ ~ first chosen j, fI ~ first chosen i.
        int J = 0, fJ = -1, fI = -1;
        // Iterate i before the boud.
        // 'j' is not mutated yet.
        for(int i = bound; i < shape.first; ++i){
            for(int j = J; j < shape.second; ++j){
                if(vt[i][j] > ave){
                    J = j;
                    if(fJ == -1) fJ = j;
                    if(fI == -1) fI = i;
                    optimalMatch.push_back(std::pair<int,int>(i+1,j+1));
                    break;
                }
            }
        }
        // Iterate i after the boud.
        // 'j' is not mutated yet.
        for(int i = 0; i < bound; ++i){
            for(int j = J; j < shape.second; ++j){
                if(vt[i][j] > ave){
                    J = j;
                    if(fJ == -1) fJ = j;
                    if(fI == -1) fI = i;
                    optimalMatch.push_back(std::pair<int,int>(i+1,j+1));
                    break;
                }
            }
        }
        // Iterate i before the boud.
        // 'j' is not mutated already.
        for(int i = bound; i < std::min(shape.first, fI); ++i){
            for(int j = 0; j < fJ; ++j){
                if(vt[i][j] > ave){
                    J = j;
                    optimalMatch.push_back(std::pair<int,int>(i+1,j+1));
                    break;
                }
            }
        }
        // Iterate i after the boud.
        // 'j' is not mutated already.
        for(int i = 0; i < std::min(bound, fI); ++i){
            for(int j = J; j < fJ; ++j){
                if(vt[i][j] > ave){
                    J = j;
                    optimalMatch.push_back(std::pair<int,int>(i+1,j+1));
                    break;
                }
            }
        }
        // Memorize the better match.
        if(int(optimalMatch.size()) > tmpN){
            tmpN = optimalMatch.size();
            tmp = optimalMatch;
        }
        optimalMatch.clear();
    }
    if(tmpN > 0){
        optimalMatch = tmp;
    }
    return;
}

// Detail comments are in `.h` file!
void VotingTree::dealOptimalMatch(){
    // Search the matching programmes with dfs and initialize the voting table.
    this->searchAndVote();
    // Calculate the answer from the table.
    this->matchAccordingTalbe();
    return;
}

// Detail comments are in `.h` file!
std::vector< std::pair<int,int> > VotingTree::getOptimalMatch(){
    return this->optimalMatch;
}
```