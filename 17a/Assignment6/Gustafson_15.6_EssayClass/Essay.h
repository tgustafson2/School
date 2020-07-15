/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Essay.h
 * Author: tgust
 *
 * Created on May 17, 2019, 7:57 PM
 */

#ifndef ESSAY_H
#define ESSAY_H
#include "GradedActivity.h"

using namespace std;

class Essay: public GradedActivity {
private:
    double grammar;
    double spelling;
    double length;
    double content;
public:
    Essay(double gram, double spell, double len, double con){
        grammar=gram;
        spelling=spell;
        length=len;
        content=con;
        double total= gram+spell+len+con;
        setScore(total);
    }
    void setGram(double gram){
        grammar=gram;
    }
    void setSpell(double spell){
        spelling=spell;
    }
    void setLength(double len){
        length=len;
    }
    void setCon(double con){
        content=con;
    }
};



#endif /* ESSAY_H */

