/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on April 21, 2019, 5:49 PM
 */

#include <iostream>
#include <cmath>
using namespace std;

/*
 * 
 */
void encrypt();
void decrypt();
int main(int argc, char** argv) {
    char input;
    cout<<"Enter 0 to decrypt a number and 1 to encrypt a number:";
    
    cin>>input;
    if (input=='0'){
        decrypt();
    }
    else if (input=='1'){
        encrypt();
    }
    
    
    return 0;
}

void encrypt (){
    int input;
    int encrypt[4];
    cout<<"Enter the four digit number you wish to encrypt:";
    cin>>input;
    
    encrypt[3]=(input%10);
    encrypt[2]=((input/10)%10 );
    encrypt[1]=((input/100)%10 );
    encrypt[0]=((input/1000)%10 );
    for (int i=0; i<4; i++){
        encrypt[i]+=5;
        encrypt[i]%=8;
    }
    int temp1=encrypt[0];
    encrypt[0]=encrypt[2];
    encrypt[2]=temp1;
    int temp2=encrypt[1];
    encrypt[1]=encrypt[3];
    encrypt[3]=temp2;
    for (int j=0; j<4;j++){
        cout<<encrypt[j];
    }
}
void decrypt (){
    int dinput;
    int decrypt[4];
    cout<<"Enter the four digit number you wish to decrypt:";
    cin>>dinput;
    decrypt[3]=(dinput%10);
    decrypt[2]=((dinput/10)%10 );
    decrypt[1]=((dinput/100)%10 );
    decrypt[0]=((dinput/1000)%10 );
    int temp1=decrypt[0];
    decrypt[0]=decrypt[2];
    decrypt[2]=temp1;
    int temp2=decrypt[1];
    decrypt[1]=decrypt[3];
    decrypt[3]=temp2;
    for (int i=0; i<4; i++){
        decrypt[i]=((decrypt[i]-5)%8);
        if (decrypt[i]<0){
            decrypt[i]+= 8;
        }
    }
    for (int j=0; j<4;j++){
        cout<<decrypt[j];
    }

}