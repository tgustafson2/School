/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on March 15, 2019, 7:42 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */

int * getData(int &);
int * sort (const int*, int);
int * reverse (const int*, int);
void printdat(const int*, int);



int main(int argc, char** argv) {
    
    int size=0;
    int * Data=nullptr, *sortarr=nullptr, *reversearr=nullptr;
    Data=getData(size);
    sortarr=sort (Data, size);
    printdat(sortarr,size);
    reversearr=reverse(Data,size);
    printdat(reversearr, size);

    return 0;
}

int * getData(int &size){
    cin>>size;
    int * DatArr= new int [size];
    for (int i=0; i<size; i++){
        cin>>*(DatArr+i);
    }
    return DatArr;
}
int * sort (const int* Arr, int size){
    int * Data= new int [size];
    for (int j=0; j<size; j++){
        *(Data+j)=*(Arr+j);
    }
    for (int maxelement=size-1; maxelement>0; maxelement--){
        for (int index=0; index<maxelement; index++){
            if (*(Data+index)>*(Data+index+1)){
                int temp=*(Data+index);
                *(Data+index)=*(Data+index+1);
                *(Data+index+1)=temp;
            }
        }
    }
    return Data;
}
int * reverse (const int* Arr, int size){
    int * Data= new int [size];
    for (int j=0; j<size; j++){
        *(Data+j)=*(Arr+j);
    }
    for (int maxelement=size-1; maxelement>0; maxelement--){
        for (int index=0; index<maxelement; index++){
            if (*(Data+index)<*(Data+index+1)){
                int temp=*(Data+index);
                *(Data+index)=*(Data+index+1);
                *(Data+index+1)=temp;
            }
        }
    }
    return Data;
}
void printdat (const int* Data, int size){
    for (int i=0; i<size; i++){
        cout<<*(Data+i);
        if (i<size-1){
            cout<<" ";
        }
    }
    if (*Data<*(Data+(size-1))){
        cout<<endl;
    }
}