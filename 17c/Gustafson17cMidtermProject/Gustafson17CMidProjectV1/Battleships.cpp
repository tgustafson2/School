/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Battleships.h"
#include "List.h"
#include "Player.h"
#include <ctime>
#include <stack>
#include <utility>
using namespace std;

Battleships::Battleships(){
    
    players=new Player*[2];
    players[0]=new Player();
    players[1]=new Player();
    game=true;
}
pair<int,string> Battleships::Playgame(){
    while (game==true){
        //for loop print out player name and opponent board
        for (int i=0; i<2; i++){
            int arow, acol;
            cout<<players[i]->getName()<<"'s turn"<<endl;
            if (i==0)players[1]->printBoard();
            else if (i==1)players[0]->printBoard();
            cout<<"Enter the row of the location you wish to attack:";
            cin>>arow;
            cout<<"Enter the column of the location you wish to attack:";
            cin>>acol;
            if (i==0)attack (arow,acol,1);
            else if (i==1)attack(arow,acol,0);
            if (i==0){
                if (players[1]->getPieces()==0)players[1]->setStatus(false);}
            else if (i==1){
                if (players[0]->getPieces()==0)players[0]->setStatus(false);
            }
            players[i]->addMove();
        }
        if (players[0]->getStatus()==false||players[1]->getStatus()==false)game=false;
        //prompt attack location, mark hit or miss
        //if all ships are down set player to false
        //if player is false set game to false
    }
    if (players[0]->getStatus()==true){
        cout<<"Congratulations "<<players[0]->getName()<<" you have won";
        pair <int,string> winner;
        winner.first=players[0]->getMove();
        winner.second=players[0]->getName();
        return winner;
    }
    else if(players[1]->getStatus()==true){
        cout<<"Congratulations "<<players[1]->getName()<<" you have won";
        pair <int,string> winner;
        winner.first=players[1]->getMove();
        winner.second=players[1]->getName();
        return winner;
    }
    //print winner's name
}
void Battleships::attack(int row, int col, int pl){
    if(players[pl]->getOccu(row,col)==true){
        players[pl]->setBoard(row,col,"hit");
        cout<<"Hit"<<endl;
    }
    else if (players[pl]->getOccu(row,col)==false){
        players[pl]->setBoard(row,col,"miss");
        cout<<"Miss"<<endl;
    }
}
void Battleships::timedMode(){
    stack<unsigned int> playertime;
    float score1,score2;
    while (game==true){
        //for loop print out player name and opponent board
        for (int i=0; i<2; i++){
            unsigned int time_req=time(0);
            int arow, acol;
            cout<<players[i]->getName()<<"'s turn"<<endl;
            if (i==0)players[1]->printBoard();
            else if (i==1)players[0]->printBoard();
            cout<<"Enter the row of the location you wish to attack:";
            cin>>arow;
            cout<<"Enter the column of the location you wish to attack:";
            cin>>acol;
            if (i==0)attack (arow,acol,1);
            else if (i==1)attack(arow,acol,0);
            if (i==0){
                if (players[1]->getPieces()==0)players[1]->setStatus(false);}
            else if (i==1){
                if (players[0]->getPieces()==0)players[0]->setStatus(false);
            }
            players[i]->addMove();
            time_req=time(0)-time_req;
            playertime.push(time_req);
        }
        
        if (players[0]->getStatus()==false||players[1]->getStatus()==false)game=false;
        //prompt attack location, mark hit or miss
        //if all ships are down set player to false
        //if player is false set game to false
    }
    unsigned int player1time=0,player2time=0;
    while (!playertime.empty()){
        player1time=playertime.top();
        playertime.pop();
        player2time=playertime.top();
        playertime.pop();
    }
    score1=(float)(players[0]->getPieces()+1)*player1time;
    score2=(float)(players[1]->getPieces()+1)*player2time;
    if (score1<score2){
        cout<<"Congratulations "<<players[0]->getName()<<" you have won";
        cout<<endl<<"With a score of "<<score1;
    }
    else if (score1>score2){
        cout<<"Congratulations "<<players[1]->getName()<<" you have won";
        cout<<endl<<"With a score of "<<score2;
    }
    else if (score1==score2){
        cout<<"It is a tie with a score of "<<score1;
    }

    
}