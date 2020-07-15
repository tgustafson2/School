/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RetailItem.h
 * Author: tgust
 *
 * Created on April 30, 2019, 9:14 PM
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H
#include <string>
using namespace std;

class RetailItem{
private:
    string description;
    int unitsOnHand;
    double price;
public:
    RetailItem(string desc, int units, double cost){
        description=desc;
        unitsOnHand=units;
        price=cost;
    }
    void setdesc(string desc){
        description=desc;
    }
    void setunit(int units){
        unitsOnHand=units;
    }
    void setprice(double cost){
        price=cost;
    }
    string getdesc(){
        return description;
    }
    int getunits(){
        return unitsOnHand;
    }
    double getprice(){
        return price;
    }
};


#endif /* RETAILITEM_H */

