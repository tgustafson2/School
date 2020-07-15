/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on May 17, 2019, 6:18 PM
 */

#include <cstdlib>
#include <iostream>
#include "MilTime.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int hours, seconds;
    cout<<"Enter the hours and minutes in military format:";
    cin>>hours;
    cout<<"Enter the seconds:";
    cin>>seconds;
    MilTime time1(hours, seconds);
    cout<<"The time in military format is: "<<time1.getHourf()<<endl;
    cout<<"The time in standard format is: "<<time1.getStandHr()<<endl;
    
    
    
    

    return 0;
}

