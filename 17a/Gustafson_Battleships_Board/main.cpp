/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on April 11, 2019, 11:35 AM
 */

#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
struct board{
    string mark;
    bool occupied;
    
};



int main(int argc, char** argv) {
    board layout[10][10];
    fstream battleship_setup;
    battleship_setup.open("battleship_setup.dat", ios::out| ios::binary);
    
    
    
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            layout[i][j].mark="empty";
            layout[i][j].occupied=false;
            battleship_setup.write(reinterpret_cast<char *> (&layout[i][j]),sizeof(layout[i][j]));
        }
    }
    
    battleship_setup.close();
    
    
    

    return 0;
}

