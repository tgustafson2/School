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

    int day;
    string month;
    cout<<"Enter a month:";
    
    cin>>month;
    cout<<"Enter the day of the month:";
    cin>>day;
    DayOfYear days(month, day);
    days.printd();
    days++;
    cout<<"After increment ";
    days.printd();
    days--;
    days--;
    cout<<"After decrementing twice ";
    days.printd();
    return 0;
}

