/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumArr.h
 * Author: tgust
 *
 * Created on May 2, 2019, 3:25 PM
 */

#ifndef NUMARR_H
#define NUMARR_H
#include <iostream>
using namespace std;

class NumArr{
private:
    float * num;
    float average;
    float max;
    float min;
    int size;
    void setmax(){
        for (int i; i<size; i++){
            if (max<num[i]){
                max=num[i];
            }
        }
    }
    void setmin(){
        for (int i; i<size; i++){
            if (min>num[i]){
                min=num[i];
            }
        }
    }
    void setavg(){
        for (int i=0; i<size; i++){
            average+=num[i];
        }
        average/=size;
    }
public:
    NumArr(int index){
        num=new float (index);
        size=index;
        average=0;
    }
    ~NumArr(){
        delete[] num;
        
    }
    void fillarr(){
        
        for (int index=0; index<size; index++){
            cout<<"Enter a number:";
            cin>>num[index];}
        max=num[0];
        min=num[0];
        
        setmax();
        setmin();
        setavg();
    }
    float getmax(){
        return max;
    }
    float getmin(){
        return min;
    }
    float getavg(){
        return average;
    }
    float getnum(int i){
        return num[i];
    }
    
};

#endif /* NUMARR_H */

