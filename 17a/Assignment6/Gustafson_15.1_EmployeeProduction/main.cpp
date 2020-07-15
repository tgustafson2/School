/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on May 17, 2019, 5:17 PM
 */

#include <cstdlib>
#include <iostream>
#include "ProductionWorker.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string name, date;
    int shift, number;
    double rate;
    cout<<"Enter the employee name:";
    getline(cin, name);
    cout<<"Enter the employee's number:";
    cin>>number;
    cin.ignore();
    cout<<"Enter the employee's hire date:";
    getline(cin, date);
    cout<<"Enter the work shift for the employee(1 for day, 2 for night)";
    cin>>shift;
    cout<<"Enter the employee's pay rate:";
    cin>>rate;
    ProductionWorker worker1(shift, rate, name, number, date);
    cout<<"\n\n\nEmployee"<<endl;
    cout<<worker1.getname()<<endl;
    cout<<"ID: "<<worker1.getnumber()<<endl;
    cout<<"Hire Date: "<<worker1.gethdte()<<endl;
    if (worker1.getshift()==1){
        cout<<"Day Shift"<<endl;
    }
    else if (worker1.getshift()==2){
        cout<<"Night Shift"<<endl;
    }
    cout<<"Hourly Pay: $"<<worker1.getrate();
    
    

    return 0;
}

