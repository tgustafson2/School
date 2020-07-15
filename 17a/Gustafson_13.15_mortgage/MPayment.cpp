/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "MPayment.h"
#include <cmath>





void MPayment::setterm(){
    float inner=(1+rate/12);
    term=pow(inner,(12*years));
}
void MPayment::setpay(){
    setterm();
    
    pay=loan*rate*term/(12*(term-1));
}