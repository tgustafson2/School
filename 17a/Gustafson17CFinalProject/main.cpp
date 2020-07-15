/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on October 12, 2019, 3:36 PM
 */

#include <cstdlib>
#include <queue>
#include <iomanip>
#include <iostream>
#include "BinaryTree.h"
#include "Battleships.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int inpt;
    cout<<"There are 2 game modes, a one off mode with scoring based on time and pieces remaining, \n";
    cout<<"Or a continuous mode that will give a leaderboard once done. Input 1 for time or 2 for leaderboard:";
    cin>>inpt;
    if (inpt==2){
        BinaryTree leaderboard;
    //priority_queue<pair<int,string>, vector <pair<int,string>>,greater<pair<int,string>>>leaderboard;
    bool playstatus=true;
    char x;

    do{
    Battleships game;
    leaderboard.insertNode(game.Playgame()) ;
    cout<<endl<<"Would you like to play another game?Y/N";
    cin>>x;
    if (x=='N'|| x=='n')playstatus=false;
    }while (playstatus==true);
    leaderboard.prntIn();
}
    else if (inpt==1){
        Battleships game;
        game.timedMode();
    }
    return 0;
}

