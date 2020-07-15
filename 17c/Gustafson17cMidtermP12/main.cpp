/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on October 26, 2019, 12:37 AM
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */

double C(double);
double S(double);

int main(int argc, char** argv) {

    float pi=3.14;
    double x=pi/4;
    double resultC, resultS;
    
    resultC=C(x);
    resultS=S(x);
    cout<<fixed;
    cout<<"The outcome for function C:"<<resultC<<endl;
    cout<<"The outcome for function S:"<<resultS<<endl;
    
    
    
    
    
    return 0;
}

double C(double x){
    if (pow(10,-6)>abs(x))return ((1/x)+(x/6));
    else return (C(x/2)*S(x/2)/2);
}
double S(double x){
    if (pow(10,-6)>abs(x))return (1+(x*x)/2.0f);
    else return ((pow(C(x/2),2)*pow(S(x/2),2))/(pow(C(x/2),2)-pow(S(x/2),2)));
}

