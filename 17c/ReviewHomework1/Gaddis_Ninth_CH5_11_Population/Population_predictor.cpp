/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Population_predictor.cpp
 * Author: tgust
 *
 * Created on February 22, 2019, 12:13 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

/*Declare variables days, num, increaseperc, population
 * Prompt user for input of population, days, and increase percentage.
 * Validate user input with while loops
 * Use for loop to calculate and display population each day
 * Use stream manipulators to display as ints
 * 
 */
int main() {
    int days, num;
    double increaseperc, population;
    
    cout<<"What is the initial population of organisms?";
    cin>>population;
    while(population<2){
        cout<<"Invalid input. Please reenter population of at least 2.";
                cin>>population;}
    
    cout<<"What is the average daily increase by percent? %";
    cin>>increaseperc;
    while(increaseperc<0){
        cout<<"Invalide input. Please reenter a positive number.";
        cin>>increaseperc;}
    
    cout<<"How many days will they multiply?";
    cin>>days;
    while(days<1){
        cout<<"Invalid input. Please reenter more than 1 day.";
        cin>>days;
        
    }
    for (num=1; num<=days; num++){
        population*=1+(increaseperc/100);
        cout<<"Day"<<setw(10)<<right<<num<<"\tPopulation"
                <<setw(20)<<right<<fixed<<setprecision(0)<<population<<"\n";
    }    

    return 0;
}

