/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: tgust
 *
 * Created on October 12, 2019, 3:36 PM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Board.h"
#include "List.h"
#include <set>

class Player{
private:
    //board
    Board *board;
    bool active;
    string name;
    int pieces;
    int moves;
    int V=5;
    List<int> *ships;
    int graph[5][5];
    //set pieces
    //active status
public:
    Player();
    //constructor call board, then prompt input for ships positions, use lists for ships
    //check status
    ~Player(){
        delete board;
    }
    bool getStatus();
    void setStatus(bool);
    void addMove();
    int getMove();
    //getboard location
    bool getOccu(int,int);
    //setboard string
    void setBoard(int,int, string);
    //printboard function
    void printBoard();
    string getName(){
        return name;
    }
    int getPieces(){
        return pieces;
    }
    int minKey(int key[], bool mstSet[]);
void primMST(int [5][5]) ;
void printMST(int [], int [5][5]) ;
void callMST(){
    primMST(graph);
}
    
};


#endif /* PLAYER_H */

