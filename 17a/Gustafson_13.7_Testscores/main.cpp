/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on April 30, 2019, 9:40 PM
 */

#include <cstdlib>
#include "TestScores.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int test1, test2, test3;
    cout<<"Enter score:";
    cin>>test1;
    cout<<"Enter score:";
    cin>>test2;
    cout<<"Enter score:";
    cin>>test3;
    TestScores student(test1, test2, test3);
    cout<<setprecision(3);
    cout<<"The average is: "<<student.getaverage();

    return 0;
}

