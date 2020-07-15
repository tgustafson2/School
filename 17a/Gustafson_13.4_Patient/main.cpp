/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on April 30, 2019, 11:26 PM
 */

#include <cstdlib>
#include <iostream>
#include "Patient.h"
#include "Procedure.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Patient sample();
    Procedure psamp[]={
        Procedure ("Physical Exam","4/30/19","Dr.Irvine",250),
        Procedure ("X-ray", "4/30/19", "Dr. Jamison",500),
        Procedure ("Blood Test", "4/30/19", "Dr. Smith", 200)
    };
    for (int i=0; i<3; i++){
       cout<<psamp[i].getprocedure()<<endl;
       cout<<psamp[i].getdate()<<endl;
       cout<<psamp[i].getpractioner()<<endl;
       cout<<psamp[i].getcharges()<<endl;
               
    }

    return 0;
}

