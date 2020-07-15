/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on May 18, 2019, 7:39 PM
 */

#include <cstdlib>
#include <iostream>


using namespace std;

/*
 * 
 */
template <class T>
T minima(T val1, T val2){
    if (val1<=val2){
        return val1;
    }
    else return val2;
}
template <class T>
T maxima(T val1, T val2){
    if (val1>=val2){
        return val1;
    }
    else return val2;
}






int main(int argc, char** argv) {

    int val1, val2;
    double val3, val4;
    float val5, val6;
    
    cout<<"Enter a two integer values:";
    cin>>val1>>val2;
    cout<<"The larger value is "<<maxima(val1, val2)<<endl;
    cout<<"The smaller value is "<<minima(val1, val2)<<endl;
    cout<<"Enter a two values:";
    cin>>val3>>val4;
    cout<<"The larger value is "<<maxima(val3, val4)<<endl;
    cout<<"The smaller value is "<<minima(val3, val4)<<endl;
    cout<<"Enter a two values:";
    cin>>val5>>val6;
    cout<<"The larger value is "<<maxima(val5, val6)<<endl;
    cout<<"The smaller value is "<<minima(val5, val6)<<endl;
    
    return 0;
}

