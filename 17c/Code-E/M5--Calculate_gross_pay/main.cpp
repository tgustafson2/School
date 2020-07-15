/* 
 * File:   main.cpp
 * Author: Thomas Gustafson
 * Created on March 2, 2019
 * Purpose:  Overtime
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here
#include <cmath>

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float payRate, paycheck;
    unsigned short hrsWrkd;
    
    //Input or initialize values Here
    cout<<"Paycheck Calculation."<<endl;
    cout<<"Input payRate in $'s/hour and hours worked"<<endl;
    cin>>payRate>>hrsWrkd;
    
    //Calculate Paycheck
    if (hrsWrkd<20){
        paycheck=payRate*hrsWrkd;
    }
    else if (hrsWrkd>20&&hrsWrkd<40){
        paycheck=20*payRate;
        paycheck+=(1.5*payRate*(hrsWrkd-20));
        
        
    }
    else if (hrsWrkd>40){
        paycheck=20*payRate;
        paycheck+=(1.5*payRate*20);
        paycheck+=(2*payRate*(hrsWrkd-40));
    }

    
    //Output the check
    cout<<fixed<<setprecision(2)<<"$"<<paycheck<<endl;
    
    
    //Exit
    return 0;
}