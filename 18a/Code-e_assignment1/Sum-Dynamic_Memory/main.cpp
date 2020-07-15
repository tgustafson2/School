/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on March 15, 2019, 9:26 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */

int * getdata (int &);
int * sumAry (const int*, int);
void prntAry (const int*, int);




int main(int argc, char** argv) {
    int size=0;
    int* data=getdata(size);
    int* sum=sumAry(data, size);
    prntAry(data, size);
    cout<<endl;
    prntAry (sum, size);
    
    
    

    return 0;
}

int * getdata (int &size){
    cin>>size;
    int *data=new int [size];
    for (int i=0; i<size; i++){
        cin>>*(data+i);
    }
    return data;
}

int * sumAry (const int* data, int size){
    int * sum=new int [size];
    int sumcounter=0;
    for(int i=0; i<size; i++){
        sumcounter+=*(data+i);
        *(sum+i)=sumcounter;
    }
    return sum;
}

void prntAry (const int* data, int size){
    for (int i=0; i<size; i++){
        cout<<*(data+i);
        if (i<(size-1)){
            cout<<" ";
        }
    }
}