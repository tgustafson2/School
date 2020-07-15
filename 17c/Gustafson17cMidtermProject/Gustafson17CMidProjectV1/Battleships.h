/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Battleships.h
 * Author: tgust
 *
 * Created on October 12, 2019, 3:36 PM
 */

#ifndef BATTLESHIPS_H
#define BATTLESHIPS_H
#include "List.h"
#include "Player.h"
#include <utility>

class Battleships{
private:
    Player **players;
    //List<int> *ships;
    bool game;
public:
    Battleships();
    ~Battleships(){
        //ships->~List();
        delete players;
    }
    //constructor call players objectaray
    //game alternate until one player is no longer active, display winner name
    pair<int,string> Playgame();
    void attack(int, int, int);
    void timedMode();
    
};


#endif /* BATTLESHIPS_H */

