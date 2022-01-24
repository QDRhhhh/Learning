/* 
 *
 * FileName:  studentsClass.cpp
 * Auther:    Isshiki修
 * Summary:   The defination of the class "Students".
 * 
 */
#include "studentsClass.h"

Students::Students(const Students &r){
    this->ID = r.ID;
    this->name = r.name;
    this->score = r.score;
}

Students::Students(string name,string subjectsData){
    static int ID = 0;
    ++ID;
    this->ID = ID;
    this->name = name;
    this->score.clear();

    extern map< string,map< string,float > > subjects;
    string sName;
    float sScore;

    // change string to istream
    stringstream tmp;
    tmp << subjectsData;
    while(!tmp.eof()){
        tmp >> sName >> sScore;
        
        // break while no subject data
        if(sName.empty()) break;

        if(subjects.find(sName) == subjects.end()){
            subjects[sName]["sum"] = sScore;
            subjects[sName]["max"] = sScore;
            subjects[sName]["min"] = sScore;
            subjects[sName]["tot"] = 1;
        } else {
            subjects[sName]["sum"] += sScore;
            subjects[sName]["tot"] += 1;
            if(subjects[sName]["max"] < sScore) subjects[sName]["max"] = sScore;
            if(subjects[sName]["min"] > sScore) subjects[sName]["min"] = sScore;
        }
        score[ sName ] = sScore;
    }
}

float Students::calSum(){
    float sum = 0;
    for(map<string,float>::iterator it = score.begin();it != score.end();++it){
        sum += (*it).second;
    }
    return sum;
}

float Students::calAverage(){
    if(score.size() == 0){
        return 0;
    } else {
        return calSum() / score.size();
    }
}

int Students::getID(){
    return ID;
}

string Students::getName(){
    return name;
}

map<string,float> Students::getScore(){
    return score;
}