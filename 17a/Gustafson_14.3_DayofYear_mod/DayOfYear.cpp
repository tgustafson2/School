/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "DayOfYear.h"
#include <iostream>
#include <string>
using namespace std;

int DayOfYear::monthdays[]={
    0,31,59,90,120,151,181,212,243,273,304,334,365
};
string DayOfYear::months[]={
    "January", "February", "March", "April", "May","June", "July", "August",
    "September", "October", "November","December"
};
void DayOfYear::printd(){
    cout<<"That is day "<<days<<endl;
}
void DayOfYear::print(){
    int tracker=0;
    int mdays=days;
    while (days>monthdays[tracker]){
        tracker++;
    }
    mdays-=monthdays[tracker-1];
    cout<<months[tracker-1]<<" "<<mdays;
}

DayOfYear::DayOfYear(string month, int day){
    int tracker=0;
    
    
    while (month!=months[tracker]){
        tracker++;
        if(tracker>11){
            tracker=0;
            cout<<"Reenter month with first letter capitalized:";
            cin.ignore();
            cin>>month;
        }
        
    }
    if (day>(monthdays[tracker]-monthdays[tracker-1])||day<1){
        cout<<"Invalid days, Reenter days:";
        cin>>day;
    }
    days=monthdays[tracker]+day;
}
DayOfYear DayOfYear:: operator++(){
    days++;
    if (days>365){
        days-=365;
    }
    return *this;
}
DayOfYear DayOfYear::operator --(){
    days--;
    if (days<1){
        days+=365;
    }
    return *this;
}
DayOfYear DayOfYear:: operator++(int){
    int day=days;
    days++;
    if (days>365){
        days-=365;
    }
    return day;
}
DayOfYear DayOfYear::operator --(int){
    int day=days;
    days--;
    if (days<1){
        days+=365;
    }
    return day;
}
