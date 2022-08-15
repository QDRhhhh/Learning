/* 
 * 
 * FileName:  main.cpp
 * Auther:    Isshiki修
 * Summary:   The Entrance of the program.
 * 
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include "studentsClass.h"

using std::string;using std::vector;
using namespace std;

vector<Students> studentsList;

float _min(float x,float y){
    return x < y ? x : y;
}

float _max(float x,float y){
    return x > y ? x : y;
}

void readData(){
    string name;
    vector<float> score;
    float newScore;
    for(int i = 1;i <= 10;++i){
        score.clear();
        cin >> name;
        for(int j = 0;j < 3;++j){
            cin >> newScore;
            score.push_back(newScore);
        }
        Students newStudents(i,name,score);
        studentsList.push_back(newStudents);
    }
}

void printData(){
    float sum[3] = {};
    float min[3] = {10,10,10};
    float max[3] = {};

    cout << setiosflags(ios::left);
    cout << setw(8) << "no";
    cout << setw(8) << "name";
    cout << setw(8) << "score1";
    cout << setw(8) << "score2";
    cout << setw(8) << "score3";
    cout << setw(8) << "average";
    cout << endl;

    for(int i = 0;i < studentsList.size();++i){
        Students s = studentsList[i];
       cout << setw(8) << s.getID();
       cout << setw(8) << s.getName();
        for(int j = 0;j < 3;++j){
            cout << setw(8) << s.getScore(j);
            sum[j] += s.getScore(j);
            min[j] = _min(min[j],s.getScore(j));
            max[j] = _max(min[j],s.getScore(j));
        }
        cout << setw(8) << s.calAverage();
        cout << endl;
    }

    cout << setw(8) << " ";
    cout << setw(8) << "average";
    for(int j = 0;j < 3;++j){
        cout << setw(8) << sum[j]/10;
    }
    cout << endl;

    cout << setw(8) << " ";
    cout << setw(8) << "min";
    for(int j = 0;j < 3;++j){
        cout << setw(8) << min[j];
    }

    cout << endl;
    cout << setw(8) << " ";
    cout << setw(8) << "max";
    for(int j = 0;j < 3;++j){
        cout << setw(8) << max[j];
    }
    cout << endl;
}

int main(){
    freopen("studentData.txt","r",stdin);
    freopen("studentList.txt","w",stdout);
    
    readData();
    
    printData();
}