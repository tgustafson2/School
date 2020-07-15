/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>
#include <cmath>
SavingsAccount::SavingsAccount(float Balance){
    if (Balance>0){
        this->Balance=Balance;
    }
    else
    this->Balance=0;
    FreqWithDraw=0;
    FreqDeposit=0;
}
void SavingsAccount::Transaction(float trans){
    if (trans>0){
        Balance+=Deposit(trans);
    }
    else if(trans<0){
        Balance+=Withdraw(trans);
    }
}
float SavingsAccount::Total(float savint, int time){
    return Balance*pow((1+savint),time);
}
float SavingsAccount::TotalRecursive(float savint, int time){
    
    if (time>0){
       Balance=TotalRecursive(savint, time-1); 
       Balance*=(1+savint);
    }
    return Balance;
}
void SavingsAccount::toString(){
    cout<<"Balance="<<fixed<<setprecision(2)<<Balance<<endl;
    cout<<"Withdraws="<<FreqWithDraw<<endl;
    cout<<"Deposits="<<FreqDeposit<<endl;
}
float SavingsAccount::Deposit(float dep){
    FreqDeposit++;
    return dep;
}
float SavingsAccount::Withdraw(float withd){
    if(abs(withd)<Balance){
        FreqWithDraw++;
        return withd;
    }
    else{
        cout<<"WithDraw not Allowed"<<endl;
        FreqWithDraw++;
        return 0;
    }
}