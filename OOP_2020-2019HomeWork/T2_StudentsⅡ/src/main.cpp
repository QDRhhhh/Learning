/* 
 * 
 * FileName:  main.cpp
 * Auther:    Isshiki修
 * Summary:   The Entrance of the program.
 * 
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "studentsClass.h"

const int maxN = 1e6+9;

vector< Students > students;
map< string,map< string,float > > subjects;

void init(){
    students.clear();
    subjects.clear();
}

void readData(){
    ifstream infile;
    infile.open("studentsData.txt",ios::in);
    while(!infile.eof()){
        string name;
        infile >> name;
        
        // ignore empty line
        if(name.empty()) continue;

        string subjectsData;
        getline(infile,subjectsData);
        Students newStudent(name,subjectsData);
        students.push_back(newStudent);
    }
    infile.close();
}

void printData(){
    ofstream outfile;
    outfile.open("studentsList.txt",ios::out | ios::trunc);
    
    // head
    outfile << setiosflags(ios::left);
    outfile << setw(4) << "ID";
    outfile << setw(10) << "Name";
    for(map< string,map< string,float > >::iterator it = subjects.begin();it != subjects.end();++it){
        outfile << setw(10) <<  (*it).first;
    }
    outfile << setw(10) << "Average";
    outfile << endl;

    // body data
    for(int i = 0;i < students.size();++i){
        outfile << setw(4) << students[i].getID();
        outfile << setw(10) << students[i].getName();
        map<string,float> score = students[i].getScore();
        for(map< string,map<string,float> >::iterator it = subjects.begin();it != subjects.end();++it){
            if(score.find((*it).first) == score.end()){
                outfile << setw(10) << "-";
            } else {
                outfile.precision(2);
                outfile << setw(10) << score[(*it).first];
            }
        }
        outfile.precision(2);
        outfile << setw(10) << students[i].calAverage();
        outfile << endl;
    }

    // analysis
    outfile << setw(4) << " ";
    outfile << setw(10) << "Average";
    for(map< string,map< string,float > >::iterator it = subjects.begin();it != subjects.end();++it){
        outfile.precision(2);
        outfile << setw(10) <<  (*it).second["sum"]/(*it).second["tot"];
    }
    outfile << endl;
    outfile << setw(4) << " ";
    outfile << setw(10) << "Min";
    for(map< string,map< string,float > >::iterator it = subjects.begin();it != subjects.end();++it){
        outfile.precision(2);
        outfile << setw(10) <<  (*it).second["min"];
    }
    outfile << endl;
    outfile << setw(4) << " ";
    outfile << setw(10) << "Max";
    for(map< string,map< string,float > >::iterator it = subjects.begin();it != subjects.end();++it){
        outfile.precision(2);
        outfile << setw(10) <<  (*it).second["max"];
    }
    outfile << endl;
}

int main(){
    init();
    readData();
    printData();
    return 0;
}