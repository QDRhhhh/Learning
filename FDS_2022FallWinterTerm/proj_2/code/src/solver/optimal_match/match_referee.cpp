#include "match_referee.h"


// Detail comments are in `.h` file!
MatchReferee::MatchReferee(double at, double ert, double weight)
    :   angleTolerance(at), 
        edgeRatioTolerance(ert),
        weight(weight){}

// Detail comments are in `.h` file!
double MatchReferee::getWeight(){
    return this->weight;
}

// Detail comments are in `.h` file!
bool MatchReferee::isMatch(Point2D &Ap, Point2D &Am, Point2D &An, Point2D &Bp, Point2D &Bm, Point2D &Bn){
    
    // p ~ pre, m ~ main, n ~ next, o ~ opposite
    double lineAp, lineAn, lineAo,lineBp, lineBn, lineBo;
    double angleA, angleB;
    lineAp = Am.getDis(Ap);
    lineAn = Am.getDis(An);
    lineAo = Ap.getDis(An);
    // Use law of cosines to calculate the angle.
    angleA = acos(
        (lineAp * lineAp + lineAn * lineAn - lineAo * lineAo) / (2 * lineAp * lineAn)
    );

    lineBp = Bm.getDis(Bp);
    lineBn = Bm.getDis(Bn);
    lineBo = Bp.getDis(Bn);
    // Use law of cosines to calculate the angle.
    angleB = acos(
        (lineBp * lineBp + lineBn * lineBn - lineBo * lineBo) / (2 * lineBp * lineBn)
    );

    // Retrun true only when angle and the edge ratio both fits the tolerance.
    return  (abs(angleA - angleB) <= this->angleTolerance) &&
            (abs(lineAp/lineAn - lineBp/lineBn) <= this->edgeRatioTolerance);
}

