/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Celsius_to_Fahrenheit.cpp
 * Author: tgust
 *
 * Created on February 21, 2019, 7:24 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

/*declare floating point variables celtemp and ftemp
 * prompt the user to input the temperature in celsius
 * calculate temperature in fahrenheit
 * Output temperature in fahrenheit
 */
int main() {
    float celtemp;
    float ftemp;
    cout<<"Enter the temperature in Celsius.";
    cin>>celtemp;
    ftemp=(celtemp*(9.0/5.0)+32);
    cout<<"The temperature is "<<ftemp<<" degrees Fahrenheit.";
    return 0;
}

