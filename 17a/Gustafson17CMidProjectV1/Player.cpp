/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Player.h"
#include "Board.h"
#include "List.h"
#include <iostream>
#include <stdlib.h>
Player::Player(){
    //get name
    moves=0;
    int a[5]={5,4,3,3,2};
    ships=new List<int>(5,a);
    cout<<"Enter player's name:";
    cin>>name;
    cin.ignore();
    board = new Board;
    active=true;
    pieces=17;
    int startrow, endrow, startcol, endcol;
    board->printboard();
    for (int i=0; i<5; i++){
        cin.clear();
        cout<<"Enter a length of "<<ships->getNth(i)<<" spaces"<<endl;
        cout<<"Enter the starting location's row:";
        cin>>startrow;
        cout<<"Enter the starting location's column:";
        cin>>startcol;
        cout<<"Enter the ending location's row:";
        cin>>endrow;
        cout<<"Enter the ending location's column:";
        cin>>endcol;
        if (startrow==endrow){
            if (startcol<endcol){
            for (int j=startcol; j<=endcol; j++){
                board->setString((startrow-1)*10+j, "occupied");
            }
            }
            if (startcol>endcol){
                for (int j=endcol; j>=startcol; j--){
                board->setString((startrow-1)*10+j, "occupied");
            }
            }
        
        }
        else if (startcol==endcol){
            if (startrow<endrow){
            for (int j=startrow; j<=endrow; j++){
                board->setString((startrow-1)*10+j, "occupied");
            }
            }
            if (startrow>endrow){
                for (int j=endrow; j>=startrow; j--){
                board->setString((startrow-1)*10+j, "occupied");
            }
            }
        }
    }//clear user input
    system("clear");
    //prompt input for ship locations
}
bool Player::getStatus(){
    return active;
}
void Player::setStatus(bool sta){
    active=sta;
}
bool Player::getOccu(int row, int col){
    return board->getOccup((row-1)*10+col);
}
void Player::setBoard(int row, int col, string mark){
    if (mark=="hit")pieces--;
    board->setString((row-1)*10+col,mark);
}
void Player::printBoard(){
    board->printboard();
}
void Player::addMove(){
    moves++;
}
int Player::getMove(){
    return moves;
}

