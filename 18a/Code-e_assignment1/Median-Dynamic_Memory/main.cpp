/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on March 12, 2019, 11:38 PM
 */

#include <iostream>
#include <iomanip>


using namespace std;

/*
 * 
 */
int * getdata(int &);
void printdata(int *, int);
float * getmedian(int *, int);
void printmed (float*);


int main(int argc, char** argv) {
    int size=0;
    int * datarr=nullptr;
    float * medianarr=nullptr;
    datarr=getdata(size);
    printdata(datarr, size);
    
    
    medianarr= getmedian(datarr, size);
    
    
    printmed (medianarr);
    
    delete [] datarr;
    delete [] medianarr;
         

    return 0;
}

int * getdata(int &size){
    int * data=nullptr;
    cin>>size;
    data= new int [size];
    for (int i=0; i<size; i++){
        cin>>*(data+i);
    }
    return data;
}

void printdata(int * data, int size){
    for (int j=0; j<size;j++){
        cout<<*(data+j);
        if (j<size-1){
            cout<<" ";
        }
    }
    cout<<endl;
    
}

float * getmedian (int * data, int size){
    
    float * median=nullptr;
    float medianval=0;
    median=new float [size+2];
    *median=(size+2);
    
    
    if ((size%2)==1){
        
        medianval=*(data+(size/2));
        
        
    }
    else if ((size%2)==0){
        medianval= *(data+(size/2))+*(data+(size/2)-1);
        medianval=medianval/2;
        
        
        
    }
    
    *(median+1)=medianval;
    for (int i=0; i<size; i++){
        *(median+2+i)=*(data+i);
    }

    return median;
}

void printmed (float * median){
    int size=*median;
    
    cout<<*median<<" ";
    for (int j=1; j<size; j++){
        cout<<fixed<<setprecision(2)<<*(median+j);
        if(j<size-1){
        cout<<" ";
        }
    }
    
}
