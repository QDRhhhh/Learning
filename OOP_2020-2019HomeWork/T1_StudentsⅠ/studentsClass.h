/* 
 *
 * FileName:  studentsClass.h
 * Auther:    Isshiki修
 * Summary:   The declaration of the class "Students".
 * 
 */
#ifndef __STUDENTS__
#define __STUDENTS__
#include <string>
#include <vector>
using std::string;using std::vector;

class Students{
private:
    int             ID;
    string          name;
    vector<float>  score;
public:
    Students(){}
    Students(int ID,string name,vector<float> score);
    float calSum();
    float calAverage();
    int getID();
    string getName();
    float getScore(int index);
};

#endif