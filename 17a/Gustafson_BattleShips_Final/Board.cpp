/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Board.h"

using namespace std;
Board::Board(){
    location=new BoardSpace **[10];
    for (int i=0; i<10; i++){
        location[i]= new BoardSpace*[10];
        for (int j=0; j<10; j++){
            location[i][j]= new BoardSpace();
        }
    }
}
Board::~Board(){
    for (int i=0; i<10; i++){
        delete []location[i];
    }
    delete []location;
}