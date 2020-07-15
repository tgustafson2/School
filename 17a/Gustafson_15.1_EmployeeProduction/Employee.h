/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: tgust
 *
 * Created on May 17, 2019, 5:18 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

using namespace std;


class Employee{
private:
    string name;
    int number;
    string hdate;
public:
    Employee(){
        Employee("",0,"");
    }
    Employee (string name, int num, string date){
        setname(name);
        setnumber(num);
        sethdate(date);
    }
    void setname(string name){
        this->name=name;
    }
    void setnumber(int num){
        number=num;
    }
    void sethdate( string date){
        hdate=date;
    }
    string getname(){
        return name;
    }
    int getnumber(){
        return number;
    }
    string gethdte(){
        return hdate;
    }
    
};

#endif /* EMPLOYEE_H */

