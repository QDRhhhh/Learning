#include "meta_data.h"

/*
 * <[ Class Methods Implementations ]>
 * [ Class Name ]:
 * - Point2D
 */

// Detail comments are in `.h` file!
Point2D::Point2D(double x, double y): x(x), y(y), isMarked(false){}

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
TableSlice Table2D::operator[](int idx){
    return TableSlice(this, idx);
}
