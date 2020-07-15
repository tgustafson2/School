/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Employee.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

Employee::Employee(char MyName[], char JobTitle [],float HourlyRate){
    strcpy(this->MyName,MyName);
    strcpy(this->JobTitle, JobTitle);
    setHourlyRate(HourlyRate);
    HoursWorked=0;
    GrossPay=0;
    NetPay=0;
}
float Employee::setHourlyRate(float HourlyRate){
    if (HourlyRate>0&&HourlyRate<84){
    this->HourlyRate=HourlyRate;}
    else{
        cout<<"Unacceptable Hourly Rate"<<endl;
        this->HourlyRate=0;}
    return this->HourlyRate;
}
int Employee::setHoursWorked(int HoursWorked){
    if (HoursWorked>0&&HoursWorked<84){
    this->HoursWorked=HoursWorked;}
    else{
        cout<<"Unacceptable Hours Worked"<<endl;
        this->HoursWorked=0;}
    return this->HoursWorked;
    
}
float Employee:: getGrossPay(float HourlyRate, int HoursWorked){
    if (HoursWorked<40){
        GrossPay=HourlyRate*HoursWorked;
    }
    else if(HoursWorked>=40&&HoursWorked<50){
        GrossPay=HourlyRate*40;
        GrossPay+=HourlyRate*(HoursWorked-40)*1.5;
        
    }
    else{
        GrossPay=HourlyRate*40+HourlyRate*10*1.5;
        GrossPay+=HourlyRate*2*(HoursWorked-50);
    }
    return GrossPay;
}
float Employee::getNetPay(float GrossPay){
    double tax=Tax(GrossPay);
    NetPay=GrossPay-tax;
    return NetPay;
}
float Employee::CalculatePay(float HourlyRate, int HoursWorked){
    return getNetPay(getGrossPay(setHourlyRate(HourlyRate), setHoursWorked(HoursWorked)));
}
void Employee::toString(){
    cout<<"Name = "<<MyName<<" Job Title = "<<JobTitle<<endl;
    cout<<"Hourly Rate = "<<fixed<<setprecision(0)<<HourlyRate<<" Hours Worked = "<<HoursWorked
            <<" Gross Pay = "<<GrossPay<<" Net Pay = "<<fixed<<setprecision(0)<<NetPay<<endl;
}
double Employee::Tax(float GrossPay){
    double tax;
    if (GrossPay<500){
        tax=GrossPay*.1;
    }
    else if(GrossPay>=500&&GrossPay<1000){
        tax=500*.1;
        tax+=.2*(GrossPay-500);
    }
    else{
        tax=500*.1+.2*500;
        tax+=.3*(GrossPay-1000);
    }
    return tax;
}