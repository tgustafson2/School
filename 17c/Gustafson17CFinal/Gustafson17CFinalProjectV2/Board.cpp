/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Board.h"
#include <map>
#include <iterator>
#include <utility>
#include <string>
#include <iostream>
using namespace std;

Board::Board(){
    //board= new map<int, string>();
    for (int i=1; i<=100; i++){
        board[i]="empty";
    }
}
void Board::setString(int key, string ele){
    board[key]=ele;
}
bool Board::getOccup(int key){
    if (board[key]=="occupied"){
        return true;
    }
    else return false;
}
void Board::printboard(){
    map<int, string> :: iterator it;
    cout <<"  1  2  3  4  5  6  7  8  9  10"<<endl;
    //int i=0;
    for (it=board.begin(); it!=board.end(); ++it){

        if(it->first==1)cout<<"1 ";
        else if (it->first==11)cout<<endl<<"2 ";
        else if (it->first==21)cout<<endl<<"3 ";
        else if (it->first==31)cout<<endl<<"4 ";
        else if (it->first==41)cout<<endl<<"5 ";
        else if (it->first==51)cout<<endl<<"6 ";
        else if (it->first==61)cout<<endl<<"7 ";
        else if (it->first==71)cout<<endl<<"8 ";
        else if (it->first==81)cout<<endl<<"9 ";
        else if (it->first==91)cout<<endl<<"10 ";
        if (it->second=="empty"||it->second=="occupied")cout<<"_  ";
        else if (it->second=="hit")cout<<"x  ";
        else if (it->second=="miss")cout<<"o  ";
    }
    cout<<endl;
}