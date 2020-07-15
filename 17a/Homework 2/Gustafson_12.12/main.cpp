/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on April 6, 2019, 10:17 PM
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
    double qrtsales[4];
    double divtotal;
    double totsales=0;
    double divaverage;
    double high, low;
    fstream sales;
    DivSales dat[qrt];
    
    
    sales.open("sales.dat", ios::in| ios::binary);
    for (int i=0; i<qrt; i++){
        divtotal=0;
        for (int j=0; j<qrt; j++){
        sales.read (reinterpret_cast<char *> (&dat[i]), sizeof(dat));
        divtotal+=dat[i].sales[j];
        totsales+=dat[i].sales[j];
        if (i==0&j==0){
            high=dat[i].sales[j];
            low=dat[i].sales[j];
        }
        else if (high<dat[i].sales[j]){
            high=dat[i].sales[j];
        }
        else if (low>dat[i].sales[j]){
            low=dat[i].sales[j];
        }
        if (j==0){
            qrtsales[j]=dat[i].sales[j];
        }
        else if (j==1){
            qrtsales[j]=dat[i].sales[j];
        }
        else if (j==2){
            qrtsales[j]=dat[i].sales[j];
        }
        else if (j==3){
            qrtsales[j]=dat[i].sales[j];
        }
        
        }
        divaverage=divtotal/qrt;
        cout<<"The average quarterly sales for "<<dat[i].name<<" division"
                " are:$"<<divaverage;
        cout<<"The total sales for "<<dat[i].name<<" division"
                " are:$"<<divtotal;
                
    }
    cout<<"The total corporate sales are:$"<<totsales<<endl;
    for (int k=0; k<qrt; k++){
        cout<<"The totals sales for Quarter "<<k<<" are:$ "<<qrtsales[k]<<endl;
    }
    sales.close();
    

    return 0;
}

