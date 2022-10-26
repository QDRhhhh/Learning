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