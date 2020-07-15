/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Thomas Gustafson
 *
 * Created on October 7, 2018, 6:46 PM
 */

#include <iostream>
#include <iomanip>
//This program will calculate the commission received depending on sales
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    float sales, commission, tier1,tier2,tier3;
    tier1=.1;
    tier2=.15;
    tier3=.2;
    cout<< "Enter amount of sales: ";
    cin>>sales;
    // Three separate possible paths using if else statements
    if (sales<5000)
        commission= sales*tier1;
    else if (5000<=sales<=25000)
        commission= sales*tier2;
    else
        commission= sales*tier3;
    cout<< setprecision(2)<<fixed;
    cout<< "\nSales:"<< right<<setw(7)<<"$"<<setw(10)<<right<<sales <<endl;
    cout<< "Commission: $" <<right<<setw(10)<<right<<commission;

    return 0;
}

