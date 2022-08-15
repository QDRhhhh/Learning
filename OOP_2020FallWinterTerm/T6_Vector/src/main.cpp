#include <iostream>

#include "Vector.h"

using namespace std;

template <typename T>
void testPrint_R(T &x){
    static int id = 0;
    cout << "[RR] Print Begin!\n";
    cout << "ID : " << (++id) << '\n';

    cout << "Size : " << x.size() << "\n";
    cout << "Elements are : \n";
    for(int i = 0;i < x.size();++i){
        cout << "   ( #" << i << " ) : " << x[i] << "\n";
    }

    cout << "[==] Print Finish!\n";
}


template <typename T>
void testPrint(T x){
    static int id = 0;
    cout << "[NN] Print Begin!\n";
    cout << "ID : " << (++id) << '\n';

    cout << "Size : " << x.size() << "\n";
    cout << "Elements are : \n";

    for(int i = 0;i < x.size();++i){
        cout << "   ( #" << i << " ) : " << x[i] << "\n";
    }

    cout << "[==] Print Finish!\n";
}


int main(){
    cout << "[::] create a Vector<int>[16]\n";
    Vector<int> v(16);
    cout << "[::] Success\n";

    testPrint(v);
    testPrint_R(v);
    for(int i = 0;i < 16;++i) v.push_back(i);
    testPrint_R(v);
    for(int i = 16;i < 24;++i) v.push_back(i);
    testPrint_R(v);

    try{
        v.at(33);
    } catch( std::out_of_range ){
        cout << "ok fine\n";
    }
}