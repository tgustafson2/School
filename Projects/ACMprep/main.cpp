/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on September 5, 2020, 5:00 PM
 */
//System Libraries
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void fromDeci();

//Execution Begins Here

int main(int argc, char** argv) {
    //Set random number seed here

    //Declare Variables
    int problems;
    vector <int> base;
    vector <string>num;
    //Initialize Variables
    cin>>problems;
    //Process inputs to outputs/map
    for (int i=0; i<problems;i++){
        int b;
        string n;
        cin>>b;
        cin>>n;
        base.push_back(b);
        num.push_back(n);
    }
    for (int i=0; i<problems;i++){
        int answ=0;
        
        for (int j=0; j<=num[i].size();j++){
            if (num[i][j]>='0'&&num[i][j]<='9'){
                cout<<(int(num[i][j])-48)*pow(base[i],num[i].size()-j-1)<<endl;
                answ+=(int(num[i][j])-48)*pow(base[i],num[i].size()-j-1);
            }
            else
                answ+=(int(num[i][j])-55)*pow(base[i],num[i].size()-j-1);
        }
        cout<<answ<<endl;
    }
    //Display the results

    //Clean up and exit stage right
    return 0;
}
void fromDeci(){
        int problems;
    vector <int> base, num;
    //Initialize Variables
    cin>>problems;
    //Process inputs to outputs/map
    for (int i=0; i<problems;i++){
        int b,n;
        cin>>b>>n;
        base.push_back(b);
        num.push_back(n);
    }
    
    for (int i=0; i<problems; i++){
        
        vector <int> conv;
        
        do {
           
            conv.push_back(num[i]%base[i]);
            
            num[i]/=base[i];
         
            
        }while(num[i]>=base[i]);
        conv.push_back(num[i]);
        for (int j=conv.size()-1; j>=0; j--){
            if (conv[j]<10)
            cout<<conv[j];
            else{
                char a;
                a=conv[j]+55;
                cout<<a;
            }
                
        }
        cout<<endl;
        
    }
}