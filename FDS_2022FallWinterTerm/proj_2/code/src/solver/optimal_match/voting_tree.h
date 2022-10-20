#ifndef __VOTING_TREE__
#define __VOTING_TREE__

// Head file.
#include <vector>
#include <iostream>
#include "meta_data.h"
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
     * - CurStage::store()
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
     * - "cur.store(1, 2)" will store the pA[1] and pB[2] to the stage.
     */
    void store(VotingTree *, int, int);

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - CurStage::recover()
     * [ Belonging Class ]:
     * - CurStage
     * [ Description ]:
     * - It will recover the current stage.
     * - [ Params Description ]:
     * - - No params.
     * - [ Return Description ]:
     * - - No params.
     * [ Usage ]:
     * - "cur.recover()" will do the things above.
     */
    void recover();

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
private: 

    Polygon2D pgA, pgB;
    Table2D votingTable;
    MatchReferee &judger1;
    MatchReferee &judger2;
    std::vector< std::pair<int,int> > optimalMatch;
    CurStage cur;

    /* 
     * <[ Class Methods Defination ]>
     * [ Method Name ]:
     * - VotingTree::getVoteByDfs()
     * [ Belonging Class ]:
     * - VotingTree
     * [ Description ]:
     * - It will dfs the possible matching and get the sum of vote of each match.
     * - [ Params Description ]:
     * - - No params.
     * - [ Return Description ]:
     * - - (double) // The vote of the current match.
     * [ Usage ]:
     * - "vt.getVoteByDfs()" will dfs and get the vote of current match (also the son of the match).
     */
    double getVoteByDfs();

public:
    
    /* 
     * <[ Class Static Methods Defination ]>
     * [ Method Name ]:
     * - VotingTree::readPts()
     * [ Belonging Class ]:
     * - VotingTree
     * [ Description ]:
     * - To get the input data from istream.
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
     * - "VotingTree vt(A, B);" defines a voting tree solve the situation with 
     * - graph with the corner points stored in (vector<Point2D>)pts.
     */
    VotingTree(std::vector<Point2D> &, std::vector<Point2D> &, MatchReferee &, MatchReferee &);

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