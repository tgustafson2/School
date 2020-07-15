/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on April 20, 2019, 12:19 AM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
struct ModeSt{
    int size;
    int *data;
};
struct Stats{
    
    float median;
    int modFreq;
    float mean;
    ModeSt *mode;
};

Stats *stat(const int *);
void swap(int *,int *);     
void maxPos(int *,int,int); 
void mrkSort(int *,int); 

int main(int argc, char** argv) {
    int size, modNum;
    cout<<"Enter the size of the array:";
    cin>>size;
    cout<<"Input the number of unique numbers:";
    cin>>modNum;
    int *array= new int [size];
    cout<<"Original Array"<<endl;
    
    for(int i=0;i<size;i++){
        *(array+i)=i%modNum;
        cout<<*(array+i)<<" ";
        if ((i%modNum)==(modNum-1)){
            cout<<endl;
        }
    }
    cout<<endl;
    mrkSort (array, size);
    Stats *Modedata=stat(array);

    return 0;
}

Stats *stat(const int *array){
    //Non-working stub to be completed by the student
    cout<<*array;
    cout<<endl<<"stat function to be completed by the student"<<endl;
    Stats *stats=new Stats;
    cout<<"After dynamic structure";
    stats->mode=new ModeSt;
    stats->mode->size=0;
    int nModes=0;
    
    stats->modFreq=1;
    stats->median=0;
    
    
    
    int maxfrequency=1;
    int frequencytracker=1;
    int i=0;
    cout<<"before while loop";
    while ((*array+i+1)>=0){
        
        if (*(array+i)==*(array+i+1)){
            frequencytracker+=1;
            if (maxfrequency<frequencytracker){
                maxfrequency=frequencytracker;
                
            }
            
        }
        else if (*(array+i)!=*(array+i+1)){
            frequencytracker=1;
        }
        i++;
    }
    cout<<"After frist while";
    int Arraysize=i;
    float total;
    for (int index=0; index<i;index++){
        
        total+=*(array+index);
    }
    stats->mean=(total/i);
    if ((i%2)==1){
        stats->median=(*array+(i/2));
        
    }
    else if ((i%2)==0){
        stats->median=((*array+(i/2))+(*array+(i/2)+1))/2;
    }
    cout<<"AFter median";
    int j=0;
     while ((*array+j+1)>=0){
        
        if (*(array+j)==*(array+(j+maxfrequency-1))){
            if (*(array+j)!=*(array+j+1)){
                nModes=0;
            
        }
            else{
                nModes+=1;
            }
            
        }
        j++;
    }
    stats->mode->data=new int[nModes];
    stats->mode->size=nModes;
    stats->modFreq=maxfrequency;
    int k=0;
    while (*array+k>=0){
        if (*(array+k)==*(array+k+maxfrequency-1)){
            int l=0;
            stats->mode->data[l]=*(array+k);
            l++;
        }
            
        k++;
    }
    
    return stats;
}
void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        maxPos(array,n,i);
    }
}

void maxPos(int *array,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(*(array+pos)<*(array+i))
            swap(array+pos,array+i);
    }
}

void swap(int *a,int *b){
    
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}