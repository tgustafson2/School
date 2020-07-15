/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimeOff.h
 * Author: tgust
 *
 * Created on May 12, 2019, 3:13 PM
 */

#ifndef TIMEOFF_H
#define TIMEOFF_H
#include <iostream>
#include "NumDays.h"

using namespace std;


class TimeOff{
private:
    NumDays maxSickDays;
    NumDays sickTaken;
    NumDays maxVacation;
    NumDays vacTaken;
    NumDays maxUnpaid;
    NumDays unpaidTaken;
    string name;
    int id;
public:
    TimeOff(int smax, int staken, int vmax, int vtaken, int umax, int utaken, string name, int id){
        this->name=name;
        this->id=id;
        
        setsmax(smax);
        setstaken(staken);
        setvmax(vmax);
        setvtaken(vtaken);
        setumax(umax);
        setutaken(utaken);
    }
    int getsmaxHours(){
        return maxSickDays.getHours();
    }
    float getsmaxDays(){
        return maxSickDays.getDays();
    }
    int getstakenHours(){
        return sickTaken.getHours();
    }
    float getstakenDays(){
        return sickTaken.getDays();
    }
    int getvmaxHours(){
        return maxVacation.getHours();
    }
    float getvmaxDays(){
        return maxVacation.getDays();
    }
    int getvtakenHours(){
        return vacTaken.getHours();
    }
    float getvtakenDays(){
        return vacTaken.getDays();
    }
    int getumaxHours(){
        return maxUnpaid.getHours();
    }
    float getumaxDays(){
        return maxUnpaid.getDays();
    }
    int getutakenHours(){
        return unpaidTaken.getHours();
    }
    float getutakenDays(){
        return unpaidTaken.getDays();
    }
    string getname(){
        return name;
    }
    int getid(){
        return id;
    }
    void setsmax(int hours){
        maxSickDays.setHours(hours);
    }
    void setstaken(int hours){
        sickTaken.setHours(hours);
    }
    void setvmax(int hours){
        while (hours>240){
            cout<<"Company policy states that an employee may not accumulatele more than"<<endl
                    <<" 240 hours of paid vacation. Reenter valid amount:";
            cin>>hours;
        }
        maxVacation.setHours(hours);
    }
    void setvtaken(int hours){
        vacTaken.setHours(hours);
    }
    void setumax (int hours){
        maxUnpaid.setHours(hours);
    }
    void setutaken (int hours){
        unpaidTaken.setHours(hours);
    }
    void setname(string name){
        this->name=name;
    }
    void setid(int id){
        this->id=id;
    }
    
    
};



#endif /* TIMEOFF_H */

