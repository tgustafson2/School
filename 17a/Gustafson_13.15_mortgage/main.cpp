/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on May 2, 2019, 6:30 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "MPayment.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    MPayment loaninfo;
    float loan, rate;
    int years;
    cout<<"Enter the amount the loan is for:$";
    cin>>loan;
    cout<<"Enter how many years it is for:";
    cin>>years;
    cout<<"Enter the rate as a decimal:";
    cin>>rate;
    loaninfo.setloan(loan);
    loaninfo.setyears(years);
    loaninfo.setrate(rate);
    cout<<"The monthly payment is:$"<<fixed<<setprecision(2)<<loaninfo.getpay()<<endl;
    cout<<"The total payment will be:$"<<fixed<<setprecision(2)<<loaninfo.gettotal();
    return 0;
}

