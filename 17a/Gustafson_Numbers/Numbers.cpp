/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <cstring>
#include <cmath>
#include "Numbers.h"

string Numbers::lessThan20[]={"zero", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine", "ten", "eleven","twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
     string Numbers:: tens[]={
        "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "
    };
    string Numbers:: hundred= " hundred ";
    string Numbers:: thousand= " thousand ";

void Numbers::printf(){
    
        string wnumber="";
        if (number>=1000){
            wnumber+=lessThan20[number/1000];
            
            wnumber+=thousand;
        }
        if (((number/100)%10)!=0){
            wnumber+=lessThan20[(number/100)%10];
            wnumber+=hundred;
            
        }
        if (((number/10)%10)!=0){
            wnumber+=tens[((number/10)%10)-2];
        }
        if (number>0){
            if (((number/10)%10)<2){
            wnumber+=lessThan20[number%20];}
            else if (((number/10)%10)>=2){
                wnumber+=lessThan20[number%10];
            }
        }
        else if (number==0){
            wnumber+=lessThan20[number];
        }
        cout<<wnumber;
}