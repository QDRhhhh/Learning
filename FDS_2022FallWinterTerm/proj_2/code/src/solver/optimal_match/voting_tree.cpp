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

// Detail comments are in `.h` file!
void VotingTree::matchAccordingTalbe(){
    // Reset the result space.
    this->optimalMatch.clear();
    // The vector to store the elements in talbe.
    std::vector<MatchPair> vec;
    // The set data structure to note whether the point is visited.
    std::set<int> visA, visB;
    // Set alias to make code briefly.
    auto & vt = this->votingTable; 
    auto shape = vt.getShape();
    // Extract elements from the table.
    for(int i = 0; i < shape.first; ++i){
        for(int j = 0; j < shape.second; ++j){
            MatchPair te = {i, j, vt[i][j]};
            vec.push_back(te);
        }
    }
    // The comparation rule is defined in the struct defination.
    std::sort(vec.begin(), vec.end());
    // First we should deal with the points we don't want to count. We will try
    // to find the smallest crow of point and note them useless.
    // We use cutPoint to note from where we won't use. If it is -1, that means
    // we don't find a obvious cutPoint.
    int cutPoint = -1;
    for(int i = vec.size()-1-1; i >= 0+1; --i){
        auto cur = vec[i].ele, smaller = vec[i+1].ele, bigger = vec[i-1].ele;
        // (bigger - cur) / (cur - smaller) > this->mutationRatio, but without Div 0.
        if((bigger - cur) > this->mutationRatio * (cur - smaller) ){
            cutPoint = i;
            break;
        }
    }
    // Add point.
    for(int i = 0; i < cutPoint; ++i){
        auto cur = vec[i];
        if(visA.find(cur.x) == visA.end() && visB.find(cur.y) == visB.end()){
            visA.insert(cur.x), visB.insert(cur.y);
            this->optimalMatch.push_back(std::pair<int,int>(cur.x+1, cur.y+1));
        }
    }
    // Sort it in accressment order.
    std::sort(optimalMatch.begin(), optimalMatch.end());
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