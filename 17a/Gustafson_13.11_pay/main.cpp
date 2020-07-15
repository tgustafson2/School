/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on May 2, 2019, 4:55 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Payroll.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Payroll employees[7];
    float rate, hours;
    for (int i=0; i<7; i++){
        cout<<"Enter the employee's hourly pay:";
        cin>>rate;
        cout<<"Enter the time worked:";
        cin>>hours;
        employees[i].setpay(rate, hours);
        cout<<"Their gross pay is:$"<<setprecision(2)<<fixed<<employees[i].getsalary()<<endl;
    }

    return 0;
}

