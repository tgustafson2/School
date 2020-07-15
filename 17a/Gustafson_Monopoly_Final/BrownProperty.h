/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BrownProperty.h
 * Author: tgust
 *
 * Created on May 29, 2019, 7:40 PM
 */

#ifndef BROWNPROPERTY_H
#define BROWNPROPERTY_H
#include "BoardLocation.h"

using namespace std;
class BrownProperty : public BoardLocation{
private:
    Status propstatus;
    int rent[7];
    int housenumber;
    int owner;
public:
    BrownProperty(string topname, string bottomname, int location, int rent[7]):
    BoardLocation(topname, bottomname, location){
        propstatus=Status.Unowned;
        housenumber=0;
        owner=0;
        for (int i; i<7; i++){
            this->rent[i]=rent[i];
        }
    }
    
    
};


#endif /* BROWNPROPERTY_H */

