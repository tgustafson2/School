/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procedure.h
 * Author: tgust
 *
 * Created on April 30, 2019, 11:29 PM
 */

#ifndef PROCEDURE_H
#define PROCEDURE_H
#include <iostream>
using namespace std;
class Procedure{
private:
    string procedure;
    string date;
    string practioner;
    float charges;
public:
    Procedure(string a, string b, string c, float d){
        procedure=a;
        date=b;
        practioner=c;
        charges=d;
    }
    void setprocedure(string a){
        procedure=a;
    }
    void setdate(string a){
        date=a;
    }
    void setpractioner(string a){
        practioner=a;
        
    }
    void setcharges(float a){
        charges=a;
    }
    string getprocedure(){
        return procedure;
    }
    string getdate(){
        return date;
        
    }
    string getpractioner(){
        return practioner;
    }
    float getcharges(){
        return charges;
    }
};

#endif /* PROCEDURE_H */

