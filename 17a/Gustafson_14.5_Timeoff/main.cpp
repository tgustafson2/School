/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on May 12, 2019, 3:12 PM
 */

#include <cstdlib>
#include <iostream>
#include "NumDays.h"
#include "TimeOff.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    string name;
    int id,vmax, smax, umax, vtaken, staken, utaken;
    
    cout<<"Enter the employee's name:";
    
    getline(cin, name);
    cout<<"Enter the employee's id number:";
    cin>>id;
    
    cout<<"Enter the maximum amount of vacation time:";
    cin>>vmax;
    cout<<"Enter the vacation hours taken:";
    cin>>vtaken;
    cout<<"Enter the maximum amount of sick time:";
    cin>>smax;
    cout<<"Enter the sick time taken:";
    cin>>staken;
    cout<<"Enter the max amount of unpaid time:";
    cin>>umax;
    cout<<"Enter the amount of unpaid time taken:";
    cin>>utaken;
    
    
    
    TimeOff employee(smax,staken,vmax,vtaken,umax,utaken,name,id);
    cout<<employee.getname()<<" time off data:"<<endl;
    cout<<"Employee has "<<(employee.getsmaxDays()-employee.getstakenDays())<<" days of sick leave left."<<endl;
    cout<<"Employee has "<<(employee.getvmaxDays()-employee.getvtakenDays())<<" days of vacation leave left."<<endl;
    cout<<"Employee has "<<(employee.getumaxDays()-employee.getutakenDays())<<" days of unpaid leave left."<<endl;
    
    
    return 0;
}

