/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Numbers.h
 * Author: tgust
 *
 * Created on May 11, 2019, 6:17 PM
 */

#ifndef NUMBERS_H
#define NUMBERS_H
#include <string>
#include <iostream>
using namespace std;

class Numbers{
private:
    int number;
    
    static string lessThan20[20];
    static string tens[8];
    static string hundred;
    static string thousand;
    
    
public:
    Numbers (int num){
        
        setnumber(num);
        
        
    }
    void setnumber(int num){
        number= num;
    }
    void printf();
    
};

#endif /* NUMBERS_H */
