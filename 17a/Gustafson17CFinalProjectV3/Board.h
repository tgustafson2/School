/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.h
 * Author: tgust
 *
 * Created on October 12, 2019, 3:36 PM
 */

#ifndef BOARD_H
#define BOARD_H
#include <map>
#include <iterator>
#include <utility>
#include <string>

using namespace std;
class Board{
private:
    map <int, string> board;
    
    //use map for board
public:
    Board();
    ~Board(){
        //delete board;
    }
    //set all strings to empty in constructor
    //setstring function
    void setString(int, string);
    //getoccupied function
    bool getOccup(int);
    //printboard
    void printboard();
    
};

#endif /* BOARD_H */

