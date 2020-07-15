/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on March 15, 2019, 9:48 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int * getData(int &);
int * augment(const int*, int);
void prntAry(const int *, int);




int main(int argc, char** argv) {
    int * data=nullptr;
    int * augAry=nullptr;
    int size=0;
    data=getData(size);
    augAry=augment(data, size);
    prntAry(data, size);
    cout<<endl;
    size+=1;
    prntAry(augAry, size);

    return 0;
}


int * getData (int &size){
    cin>>size;
    int *data=new int [size];
    for (int i=0; i<size; i++){
        cin>>*(data+i);
    }
    return data;
}

int * augment (const int * data, int size){
    int * augAry= new int[size];
    *augAry=0;
    for (int i=1; i<=size; i++){
        *(augAry+i)=*(data+i-1);
    }
    return augAry;
}

void prntAry(const int * ary, int size){
    for (int i=0; i<size; i++){
        cout<<*(ary+i);
        if (i<(size-1)){
            cout<<" ";
        }
    }
}


