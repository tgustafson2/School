/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on February 21, 2019, 7:45 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

/*Declare constants of yen per dollar and euros per dollar
 * Declare floating point variable of USdollar
 * Prompt the user to input currency amount
 * set precision so two places are displayed after the decimal
 * Output the yen amount
 * Output the Euro amount
 * 
 */
int main() {
    const float YEN_PER_DOLLAR =110.74;
    const float EUROS_PER_DOLLAR=.88;
    float USdollar;
    cout<<"Enter how much US currency you have. $";
    cin>>USdollar;
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"You have $"<<USdollar*YEN_PER_DOLLAR<< " Yen.\n";
    cout<<"You have $"<<USdollar*EUROS_PER_DOLLAR<< " Euros.";

    return 0;
}

