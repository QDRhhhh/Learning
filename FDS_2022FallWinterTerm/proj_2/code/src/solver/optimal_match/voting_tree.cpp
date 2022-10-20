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
double VotingTree::calSuccessRate(int size, int lim){
    if(size < lim) return 0;
    //TODO: make it more reliable.
    return 1;
}

// Detail comments are in `.h` file!
VotingTree::VotingTree(std::vector<Point2D> & A, std::vector<Point2D> & B, MatchReferee & judger1, MatchReferee & judger2, int cll)
    :   pgA(A), 
        pgB(B), 
        votingTable(A.size(), B.size(), 0),
        judger1(judger1),
        judger2(judger2),
        credibleLowerLimit(cll){}

// Detail comments are in `.h` file!
std::pair<double, double> VotingTree::getVoteByDfs(){
    double retVote = 0;
    bool retSuccess = 0, isMatched1, isMatched2;
    
    if(this->cur.curPath.size() >= 3){
         // The pgA and the newest point of pgA in current path.
        auto & curA = this->cur.curA;
        auto & pA = curA.getPointByIdx( cur.curA.getSize() - 1 );
        // The pgB and the newest point of pgB in current path.
        auto & curB = this->cur.curB;
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

        isMatched1 = judger1.isMatch(
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

        isMatched2 = judger2.isMatch(
            *Ap, *Am, *An,
            *Bp, *Bm, *Bn
        );
        
        if( !(isMatched1 && isMatched2) ){
            // Not match, but may get vote from the success of one judger.
            retVote = judger1.getWeight() * isMatched1 + judger2.getWeight() * isMatched2;
            retSuccess = VotingTree::calSuccessRate( this->cur.curPath.size()-1, this->credibleLowerLimit );
            return std::make_pair(retVote, retSuccess);
        }
    } else {
        // Although it matchs, but that's because the points are two few. It shouldn't count.
        retVote = 0;
    }
    
    // The point is leagal, means we should search more deeper.
    // Here I iterate the following point, be carefull that the boundary of A and B
    // is different. We should iterate all the possible points in B but only points
    // that have not been the endpoint of the root node. So that we can have all the
    // situation.
    // Note that we can't use pA.getMark() or pB.getMark() here because it will get 
    // the index in curPolygon system, but we want to get the index in origin polygon
    // system.

    // ia_last is the index of the point got from cur path history. That is, the last
    // selected point in A.
    int ia_last = (this->cur.curPath.end()-1)->first;
    // ia_start is just the index of point after ia_last in a ring sequence (which means
    // the previous point of the head is the end).
    int ia_start = this->pgA.getNextByIdx(ia_last).getMark();
    // ib_last is the index of the point got from cur path history. That is, the last
    // selected point in B.
    int ib_last = (this->cur.curPath.end()-1)->second;
    // ib_start is just the index of point after ia_last in a ring sequence (which means
    // the previous point of the head is the end).
    int ib_start = this->pgB.getNextByIdx(ib_last).getMark();
    // Now we should iterate all the possible situation.
    for(int ia = ia_start; ia > ia_last; ia = pgA.getNextByIdx(ia).getMark()){
        for(int ib = ib_start; ib != ib_last; ib = pgB.getNextByIdx(ib).getMark()){
            cur.storeStage(this, ia, ib);
            auto response = this->getVoteByDfs();
            double vote = response.first;
            double success = response.second;
            // Chose the maximum. TODO: make it more reliable.
            retSuccess = retSuccess < success ? success : retSuccess;
            // The current match(ia, ib) gain the vote.
            votingTable[ia][ib] += vote * success;
            // The vote of (ia, ib) contribute to the vote of its father match.
            retVote += vote * success;
            cur.recoverStage();
        }
    }

    if(retSuccess == 0){
        retVote = judger1.getWeight() * isMatched1 + judger2.getWeight() * isMatched2;
        retSuccess = VotingTree::calSuccessRate( this->cur.curPath.size(), this->credibleLowerLimit );
    }
    return std::make_pair(retVote, retSuccess);
}

// Detail comments are in `.h` file!
void VotingTree::searchAndVote(){
    // Initialize the variable to be used.
    cur.reset();
    for(int ia = 0; ia < pgA.getSize(); ++ia){
        for(int ib = 0; ib < pgB.getSize(); ++ib){
            cur.storeStage(this, ia, ib);
            auto response = this->getVoteByDfs();
            double vote = response.first;
            double success = response.second;
            votingTable[ia][ib] += vote * success;
            cur.recoverStage();
        }
    }
}

// Detail comments are in `.h` file!
Table2D VotingTree::getVotingTable(){
    return this->votingTable;
}

// Detail comments are in `.h` file!
void VotingTree::matchAccordingTalbe(){
    optimalMatch.resize(0);

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