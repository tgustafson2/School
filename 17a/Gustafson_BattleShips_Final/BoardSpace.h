/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BoardSpace.h
 * Author: tgust
 *
 * Created on June 3, 2019, 7:59 PM
 */

#ifndef BOARDSPACE_H
#define BOARDSPACE_H
#include <iostream>
#include <fstream>

using namespace std;

class BoardSpace{
private:
    string mark;
    bool occupied;
public:
    BoardSpace(){
        mark="empty";
        occupied=false;
    }
    void setOccupied(){
        occupied=true;
    }
    void setMark(string mark){
        this->mark=mark;
    }
    bool getOccupied()const{
        return occupied;
    }
    string getMark()const{
        return mark;
    }
};

#endif /* BOARDSPACE_H */

