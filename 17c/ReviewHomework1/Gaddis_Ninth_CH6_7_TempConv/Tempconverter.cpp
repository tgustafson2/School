/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TempConverter.cpp
 * Author: tgust
 *
 * Created on February 22, 2019, 2:07 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

/*Make a function declaration to convert fahrenheit to celsius
 * initialize variable for a fraction and fahrenheit
 * begin a for loop to convert 1 to 20 of fahrenheit to celsius
 * pass fahrenheit to conversion function
 * output celsius temperature
 * 
 */

float celsius (float, float);

int main() {
    const float fract=(5.0/9.0);
    float fahrenheit;
    
    for(fahrenheit=1; fahrenheit<=20; fahrenheit++){
        cout<<"Fahrenheit"<<setw(6)<<right<<fahrenheit<<"\tCelsius"
                <<setw(6)<<right<<celsius(fahrenheit, fract)<<endl;
    }

    return 0;
}

float celsius (float temp, float fract){
    float celtemp;
    celtemp=fract*(temp-32);
    return celtemp;
}

