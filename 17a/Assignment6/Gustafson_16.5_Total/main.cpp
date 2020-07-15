/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on May 18, 2019, 8:45 PM
 */

#include <cstdlib>
#include <iostream>


using namespace std;

/*
 * 
 */
template <class T>
T total(T input){
    T total=0.0;
    for (int i=0; i<input; i++){
        T  x;
        cout<<"Enter a value: ";
        cin.ignore();
        cin>>x;
        total+=x;
    }
    cout<<endl;
    return total;
}



int main(int argc, char** argv) {

    int input;
    cout<<"Enter how many values you wish to total:";
    cin>>input;

    
    cout<<total(input)<<" is the total"<<endl;
    cout<<"Enter how many values you wish to total:";
    float input2;
    cin>>input2;
    cout<<total(input2)<<" is the total"<<endl;
    cout<<"Enter how many values you wish to total:";
    double input3;
    cin>>input3;
    cout<<total(input3)<<" is the total"<<endl;
    
    
    
    
    return 0;
}

