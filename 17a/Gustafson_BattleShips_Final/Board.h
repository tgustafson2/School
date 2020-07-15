/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.h
 * Author: tgust
 *
 * Created on June 3, 2019, 7:57 PM
 */

#ifndef BOARD_H
#define BOARD_H
#include "BoardSpace.h"
#include <iostream>
#include <fstream>

using namespace std;

class Board{
private:
    BoardSpace ***location;
public:
    Board();
    ~Board();
    void setOccupied(int i, int j){
        location[i][j]->setOccupied();
    }
    void setMark(string mark, int i, int j){
        location[i][j]->setMark(mark);
    }
    bool getOccupied(int i, int j) const{
        return location[i][j]->getOccupied();
    }
    string getMark(int i, int j) const{
        return location[i][j]->getMark();
    }
};


#endif /* BOARD_H */

