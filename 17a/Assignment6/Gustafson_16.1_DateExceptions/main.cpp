/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on May 18, 2019, 7:05 PM
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
    try{
    cout<<"Enter the day:";
    cin>>day;
    cout<<"Enter the month:";
    cin>>month;
    cout<<"Enter the year:";
    cin>>year;
    Date gdate(month, day, year);
    gdate.date();
    gdate.stddate();
    gdate.numdate();}
    catch (Date::InvalidDay x){
        cout<<"Error: "<<x.getval()<<" is an invalid day.";
    }
    catch (Date::InvalidMonth y){
        cout<<"Error: "<<y.getval()<<" is an invalid month";
    }

    return 0;
}