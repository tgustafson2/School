/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on December 12, 2019, 7:05 PM
 */
//System Libraries
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <list>
using namespace std;

//User Libraries
#include "BinaryTree.h"
//Global Constants

//Function Prototypes


int Hash(string);
int sHash(string);
//Execution Begins Here

int main(int argc, char** argv) {
    //Set random number seed here
    srand (time(0));
    //Declare Variables
    int size=512;
    
    int max;
    BinaryTree<string>*tree=new BinaryTree<string>;
    list<string>*init=new list <string>[size];
    list<string>*sinit=new list <string>[size];
    int *stats = new int[11];
    for (int i = 0; i < 11; i++) {

        stats[i] = 0;
    }
    string initials="   ";
    //Initialize Variables
    for (int i=0; i<size; i++){
        initials[0] = (char) ( rand( ) % 26 + 65 );
        initials[1] = (char) ( rand( ) % 26 + 65 );
	initials[2] = (char) ( rand( ) % 26 + 65 );
        int hash= Hash(initials);
        int shash= sHash(initials);
        init[hash%512].push_back(initials);
        sinit[shash%512].push_back(initials);
        tree->insertNode(initials);
    }
    cout << "\nAt most it will take " << ceil( log( size ) / log( 2 ) ) +1<< " times to find with a binary tree"<<endl;
    //Process inputs to outputs/map
    for (int i=0; i<size; i++){
        stats[init[i].size()]++;
    }

    for (int i=0; i<11;i++){
        if (stats[i]!=0)
            max=i;
    }
    //Display the results
    cout<<"Hash"<<endl;
    for (int i=0; i<11; i++){
        cout<<i<<" collisions occured "<<stats[i]<<" times"<<endl;
    }
    cout<<"It will take at most "<<max<<" times to reach a value"<<endl;
    max=0;
    for (int i = 0; i < 11; i++) {

        stats[i] = 0;
    }
    for (int i=0; i<size; i++){
        stats[sinit[i].size()]++;
    }
    for (int i=0; i<11;i++){
        if  (stats[i]!=0)
            max=i;
    }
    cout<<"It will take at most "<<max<<" times to reach a value"<<endl;
    cout<<"Shash"<<endl;
    for (int i=0; i<11; i++){
        cout<<i<<" collisions occured "<<stats[i]<<" times"<<endl;
    }
    //Clean up and exit stage right
    return 0;
}

int Hash(string initials){
    int hash=0;
    for ( int i = 0; i < 3; i++ ) {
		int j = 0;
		char c = initials[i];
		if ( c >= 65 && c <= 67 ) {
			j = 2;
		} else if ( c >= 68 && c <= 70 ) {
			j = 3;
		} else if ( c >= 71 && c <= 73 ) {
			j = 4;
		} else if ( c >= 74 && c <= 76 ) {
			j = 5;
		} else if ( c >= 77 && c <= 79 ) {
			j = 6;
		} else if ( c >= 80 && c <= 83 ) {
			j = 7;
		} else if ( c >= 84 && c <= 86 ) {
			j = 8;
		} else if ( c >= 85 && c <= 90 ) {
			j = 9;
		}
                 
                hash+=(j*(pow(10,2-i)));
		
	}
//    cout<<hash<<endl;
    return hash;
}
int sHash(string initials){
    int hash=0;
    for ( int i = 0; i < 3; i++ ) {
		int j = 0;
		char c = initials[i];
		if ( c >= 65 && c <= 67 ) {
			j = 2;
		} else if ( c >= 68 && c <= 70 ) {
			j = 3;
		} else if ( c >= 71 && c <= 73 ) {
			j = 4;
		} else if ( c >= 74 && c <= 76 ) {
			j = 5;
		} else if ( c >= 77 && c <= 79 ) {
			j = 6;
		} else if ( c >= 80 && c <= 83 ) {
			j = 7;
		} else if ( c >= 84 && c <= 86 ) {
			j = 8;
		} else if ( c >= 85 && c <= 90 ) {
			j = 9;
		}
                 
                hash+=((j-2)*(pow(8,2-i)));
		
	}
//    cout<<hash<<endl;
    return hash;
}
