/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on April 30, 2019, 8:08 PM
 */

#include <cstdlib>
#include <iostream>
#include "Date.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int day, year, month;
    cout<<"Enter the day:";
    cin>>day;
    cout<<"Enter the month:";
    cin>>month;
    cout<<"Enter the year:";
    cin>>year;
    Date gdate(month, day, year);
    gdate.date();
    gdate.stddate();
    gdate.numdate();

    return 0;
}

