/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on May 12, 2019, 12:09 PM
 */

#include <cstdlib>
#include <iostream>
#include "NumDays.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int hours;
    cout<<"This will calculate how many days you worked by hours. Enter hours:";
    cin>>hours;
    NumDays workdays(hours);
    cout<<"You worked "<<workdays.getDays()<<" days.";
    
    
    return 0;
}

