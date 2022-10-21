#include <iomanip>
#include <iostream>

#include "optimal_match/voting_tree.h"

#define WIDTH 8

void printResult(std::vector< std::pair<int,int> > & res){
    for(auto it = res.begin(); it != res.end(); ++it){
        std::cout << std::setw(WIDTH) << it->first << std::setw(WIDTH) << it->second << std::endl;
    }
}

void solve(){
    MatchReferee judger1(0.1, 0.1, 1.0);
    MatchReferee judger2(0.1, 0.1, 1.0);
    auto inA = VotingTree::readPts(std::cin);
    auto inB = VotingTree::readPts(std::cin);
    VotingTree vTree(inA, inB, judger1, judger2, 3);

    vTree.searchAndVote();
    auto vTable = vTree.getVotingTable();
    for(auto i = 0; i < vTable.getShape().first; ++i){
        for(auto j = 0; j < vTable.getShape().second; ++j){
            std::cout << std::setw(WIDTH) << vTable[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // vTree.dealOptimalMatch();
    // auto result = vTree.getOptimalMatch();
    // printResult(result);
}

int main(){
    std::ios::sync_with_stdio(false);
    int _;
    std::cin >> _;
    while (_--){
        solve();
    }
    return 0;
}