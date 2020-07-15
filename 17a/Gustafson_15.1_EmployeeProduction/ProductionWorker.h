/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProductionWorker.h
 * Author: tgust
 *
 * Created on May 17, 2019, 5:29 PM
 */

#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H
#include "Employee.h"
using namespace std;

class ProductionWorker: public Employee
{
private:
        int shift;
        double payrate;
        
public:
    ProductionWorker(int shift, double payrate, string name, int number, string date):
    Employee(name, number, date){
        setshift(shift);
        setpayrate(payrate);
    }
    void setshift(int shift){
        this->shift=shift;
    }
    void setpayrate(double payrate){
        this->payrate=payrate;
    }
    int getshift(){
        return shift;
    }
    double getrate(){
        return payrate;
    }
    
    
            
};


#endif /* PRODUCTIONWORKER_H */

