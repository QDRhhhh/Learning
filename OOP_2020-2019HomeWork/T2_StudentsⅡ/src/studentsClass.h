/* 
 *
 * FileName:  studentsClass.h
 * Auther:    Isshiki修
 * Summary:   The declaration of the class "Students".
 * 
 */ 
#ifndef __STUDENTS__
#define __STUDENTS__

#include <map>
#include <sstream>
#include <iomanip>
using namespace std;

class Students{
private:
    int                ID;
    string             name;
    map<string,float>  score;
public:
    Students(){}
    explicit Students(const Students &r);
    Students(string name,string subjectsData);
    float calSum();
    float calAverage();
    int getID();
    string getName();
    map<string,float> getScore();
};

#endif