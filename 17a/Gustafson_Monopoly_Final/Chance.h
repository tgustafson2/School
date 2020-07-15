/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Chance.h
 * Author: tgust
 *
 * Created on May 29, 2019, 7:45 PM
 */

#ifndef CHANCE_H
#define CHANCE_H
#include "BoardLocation.h"
using namespace std;
class Chance: public BoardLocation{
private:
    int cards=16;
    
public:
    Chance(string topname, string bottomname, int location):
    BoardLocation(topname, bottomname, location){
        
    }
};

#endif /* CHANCE_H */

