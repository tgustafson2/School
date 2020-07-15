/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GustafsonFuturesavings.cpp
 * Author: tgust
 *
 * Created on November 6, 2018, 9:16 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void futurevalue (float, float, float);

int main() {
float presentvalue, monthlyinterest, months;

cout << "Enter the present value of the bank account:"<<setw(10)<<"$";
cin>> presentvalue;
cout<< "Enter the interest rate:"<<setw (30)<< right<< "%";
cin>> monthlyinterest;
cout<< "How many months will the money be left in the account?";
cin>> months;
futurevalue (presentvalue, monthlyinterest, months);
return 0;
}

void futurevalue (float presentvalue, float monthlyinterest, float months){
cout<< "The future value of the account is:"<<setw(19)<<right<<"$";
cout<< setw(20)<<left<<setprecision(2)<<fixed<<(presentvalue*(pow((1+(monthlyinterest/100)),months)));
}


