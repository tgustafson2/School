/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Prob1Random.h"
using namespace std;

Prob1Random::Prob1Random(const char nset, const char* set){

    
    this->set=new char[nset];
    this->nset=nset;
    freq=new int[nset];
    numRand=0;
    for (int i=0; i<nset; i++){
        this->set[i]=set[i];
        freq[i]=0;
    }
    unsigned seed= time(0);
    srand(seed);
}
Prob1Random::~Prob1Random(){
    delete[]set;
    delete[]freq;
    
}
char Prob1Random::randFromSet(){
    
    int arracc=(rand()%5);
    freq[arracc]++;
    char rand= set[arracc];
    numRand++;
    return rand;
}
int* Prob1Random::getFreq() const{
    return freq;
}
char* Prob1Random::getSet() const{
    return set;
}
int Prob1Random::getNumRand() const{
    return numRand;
}