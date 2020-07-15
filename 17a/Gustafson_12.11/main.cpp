/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on April 6, 2019, 9:07 PM
 */

#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
const int qrt=4;

struct DivSales{
    string name;
    int quarter[qrt];
    double sales[qrt];
    
};







int main(int argc, char** argv) {
    DivSales salefig[qrt];
    fstream sales;
    
    
    sales.open("sales.dat", ios::out| ios::binary);
    for (int i=0; i<qrt; i++){
        cout<<"Enter the Divison name:";
        cin>>salefig[i].name;
        
        
        for (int j=0; j<qrt; j++){
            cout<<"Enter the quarter:";
            cin>>salefig[i].quarter[j];
            cout<<"Enter the sale for the quarter:$";
            
            cin>>salefig[i].sales[j];
            if (salefig[i].sales[j]<0){
                cout<<"Please enter positive sales:";
                cin>>salefig[i].sales[j];
                       
            }
            
            sales.write(reinterpret_cast<char *> (&salefig[i]),sizeof(salefig[i]));
            
            
        }
    }
    sales.close();

    return 0;
}

