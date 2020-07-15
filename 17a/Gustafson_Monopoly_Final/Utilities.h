/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Utilities.h
 * Author: tgust
 *
 * Created on May 29, 2019, 7:45 PM
 */

#ifndef UTILITIES_H
#define UTILITIES_H
#include "BoardLocation.h"
using namespace std;
class Utilities:public BoardLocation{
private:
    int rent;
    int multiplier;
public:
    Utilities(string topname, string bottomname, int location, int rent):
    BoardLocation(topname, bottomname, location){
        this->rent=rent;
        multiplier=4;
    }
};


#endif /* UTILITIES_H */

