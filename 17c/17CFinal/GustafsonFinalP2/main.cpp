/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Dec 2, 2019, 8:11 PM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
//int sinhc,coshc;

float h(float,stack<int>&,stack<int>&);
float g(float,stack<int>&,stack<int>&);

int main(int argc, char** argv) {
    //Testing out recursive trig functions
//    float angDeg=45;
//    float angRad=angDeg*atan(1)/45;
//    sinhc=0,coshc=0;
    float angRad;
    float angDeg;
    stack<int>sin;
    stack<int>cos;
    for(angRad=1;angRad>-1.1;angRad-=.1){
        
    angDeg=angRad*180/(atan(1)*4);
    sin.push(0);
    cos.push(0);
    cout<<"Angle = "<<angRad<<" sinh = "<<sinh(angRad)<<
            " our h = "<<h(angRad,sin,cos)<<endl;
    cout<<"The number of sin function calls is "<<sin.top()<<endl<<"The number of cos function calls is "<<cos.top()<<endl;
    sin.pop();
    cos.pop();
    sin.push(0);
    cos.push(0);
    cout<<"Angle = "<<angRad<<" cosh = "<<cosh(angRad)<<
            " our g = "<<g(angRad,sin,cos)<<endl;
    cout<<"The number of sin function calls is "<<sin.top()<<endl<<"The number of cos function calls is "<<cos.top()<<endl;
    sin.pop();
    cos.pop();
}
//    cout<<sinhc<<endl<<coshc<<endl;
    //Exit stage right
    return 0;
}

float h(float angR,stack<int>& sin,stack<int>&cos){
    float tol=1e-6;
//    sinhc++;
    int c=sin.top();
    sin.pop();
    sin.push(c+1);
    if(angR>-tol&&angR<tol)return angR+angR*angR*angR/6;
    return 2*h(angR/2,sin,cos)*g(angR/2,sin,cos);
}
float g(float angR,stack<int>& sin,stack<int>&cos){
    float tol=1e-6;
//    coshc++;
    int c=cos.top();
    cos.pop();
    cos.push(c+1);
    if(angR>-tol&&angR<tol)return 1+angR*angR/2;
    float b=h(angR/2,sin,cos);
    return 1+2*b*b;
}