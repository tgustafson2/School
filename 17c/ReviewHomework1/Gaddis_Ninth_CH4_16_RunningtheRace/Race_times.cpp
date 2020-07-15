/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Race_times.cpp
 * Author: tgust
 *
 * Created on February 24, 2019, 10:59 AM
 */

#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main() {
    double time [3];
    string runner [3];
    int index, maxElement;
    //prompt user for input of names and times into arrays
    for (index=0; index<3; index++){
    cout<<"Enter the name of the runner:";
    cin>>runner[index];
    cout<<"Enter the time of the runner in seconds:";
    cin>>time[index];
    if (time[index]<0){
        cout<<"Invalide time, please reenter time:";
                cin>>time[index];
    }
    }
    //sort arrays using parallel arrays to maintain correct order
    for( maxElement=2; maxElement>0; maxElement--){
    for(index=0; index<maxElement; index++){
        if(time[index]>time[index+1]){
            double temp1;
            string temp2;
            temp1=time[index];
            time[index]=time[index+1];
            time[index+1]=temp1;
            
            temp2=runner[index];
            runner [index]=runner [index+1];
            runner [index+1]=temp2;
        }
    }
    }
    //Output results
    cout<<runner[0]<<" has the fastest time at "<< time[0]<<" seconds.\n";
    cout<<runner[1]<<" has the 2nd fastest time at "<< time[1]<<" seconds.\n";
    cout<<runner[2]<<" has the 3rd fastest time at "<< time[2]<<" seconds.\n";

    return 0;
}

