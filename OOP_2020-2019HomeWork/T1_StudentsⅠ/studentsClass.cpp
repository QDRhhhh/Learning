#include "studentsClass.h"

Students::Students(int ID,string name,vector<float> score){
    this->ID = ID;
    this->name = name;
    this->score.assign(score.begin(),score.end());
}

float Students::calSum(){
    float sum = 0;
    for(int i = 0;i < score.size();++i){
        sum += score[i];
    }
    return sum;
}

float Students::calAverage(){
    return calSum() / score.size();
}

int Students::getID(){
    return ID;
}

string Students::getName(){
    return name;
}

float Students::getScore(int index){
    return score[index];
}