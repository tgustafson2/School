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
#include <iostream>
using namespace std;
class Date;
ostream &operator << (ostream &, const Date &);
istream &operator >> (istream &, Date &);

class Date
{
private:
    int month;
    int day;
    int year;
    static int monthdays[12];
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
    
    int operator -(const Date &);
    Date operator ++();
    Date operator ++(int);
    Date operator --();
    Date operator --(int);
    friend ostream &operator <<(ostream &, const Date&);
    friend istream &operator >>(istream &, Date &);
};


#endif /* DATE_H */

