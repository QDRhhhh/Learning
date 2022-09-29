#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

#define MAX 1024

int main(int argc, char * argv[]){
    srand((unsigned)time(NULL)); 
    int n = 4, m = 4;
    if(argc == 3){
        n = atoi(argv[1]);
        m = atoi(argv[2]);
    }
    ofstream of;
    of.open("test_data.txt",ios::out | ios::trunc);
    int cnt = n <= 50 ? 100 : 10;
    of << cnt << "\n";
    for(int cc = 0; cc < cnt; ++cc){
        of << n << " " << m << "\n"; 
        for(int i = 1; i <= n; ++i){
            for(int j = 1;j <= m;++j){
                of << rand()%MAX - MAX/2 << " ";
            }
        of << "\n";
        }   
    }
    
}