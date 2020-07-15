/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Gustafsonpicalculation.cpp
 * Author: tgust
 *
 * Created on October 25, 2018, 11:43 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/*
 * 
 */
int main() {
    float pi;
    int n;
    char userinput;
    
    cout<< "This program will give an approximation for pi using math series\n";
    do{
    cout<<"Enter the number of terms you would like it approximated by:";
    cin>>n;
    pi=0;
    for (int terms=0; terms<n; terms++){
        pi+=4*((pow((-1),terms)/(2*terms+1)));
    }
    cout<<"The value of pi is "<<pi<<endl;
    cout<<"Do you want to calculate pi again? Y/N ";
    cin>>userinput;
    }
    
    while((userinput=='Y')||(userinput=='y'));

    return 0;
}

