/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: tgust
 *
 * Created on May 29, 2019, 11:14 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;
enum PlayerStatus{active, bankrupt, injail};
class Player{
private:
    string name;
    int number;
    int location;
    int account;
    PlayerStatus currentstat;
    
};



#endif /* PLAYER_H */

