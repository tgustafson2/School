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
void DayOfYear::print(){
    int tracker=0;
    int mdays=days;
    while (days>monthdays[tracker]){
        tracker++;
    }
    mdays-=monthdays[tracker-1];
    cout<<months[tracker-1]<<" "<<mdays;
}

