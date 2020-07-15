/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on May 17, 2019, 7:56 PM
 */

#include <cstdlib>
#include <iostream>
#include "Essay.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    double grammar, spelling, length, content;
    
    cout<<"Enter the students points for grammar:";
    cin>>grammar;
    cout<<"Enter the students points for spelling:";
    cin>>spelling;
    cout<<"Enter the students points for length:";
    cin>>length;
    cout<<"Enter the students points for content:";
    cin>>content;
    Essay ess1(grammar, spelling, length, content);
    cout<<"The essay grade is "<<ess1.getLetterGrade();
    
    
    return 0;
}

