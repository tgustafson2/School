/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumDays.h
 * Author: tgust
 *
 * Created on May 12, 2019, 12:11 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H



class NumDays{
private:
    static float workday;
    float days;
    int hours;
    void setDays(){
        days=hours/workday;
    }
public:
    NumDays(): NumDays (0){}
    NumDays(int hours){
        this->hours=hours;
        setDays();
    }
    void setHours(int hours){
        this->hours=hours;
        setDays();
    }
    int getHours(){
        return hours;
    }
    float getDays(){
        return days;
    }
    NumDays operator +(const NumDays &);
    NumDays operator -(const NumDays &);
    NumDays operator ++();
    NumDays operator ++(int);
    NumDays operator --();
    NumDays operator --(int);
};



#endif /* NUMDAYS_H */

