/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Date.h"
#include <iostream>
#include <cmath>

using namespace std;


int Date::monthdays[]={31,28,31,30,31,30,31,31,30,31,30,31};

void Date:: numdate(){
    cout<<month<<"/"<<day<<"/"<<year<<endl;
}
void Date:: stddate(){
    if (month==1){
        cout<<"January ";
    }
    else if (month==2){
        cout<<"February ";
    }
    else if (month==3){
        cout<<"March ";
    }
    else if (month==4){
        cout<<"Aril ";
    }
    else if (month==5){
        cout<<"May ";
    }
    else if (month==6){
        cout<<"June ";
    }
    else if (month==7){
        cout<<"July ";
    }
    else if (month==8){
        cout<<"August ";
    }
    else if (month==9){
        cout<<"September ";
    }
    else if (month==10){
        cout<<"October ";
    }
    else if (month==11){
        cout<<"November ";
    }
    else if (month==12){
        cout<<"December ";
    }
    cout<<day<<", "<<year<<endl;
}
void Date:: date(){
    cout<<day<<" ";
    if (month==1){
        cout<<"January ";
    }
    else if (month==2){
        cout<<"February ";
    }
    else if (month==3){
        cout<<"March ";
    }
    else if (month==4){
        cout<<"Aril ";
    }
    else if (month==5){
        cout<<"May ";
    }
    else if (month==6){
        cout<<"June ";
    }
    else if (month==7){
        cout<<"July ";
    }
    else if (month==8){
        cout<<"August ";
    }
    else if (month==9){
        cout<<"September ";
    }
    else if (month==10){
        cout<<"October ";
    }
    else if (month==11){
        cout<<"November ";
    }
    else if (month==12){
        cout<<"December ";
    }
    cout<<year<<endl;
}
int Date:: operator -(const Date &minusit){
    int days=0;
    if (month>minusit.month){
        for (int i=month-1; i>=minusit.month;i--){
    days+=monthdays[i];}
    }
    else if (minusit.month>month){
        
        for (int i=month; i<minusit.month;i++){
    days-=monthdays[i-1];}
    }
    days+=((year-minusit.year)*365);
    days+=(day-minusit.day);
    return days;
}

Date Date::operator ++(){
    day++;
    if (month==12&day>31){
        day=1;
        month=1;
        year++;
    }
    if (day>monthdays[month-1]){
        day=1;
        month++;
    }
    
    return *this;
}
Date Date::operator ++(int){
    Date temp(month, day, year);
    day++;
    if (month==12&day>31){
        day=1;
        month=1;
        year++;
    }
    if (day>monthdays[month-1]){
        day=1;
        month++;
    }
    
    return temp;
}
Date Date::operator --(){
    day--;
    if (month==1&day<1){
        day=31;
        month=12;
        year--;
    }
    if (day<1){
        
        month--;
        day=monthdays[month-1];
    }
    
    return *this;
}
Date Date::operator --(int){
    Date temp(month, day, year);
    day--;
    if (month==1&day<1){
        day=31;
        month=12;
        year--;
    }
    if (day<1){
        
        month--;
        day=monthdays[month-1];
    }
    return temp;
}
ostream &operator <<(ostream &strm, const Date &obj){
    strm<<obj.day<<" ";
    if (obj.month==1){
        strm<<"January ";
    }
    else if (obj.month==2){
        strm<<"February ";
    }
    else if (obj.month==3){
        strm<<"March ";
    }
    else if (obj.month==4){
        strm<<"Aril ";
    }
    else if (obj.month==5){
        strm<<"May ";
    }
    else if (obj.month==6){
        strm<<"June ";
    }
    else if (obj.month==7){
        strm<<"July ";
    }
    else if (obj.month==8){
        strm<<"August ";
    }
    else if (obj.month==9){
        strm<<"September ";
    }
    else if (obj.month==10){
        strm<<"October ";
    }
    else if (obj.month==11){
        strm<<"November ";
    }
    else if (obj.month==12){
        strm<<"December ";
    }
    strm<<obj.year<<endl;
    return strm;
}
 istream &operator >>(istream &strm, Date &obj){
    cout<<"Month:";
    strm>>obj.month;
    while (obj.month<1||obj.month>12){
        cout<<"Invalid input. Reenter input:";
        strm>>obj.month;
    }
    cout<<"Day:";
    strm>>obj.day;
    while (obj.day<1||obj.day> Date::monthdays[obj.month-1]){
        cout<<"Invalid input. Reenter input:";
        strm>>obj.day;
    }
    cout<<"Year:";
    strm>>obj.year;
    while (obj.year<0){
        cout<<"Invalid input. Reenter input:";
        strm>>obj.year;
    }
    return strm;
}