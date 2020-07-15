/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BaseGame.h
 * Author: tgust
 *
 * Created on June 3, 2019, 9:39 PM
 */

#ifndef BASEGAME_H
#define BASEGAME_H

#include "Player.h"



using namespace std;
//ostream &operator << (ostream &, const BaseGame &);
enum Axislab{
    A,B,C,D,E,F,G,H,I,J};
class BaseGame{
protected:
    Player **players;
    int startingplayers;
    int playercount;
    
    static Axislab conv(char);
public:
    BaseGame(int playernum){
        players= new Player*[playernum];
        for (int i=0;i<playernum; i++){
            players[i]= new Player();
        }
        startingplayers=playernum;
        playercount=playernum;
    }
    ~BaseGame(){
        for (int i=0; i<startingplayers; i++){delete players[i];}
        delete []players;
    }
    /*void setOccupied(){
        players->setOccupied();
    }*/
    int getOccupied(int p, int i, int j)const{
        //return players[p].getOccupied(i,j);
        return players[p]->getOccupied(i,j);
    }
    void setMark(int p, string mark, int i, int j){
        //players[p].setMark(mark, i, j);
        players[p]->setMark(mark, i, j);
    }
    string getMark(int p, int i, int j)const{
        //return players[p].getMark(i,j);
        return players[p]->getMark(i,j);
    }
    void setActive(int p, bool active){
        //players[p].setActive(active);
        players[p]->setActive(active);
    }
    bool getActive(int p)const{
        //return players[p].getActive();
        return players[p]->getActive();
    }
    /*void setPlayercount(int p, int playernum){
        //players[p].setPlayercount(playernum);
        //players[p]->setPlayercount(playernum);
        playercount+=playernum;
    }*/
    int getPlayercount(){
        return playercount;
    }
    string getName(int i)const{
        //return players[i].getName();
        if (i>startingplayers-1){
            return "";
        }
        else
        return players[i]->getName();
    }
    /*int getPlayercount1(){
        return playercount;
    }
    string getName1(int i){
        //return players[i].getName();
        if (i>startingplayers-1){
            return "";
        }
        else
        return players[i]->getName();
    }*/
    int getStartingplayer()const{
        return startingplayers;
    }
    bool attack(string , char , int);
    friend ostream &operator << (ostream &, const BaseGame &);
    friend void Player::setOccupied();
};


#endif /* BASEGAME_H */

