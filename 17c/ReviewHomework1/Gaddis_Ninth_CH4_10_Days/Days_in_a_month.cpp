/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Days_in_a_month.cpp
 * Author: tgust
 *
 * Created on February 21, 2019, 8:20 PM
 */

#include <iostream>

using namespace std;

/* Declare int variables month and year
 * prompt user to enter month and year
 * using if else statements determine if month is one that has 30 or 31 days
 * if it is the 2nd month use modulo with nested if statements to determine if
 * month has 28 or 29 days
 * output days
 * 
 */
int main() {
    int month, year;
    cout<<"Enter a month (1-12): ";
    cin>>month;
    cout<<"Enter a year: ";
    cin>>year;
    if (month==1||month==3||month==5||month==7||month==8||month==10||month==12){
        cout<<"31 days";
    }
    else if(month==4||month==6||month==9||month==11){
        cout<<"30 days";
    }
    else if(month==2){
        if (year%100==0){
            if(year%400==0){
                cout<<"29 days";
            }
            else{
                cout<<"28 days";
            }
        }
        else if (year%4==0){
            cout<<"29 days";
        }
        else{
            cout<<"28 days";
        }
    }
    else{
        cout<<"Invalid input";
    }

    return 0;
}

