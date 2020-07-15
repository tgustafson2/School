/* 
 * File:   main.cpp
 * Author: Gustafson
 * Created on March 2, 2019 8;36
 * Purpose:  Histogram
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    char first, second, third, fourth;
    const char min=0;
    const char max=9;

    
    //Input or initialize values Here
    cout<<"Create a histogram chart."<<endl;
    cout<<"Input 4 digits as characters."<<endl;
    cin>>first>>second>>third>>fourth;

    
    //Histogram Here
   
    
    
    cout<<fourth<<" ";
    if (fourth>='0'&&fourth<='9'){
        for (int count=fourth-48; count>0;count--){
            cout<<"*";
        }
        cout<<endl;
    }
    else cout<<"?"<<endl;
    cout<<third<<" ";
    if (third>='0'&&third<='9'){
        for (int count=third-48; count>0;count--){
            cout<<"*";
        }
        cout<<endl;
    }
    else cout<<"?"<<endl;
    cout<<second<<" ";
    if (second>='0'&&second<='9'){
        for (int count=second-48; count>0;count--){
            cout<<"*";
        }
        cout<<endl;
    }
    else cout<<"?"<<endl;
    

    cout<<first<<" ";
    if (first>='0'&&first<='9'){
        for (int count=first-48; count>0;count--){
            cout<<"*";
        }
        cout<<endl;
    }
    else cout<<"?"<<endl;
    //Exit
    return 0;
}