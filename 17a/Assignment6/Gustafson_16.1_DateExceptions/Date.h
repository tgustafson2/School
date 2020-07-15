/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.h
 * Author: tgust
 *
 * Created on April 30, 2019, 8:09 PM
 */

#ifndef DATE_H
#define DATE_H
class Date
{
private:
    int month;
    int day;
    int year;
public:
    class InvalidDay{
    
    private:
        int value;
    public:
        InvalidDay(int val){
            value=val;
        }
        int getval(){
            return value;
        }
        
        
    };
    class InvalidMonth{
    
    private:
        int value;
    public:
        InvalidMonth(int val){
            value=val;
        }
        int getval(){
            return value;
        }
        
       };
    Date(int x, int y, int z)
    {
        if (x<13&&x>0){
        month=x;}
        else
            throw InvalidMonth(x);
        if (y>0&&y<31){
        day=y;}
        else throw InvalidDay(y);
        year=z;
    }
    
    void numdate();
    void stddate();
    void date();
    
};


#endif /* DATE_H */

