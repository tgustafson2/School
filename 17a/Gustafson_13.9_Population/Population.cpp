/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Population.h"
#include <iostream>
#include <cstdlib>
using namespace std;
Population::Population(int x, int y, int z){
    if (x>0&&y>0&&z>0){
        pop=x;
        deaths=y;
        births=z;}
        else {
            cout<<"Invalid input\n";
            exit (EXIT_FAILURE);
        }
}