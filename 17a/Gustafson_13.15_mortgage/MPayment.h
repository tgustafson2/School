/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MPayment.h
 * Author: tgust
 *
 * Created on May 2, 2019, 6:30 PM
 */

#ifndef MPAYMENT_H
#define MPAYMENT_H
#include <cstdlib>
#include <iostream>
using namespace std;

class MPayment{
private:
    float term;
    float pay;
    float loan;
    float rate;
    int years;
    float total;
    void settotal(){
        total= pay*years*12;
    }
    void setterm();
    void setpay();
public:
    void setloan(float x){
        loan=x;
        if (loan<0){
            cout<<"Invalid loan amount.";
            exit (EXIT_FAILURE);
        }
    }
    void setrate(float x){
        rate=x;
        if (rate<0){
            cout<<"Invalid rate amount.";
            exit (EXIT_FAILURE);
        }
                        }
    void setyears(int x){
        years=x;
        if (years<0){
            cout<<"Invalid years.";
            exit (EXIT_FAILURE);
        }
    }
    float getpay(){
        setpay();
        return pay;
    }
    float gettotal(){
        setpay();
        settotal();
        return total;
    }
};


#endif /* MPAYMENT_H */

