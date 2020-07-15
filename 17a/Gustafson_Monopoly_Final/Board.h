/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.h
 * Author: tgust
 *
 * Created on May 29, 2019, 11:22 PM
 */

#ifndef BOARD_H
#define BOARD_H
using namespace std;

class Board{
private:
    Player *players;
    BrownProperty group1[2];
    LightBlueProperty group2[3];
    PurpleProperty group3[3];
    OrangeProperty group4[3];
    RedProperty group5[3];
    YellowProperty group6[3];
    GreenProperty group7[3];
    BlueProperty group8[2];
    Railroad group9 [4];
    Utilities group10[2];
    CommunityChest group11[3];
    Chance group12[3];
    BoardLocation group14[6];
    
    
    
    
    int communitymoney;
};


#endif /* BOARD_H */

