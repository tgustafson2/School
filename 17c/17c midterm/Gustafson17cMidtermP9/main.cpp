/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on October 26, 2019, 12:15 AM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    srand (static_cast<unsigned int>(time(0)));
    float prob=pow(.3,5);//5!/5!*(.7^0)*(.3^5)
    int count =0;
    for (int i=0; i<100000; i++){
        int full=0;
        for (int j=0; j<5; j++){
            int num=rand()%10;
            if (num<3)full+=1;
        }
        if (full==5)count++;
    }
    cout<<"Simulation results are "<<count<<" out of 100000 or "<<(float)count/100000<<endl;
    cout<<"The probability of a 5 bits randomly falling in the filled section is:"<<prob<<endl;

    return 0;
}

