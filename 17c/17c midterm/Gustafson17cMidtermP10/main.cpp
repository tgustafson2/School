/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on October 26, 2019, 12:27 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int power (int, int);

int main(int argc, char** argv) {
    
    int base, n;
    cout<<"Enter base and power:";
    cin>>base>>n;
    cout<<base<<"^"<<n<<" is "<<power(base,n);
    
    

    return 0;
}
int power (int base, int n){
    int x;
    if (n==0)return 1;
    if (n%2==0){
        x=power(base,n/2);
        return x*x;
    }
    else return base*power(base, n-1);
}

