/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on July 16, 2020, 6:13 PM
 */
//System Libraries
#include <iostream>
#include <ctime>
#include "Sort.h"
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes


//Execution Begins Here

int main(int argc, char** argv) {
    //Set random number seed here
    srand(time(0));
    //Declare Variables
    int size=50;
    int *arr=new int[size];
    //Initialize Variables
    for (int i=0;i<size;i++){
        arr[i]=rand()%100;
    }
    Sort<int>::ShellSort(arr,size);
    //Process inputs to outputs/map
    

    //Display the results
    for (int i=0; i<size;i++){
        cout<<arr[i]<<' ';
        if (i%10==9)cout<<endl;
    }
    //Clean up and exit stage right
    return 0;
}
