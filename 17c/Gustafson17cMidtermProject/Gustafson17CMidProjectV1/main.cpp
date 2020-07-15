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
    priority_queue<pair<int,string>, vector <pair<int,string>>,greater<pair<int,string>>>leaderboard;
    bool playstatus=true;
    char x;

    do{
    Battleships game;
    leaderboard.push(game.Playgame()) ;
    cout<<"Would you like to play another game?Y/N";
    cin>>x;
    if (x=='N'|| x=='n')playstatus=false;
    }while (playstatus==true);
    while (!leaderboard.empty()){
        pair <int,string> player=leaderboard.top();
        leaderboard.pop();
        cout<<player.second<<' '<<player.first;
    }}
    else if (inpt==1){
        Battleships game;
        game.timedMode();
    }
    return 0;
}

