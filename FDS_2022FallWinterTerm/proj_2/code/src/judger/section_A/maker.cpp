#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "../../lib/meta_data.h"

using namespace std;

Polygon2D randPg(int size){
    
}


Polygon2D rigidTransPg(Polygon2D & base, int offset){

}

int main(int argc, char * argv[]){
    srand((unsigned)time(NULL));

    ofstream ofIn, ofInfo;
    ofIn.open("test_data.in",ios::out | ios::trunc);
    ofInfo.open("test_data.info",ios::out | ios::trunc);
    
    vector<int> sizeSeq;
    sizeSeq.push_back(3);
    sizeSeq.push_back(5);
    sizeSeq.push_back(10);
    sizeSeq.push_back(50);
    sizeSeq.push_back(100);

    ofIn << sizeSeq.size() << endl;
    ofInfo << sizeSeq.size() << endl;
    
    for(auto it = sizeSeq.begin(); it != sizeSeq.end(); ++it){
        auto pgA = randPg(*it);
        int offset = rand() % pgA.getSize();
        auto pgB = rigidTransPg(pgA, offset);

        ofIn << pgA.getSize() << endl;
        for(int i = 0; i < pgA.getSize(); ++i){
            auto & pt = pgA.getPointByIdx(i);
            ofIn << pt.getX() << " " << pt.getY() << endl;
        }
        ofIn << pgB.getSize() << endl;
        for(int i = 0; i < pgB.getSize(); ++i){
            auto & pt = pgB.getPointByIdx(i);
            ofIn << pt.getX() << " " << pt.getY() << endl;
        }

        ofInfo << *it << endl;
        for(int i = 0; i < *it; ++i){
            ofInfo << i << " " << (i+offset) % (*it) << endl;
        }
    }


}