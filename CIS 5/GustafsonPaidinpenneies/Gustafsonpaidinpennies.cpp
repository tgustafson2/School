/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Gustafsonpaidinpennies.cpp
 * Author: tgust
 *
 * Created on October 25, 2018, 10:36 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*
 * 
 */
int main() {
    float days,pay,totalpay;
    cout<< "For how many days will the pay double? ";
    cin>> days;
    if((days>=1)&&(days<=45)){
    cout<<setprecision(2)<<fixed;
        for (int doubledays=0; doubledays<days; doubledays++){
        pay=.01*pow(2,(doubledays));
        cout<<setw(16)<<left<<(doubledays+1)<<"$"<<setw(15)<< right<<pay<<endl;
        totalpay=totalpay+pay;
    }
    cout<<setw(17)<<left<<"\nTotal"<<"$"<<setw(15)<<right<<totalpay;
    }
    else
        cout<<"Invalid number entered.";
    

    return 0;
}

