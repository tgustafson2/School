/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Population.h
 * Author: tgust
 *
 * Created on April 30, 2019, 10:16 PM
 */

#ifndef POPULATION_H
#define POPULATION_H
#include <cstdlib>
#include <iostream>
using namespace std;

class Population{
private:
    int pop;
    int deaths;
    int births;
    
public:
    Population(int, int, int);
    double getbirthr(){
        float birthr=births;
        float popr=pop;
    return birthr/popr;}
    double getdeathr(){
        float deathr=deaths;
        float popr=pop;
        return deathr/popr;
    }
};


#endif /* POPULATION_H */

