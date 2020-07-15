/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: tgust
 *
 * Created on June 3, 2019, 8:12 PM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Board.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

class Player{
private:

    static int playercount;
    static int startingplayers;
    string name;
    int pieces;
    bool active;
    Board map;
public:
    Player(){
        cout<<"Enter player's name";
        cin.clear();
        getline(cin, name);
        pieces=17;
        active=true; 
        setOccupied();

    }
    Player (int players){
        playercount=players;
        startingplayers=0;
        cout<<"Enter player's name";
        
        getline(cin, name);
        pieces=17;
        active=true; 
        setOccupied();
    }
    ~Player(){
        
        map.~Board();
    }
    //in cpp file
    void setOccupied();
    void subtractPieces(int i){
        pieces-=i;
    }
    int getPieces() const{
        return pieces;
    }
    int getOccupied (int i, int j)const{
        return map.getOccupied(i,j);
    }
    void setMark(string mark, int i, int j){
        map.setMark(mark, i, j);
    }
    string getMark (int i, int j)const{
        return map.getMark(i,j);
    }
    void setActive(bool active){
        this->active=active;
    }
    bool getActive()const{
        return active;
    }
    string getName()const{
        return name;
    }
    static void setPlayercount(int playernum){
        playercount+=playernum;
    }
    static void setStartingPlayers(int playernum){
        startingplayers=playernum;
    }
    static int getStartingPlayers(){
        return startingplayers;
    }
    static int getPlayercount(){
        return playercount;
    }

};

#endif /* PLAYER_H */

