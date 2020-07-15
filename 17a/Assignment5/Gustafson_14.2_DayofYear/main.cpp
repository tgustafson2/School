/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on May 11, 2019, 9:48 PM
 */

#include <cstdlib>
#include <iostream>
#include "DayOfYear.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int days;
    cout<<"Enter a number between 1 and 365:";
    cin>>days;
    DayOfYear day(days);
    day.print();
    
    return 0;
}

