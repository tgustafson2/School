/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on April 21, 2019, 4:47 PM
 */

#include <iostream>
#include <cmath>

using namespace std;

/*
 * 
 */
struct Prime{
    int prime;
    int power;
};
struct Primes{
    Prime *prime;
    int nPrimes;
};
Primes *factor(int);
void prntPrm (Primes*);
int main(int argc, char** argv) {
    int num=0;
    cout<<"Enter and integer between 2 and 10000:";
    
    cin>>num;
    cout<<"before leaving";
    Primes *factordat=factor(num);
    cout<<num<<" = ";
    prntPrm(factordat);

    return 0;
}
Primes *factor(int num){
    cout<<"before dynamic allocation.";
    Primes *factors=new Primes;
    for (int i=2; i<=num; i++){
        int pcounter=0;
        cout<<"in for loop";
        if (num %i ==0){
        pcounter++;
        factors->nPrimes=pcounter;}
        while (num % i ==0){
            num/=i;
            
            factors->prime->power +=1;
            factors->prime->prime=i;
            
        }
        
    }
    return factors;
}
void prntPrm (Primes* factors){
    for (int i=0; i<(factors->nPrimes); i++){
        cout<<(factors->prime->prime)<<"^"<<(factors->prime->power)<<" * ";
    }
}
