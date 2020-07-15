/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on October 26, 2019, 12:31 AM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

/*
 * 
 */

float gRecur(float);

int main(int argc, char** argv) {
    
    float x=0.5;
    float result;
    result=gRecur(x);
    cout<<"Result:"<<result<<endl;
    
    
    

    return 0;
}

float gRecur(float x){
    if (pow(10,-6)>abs(x/2))return (x-(pow(x,3)/3));
    else return (2*gRecur(x/2))/(1+pow(gRecur(x/2),2));
}

