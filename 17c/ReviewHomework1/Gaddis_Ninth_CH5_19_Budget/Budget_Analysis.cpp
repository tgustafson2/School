/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Budget_Analysis.cpp
 * Author: tgust
 *
 * Created on February 24, 2019, 12:12 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main() {
    // declare varibales for budget, expenses, number of expenses, and for index
    float monthlybudget, expense;
    int numexpenses, index;
    //prompt user for budget and number of expenses
    cout<<"Enter your monthly budget: $";
    cin>>monthlybudget;
    cout<<"How many expenses do you have this month?";
    cin>>numexpenses;
    //loop prompting user for their expenses
    for (index=0; index<numexpenses; index++){
        expense=0;
        cout<<"Enter your expense: $";
        cin>>expense;
        monthlybudget-=expense;
    }
    // output how much user is under or over budget using if and else if
    if (monthlybudget<0){
        cout<<"You are over budget by: $"<<setw(10)<<fixed
        <<setprecision(2)<<right<<monthlybudget;
    }
    else if (monthlybudget>=0){
        cout<<"You are under budget by: $"<<setw(10)<<fixed
                <<setprecision(2)<<right<<monthlybudget;
    }

    return 0;
}

