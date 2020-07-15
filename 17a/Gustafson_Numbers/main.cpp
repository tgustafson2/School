/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on May 11, 2019, 5:36 PM
 */

#include <cstdlib>
#include <iostream>
#include "Numbers.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int number;
    
    cout<<"Enter a number between 0 and 9999:";
    cin>>number;
    Numbers num(number);
    cout<<"The number is ";
    num.printf();

    return 0;
}

