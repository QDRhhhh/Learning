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