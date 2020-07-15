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
    Date(int x, int y, int z)
    {
        month=x;
        day=y;
        year=z;
    }
    void numdate();
    void stddate();
    void date();
};


#endif /* DATE_H */

