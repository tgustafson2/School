/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DayOfYear.h
 * Author: tgust
 *
 * Created on May 11, 2019, 9:48 PM
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
#include <string>
#include <iostream>

using namespace std;


class DayOfYear{
private:
    static int monthdays[13];
    static string months[12];
    int days;
    
    
public:
    DayOfYear(int num){
        while (num<1||num>365){
            cout<<"Invalid input. Reenter Number:";
            cin>>num;
        }
        days=num;
    }
    DayOfYear(string month, int day);
    DayOfYear operator ++();
    DayOfYear operator --();
    DayOfYear operator ++(int);
    DayOfYear operator --(int);
    void printd();
    void print();
    

    
};
#endif /* DAYOFYEAR_H */

