/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Railroad.h
 * Author: tgust
 *
 * Created on May 29, 2019, 7:42 PM
 */

#ifndef RAILROAD_H
#define RAILROAD_H
#include "BoardLocation.h"
using namespace std;
class Railroad:public BoardLocation{
private:
    int rent;
    int multiplier;
public:
    Railroad(string topname, string bottomname, int location):
    BoardLocation(topname, bottomname, location){
        rent=25;
        multiplier=1;
    }
};


#endif /* RAILROAD_H */

