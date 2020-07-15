/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CommunityChest.h
 * Author: tgust
 *
 * Created on May 29, 2019, 7:44 PM
 */

#ifndef COMMUNITYCHEST_H
#define COMMUNITYCHEST_H
#include "BoardLocation.h"
using namespace std;
class CommunityChest:public BoardLocation{
    private:
    int cards=16;
    
public:
    CommunityChest(string topname, string bottomname, int location):
    BoardLocation(topname, bottomname, location){
        
    }
};


#endif /* COMMUNITYCHEST_H */

