/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Math_Tutor.cpp
 * Author: tgust
 *
 * Created on February 24, 2019, 11:41 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

/*
 * 
 */
int main() {
    //declare constants for min and max value, int variables to hold number
    const int min_value = 1;
    const int max_value = 1000;
    int num1, num2;
    //get system time
    unsigned seed = time(0);
    //seed the random number generator
    srand (seed);
    //ouput program purpose and find random numbers
    cout<<"This program will help teach addition\n";
    num1 = (rand() % (max_value-min_value +1))+ min_value;
    num2 = (rand() % (max_value-min_value +1))+ min_value;
    //output random numbers and add them
    cout<<"Once you have found your answer press enter to find the correct one.\n";
    cout<<num1<<endl;
    cout<<"+"<<num2;
    cin.get();
    cout<<num1+num2;

    return 0;
}

