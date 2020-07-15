/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on April 30, 2019, 9:13 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "RetailItem.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    RetailItem stock[]={
        RetailItem("Jacket", 12, 59.95),
        RetailItem("Designer Jeans", 40, 34.95),
        RetailItem("Shirt", 20, 24.95)
    };
    for (int i=0; i<3; i++){
        cout<<setw(14)<<stock[i].getdesc();
        cout<<setw(5)<<stock[i].getunits();
        cout<<setw(8)<<stock[i].getprice()<<endl;
    }

    return 0;
}

