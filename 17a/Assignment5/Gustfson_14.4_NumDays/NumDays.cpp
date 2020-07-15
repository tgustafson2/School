/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NumDays.h"

float NumDays::workday=8.0;

NumDays NumDays:: operator +(const NumDays &addit){
    NumDays temp;
    temp.hours=hours+addit.hours;
    temp.setDays();
    return temp;
}
NumDays NumDays:: operator -(const NumDays &minusit){
    NumDays temp;
    temp.hours=hours-minusit.hours;
    temp.setDays();
    return temp;
}
NumDays NumDays:: operator ++(){
    ++hours;
    setDays();
}
NumDays NumDays:: operator ++(int){
    NumDays temp(hours);
    hours++;
    setDays();
    return *this;
}
NumDays NumDays:: operator --(){
    --hours;
    setDays();
    
}
NumDays NumDays:: operator --(int){
    NumDays temp(hours);
    hours--;
    setDays();
    return *this;
}