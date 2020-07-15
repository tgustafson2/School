
/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on October 25, 2018, 8:58 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*
 * 
 */
int main() {
    float charges, weight, rate, miles;
    cout << "Enter weight in ounce (in ounces - Max 1800): ";
    cin>> weight;
    cout << "Enter miles shipping(max: 3500): ";
    cin>> miles;
   if ((miles<=3500)&& (miles>=0)){   
        if ((0<=weight) &&(weight<60)){
            rate=1.75;
            charges=rate*ceil(miles/525);
            cout<< setprecision(2)<< fixed;
            cout<< "\nShipping Charges: $"<<right<< setw(5) <<charges;
            
        }
        else if ((60<=weight)&&(weight<120)){
            rate=2.95;
            charges=rate*ceil(miles/525);
            cout<< setprecision(2)<< fixed;
            cout<< "\nShipping Charges: $"<<right<< setw(5) <<charges;
        }
        else if ((120<=weight)&&(weight<400)){
            rate=3.55;
            charges=rate*ceil(miles/525);
            cout<< setprecision(2)<< fixed;
            cout<< "\nShipping Charges: $"<<right<< setw(5) <<charges;
        }
        
        else if ((400<=weight)&&(weight<=1800)){
            rate=4.95;
            charges=rate*ceil(miles/525);
            cout<< setprecision(2)<< fixed;
            cout<< "\nShipping Charges: $"<<right<< setw(5) <<charges;
        }
        else
            cout<< "Weight out of range. Program terminating.";
    }
   else {
        cout<<"Shipping distance out of range. Program Terminating.";
    }

    return 0;
}

