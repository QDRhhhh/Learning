#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

#include "../../utils/random_vector2d_generator.h"

#define LIM_L -1024.0
#define LIM_R 1024.0
#define STEP_LIM 10.0
#define MOVEMENT 1024

RandomVector2DGenerator rvg(STEP_LIM);

bool isLegal(pair<double,double> pt){
    return (LIM_L <= pt.first && pt.first <= LIM_R)
        && (LIM_L <= pt.second && pt.second <= LIM_R);
}

vector< pair<double,double> > drawOriPg(int n){

    vector< pair<double,double> > ret;
    
    ret.push_back( rvg.randVec() );

    for(int i = 1; i < n; ++i){
        auto & lastPt = *(ret.end()-1);
        auto newPt = rvg.randMove(lastPt);
        if(isLegal(newPt)){
            ret.push_back( newPt );
        } else {
            --i;
        }
    }

    return ret;
}

vector< pair<double,double> > transformPg(vector< pair<double,double> > ori, int offset){
    double m11 = (rand()%4000 - 2000.0)/1000.0; // [-2.0 ~ 2.0]
    double m12 = (rand()%4000 - 2000.0)/1000.0; // [-2.0 ~ 2.0]
    double m21 = (rand()%4000 - 2000.0)/1000.0; // [-2.0 ~ 2.0]
    double m22 = (rand()%4000 - 2000.0)/1000.0; // [-2.0 ~ 2.0]
    // define the transformition
    //      m11  m12  Dot x   =   x*m11+y*m12
    //      m21  m22  Mul y   =   x*m21+y*m22
    //
    for(auto it = ori.begin(); it != ori.end(); ++it){
        auto & x = it->first, & y = it->second;
        auto tx = x*m11+y*m12;
        auto ty = x*m21+y*m22;
        x = tx, y = ty;
    }
    vector< pair<double,double> > ret(ori.size());
    
    for(int i = 0; i < ori.size(); ++i){
        ret[ i ] = ori[ (i+offset)%ori.size() ];
    }

    return ret;
}

int main(int argc, char * argv[]){
    srand((unsigned)time(NULL));

    int t = 5, m = 4, n = 4;
    if(argc == 4){
        t = atoi(argv[1]);
        m = atoi(argv[2]);
        n = m;
    }
    
    int offset = rand()%m;
    auto oriPg = drawOriPg(m);
    auto newPg = transformPg(oriPg, offset);

    ofstream of_in, of_info;
    of_in.open("test_data.in",ios::out | ios::trunc);
    of_info.open("test_data.info",ios::out | ios::trunc);

    of_in << t << endl;
    of_info << t << endl;
    for(int i = 0; i < t; ++i){
        of_in << m << endl;
        for(auto it = oriPg.begin(); it != oriPg.end(); ++it){
            of_in << it->first << " " << it->second << endl;
        }

        of_in << n << endl;
        for(auto it = newPg.begin(); it != newPg.end(); ++it){
            of_in << it->first << " " << it->second << endl;
        }
    }

    for(int i = 0; i < m; ++i){
        of_info << i+1 << " " << ((i+offset)%m)+1 << endl;
    }
}