/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Payroll.h
 * Author: tgust
 *
 * Created on May 2, 2019, 4:55 PM
 */

#ifndef PAYROLL_H
#define PAYROLL_H
#include <cstdlib>
#include <iostream>
using namespace std;
class Payroll{
private:
    float rate;
    float hours;
    float salary;
    
public:
    void setpay (float x, float y){
        rate=x;
        hours=y;
        if (hours>60){
            cout<<"Invalid Input";
            exit (EXIT_FAILURE);
        }
        salary=x*y;
    }
    float getsalary(){
        return salary;
    }
    
};


#endif /* PAYROLL_H */

