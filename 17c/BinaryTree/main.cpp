/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on November 29, 2019, 3:58 PM
 */
//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries
#include "BinaryTree.h"

//Global Constants

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Set random number seed here

    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    BinaryTree<int> tree(rand()%90+10);
    tree.insertNode(40);
    
    //Initialize Variables

    //Process inputs to outputs/map
    for (int i=0; i<50;i++){
        tree.insertNode(rand()%90+10);
    }
//    tree.remove(40);
    

    //Display the results

//    tree.prntIn();
    cout<<endl;
    
    //tree.balance();
    tree.prntIn();
    cout<<endl;
    tree.prntPre();
    cout<<endl;
    tree.prntPst();
    cout<<endl;
    tree.prntLev();
    tree.~BinaryTree();
    //Clean up and exit stage right
    return 0;
}
