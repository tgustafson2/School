/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on April 30, 2019, 10:03 PM
 */

#include <cstdlib>
#include <iostream>
#include "Population.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int population, deaths, births;
    cout<<"Enter the population:";
    cin>>population;
    cout<<"Enter the number of deaths in a year:";
    cin>>deaths;
    cout<<"Enter the number of births in a year:";
    cin>>births;
    Population rates(population, deaths, births);
    cout<<"The birth rate is "<<rates.getbirthr()<<endl;
    cout<<"The death rate is "<<rates.getdeathr()<<endl;
    return 0;
}

