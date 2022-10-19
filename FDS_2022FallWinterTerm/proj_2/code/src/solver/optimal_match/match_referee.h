#ifndef __MATCH_REFEREE__
#define __MATCH_REFEREE__

// Head files.
#include <cmath>
#include "../utils/CNewbieHelper.h"
#include "meta_data.h"

/* 
 * <[ Class Defination ]>
 * [ Class Name ]:
 * - MatchReferee
 * [ Description ]: 
 * - The class defines a judement system for optimal match.
 * [ Usage ]:
 * - You should first set the relevant params before use. Then pass in the 
 * - "Point2D" objects, the relevant function will return the match result.
 * [ Index ]:
 * - C'tor & D'tor
 * - isMatch()
 * [ Remarks ]:
 * - You are not supposed to use the default C'tor and I had made it private. 
 */
class MatchReferee{
private:
    double AngleTolerance;
    double EdgeRatioTolerance;

public:
    MatchReferee() = delete; // Hiden.
    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - C'tor
     * [ Belonging Class ]:
     * - MatchReferee
     * [ Description ]:
     * - To initialize the points object.
     * [ Usage ]:
     * - "MatchReferee p(0.1, 0.2);" initialize the referee with
     * - AngleTolerance = 0.1 and EdgeRatioTolerance = 0.2.
     */
    MatchReferee(double, double);
    ~MatchReferee() = default;

    // Functional Methods

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - MatchReferee::isMatch()
     * [ Belonging Class ]:
     * - MatchReferee
     * [ Description ]:
     * - To judge whether the angle with edge can match.
     * [ Usage ]:
     * - "mr.isMatch(U, V, W, X, Y, Z);" gets a boolen value 
     * - represents whether the △UVW are approximately similar 
     * - with △XYZ.
     */
    bool isMatch(Point2D &, Point2D &, Point2D &, Point2D &, Point2D &, Point2D &);

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - MatchReferee::setUsed()
     * [ Belonging Class ]:
     * - MatchReferee
     * [ Description ]:
     * - To mark the Point2D is used.
     * [ Usage ]:
     * - "mr.setUsed(p);" marks that p is used.
     */
    void setUsed(Point2D &);

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - MatchReferee::isUsed()
     * [ Belonging Class ]:
     * - MatchReferee
     * [ Description ]:
     * - To judge whether the Point2D is used.
     * [ Usage ]:
     * - "mr.isUsed(p);" gets a boolen value represents whether
     * - the point is used.
     */
    bool isUsed(Point2D &);

};

#endif