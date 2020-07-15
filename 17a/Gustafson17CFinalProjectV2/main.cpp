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
#include <list>
#include "BinaryTree.h"
#include "Battleships.h"

using namespace std;

/*
 * 
 */
unsigned int ourHash (string&, int);

int main(int argc, char** argv) {
    int inpt;
    int max=0;
    int LSTSIZE=50;
    list<string>*top=new list <string>[LSTSIZE];
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
    pair<int,string>winner;
    winner=game.Playgame();
    top[ourHash(winner.second,20)%LSTSIZE].push_back(winner.second);
    leaderboard.insertNode(winner) ;
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
    
    for (int i=0;i<LSTSIZE;i++){
        top[i].unique();
        max+=top[i].size();
    }
    cout<<"The number of unique winners is "<<max;
  
    return 0;
}

unsigned int ourHash(string &a, int size){
    unsigned int sum;
    unsigned int prod=1;
    char c;
    for (int i=0; i<size; i++){
        if (a[i]<=91)c=a[i]-65;
        else c=a[i]-71;
        sum+=(sum+c*prod);
        prod*=52;
        prod%=9999991;
        sum%=999999991;
    }
    return sum;
}