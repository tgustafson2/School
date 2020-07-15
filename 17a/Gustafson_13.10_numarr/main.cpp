/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on May 2, 2019, 3:25 PM
 */

#include <cstdlib>
#include <iostream>
#include "NumArr.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int size, pull;
    cout<<"Enter how many numbers you want to input:";
    cin>>size;
    NumArr array(size);
    array.fillarr();
    cout<<"The max is "<<array.getmax()<<endl;
    cout<<"The min is "<<array.getmin()<<endl;
    cout<<"The average is "<<array.getavg()<<endl;
    cout<<"Enter the element you want returned:";
    cin>>pull;
    cout<<"The element is: "<<array.getnum(pull);

    return 0;
}

