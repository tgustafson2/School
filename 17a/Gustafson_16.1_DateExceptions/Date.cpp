/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Date.h"
#include <iostream>

using namespace std;

void Date:: numdate(){
    cout<<month<<"/"<<day<<"/"<<year<<endl;
}
void Date:: stddate(){
    if (month==1){
        cout<<"January ";
    }
    else if (month==2){
        cout<<"February ";
    }
    else if (month==3){
        cout<<"March ";
    }
    else if (month==4){
        cout<<"Aril ";
    }
    else if (month==5){
        cout<<"May ";
    }
    else if (month==6){
        cout<<"June ";
    }
    else if (month==7){
        cout<<"July ";
    }
    else if (month==8){
        cout<<"August ";
    }
    else if (month==9){
        cout<<"September ";
    }
    else if (month==10){
        cout<<"October ";
    }
    else if (month==11){
        cout<<"November ";
    }
    else if (month==12){
        cout<<"December ";
    }
    cout<<day<<", "<<year<<endl;
}
void Date:: date(){
    cout<<day<<" ";
    if (month==1){
        cout<<"January ";
    }
    else if (month==2){
        cout<<"February ";
    }
    else if (month==3){
        cout<<"March ";
    }
    else if (month==4){
        cout<<"Aril ";
    }
    else if (month==5){
        cout<<"May ";
    }
    else if (month==6){
        cout<<"June ";
    }
    else if (month==7){
        cout<<"July ";
    }
    else if (month==8){
        cout<<"August ";
    }
    else if (month==9){
        cout<<"September ";
    }
    else if (month==10){
        cout<<"October ";
    }
    else if (month==11){
        cout<<"November ";
    }
    else if (month==12){
        cout<<"December ";
    }
    cout<<year<<endl;
}
