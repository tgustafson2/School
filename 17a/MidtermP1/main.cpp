/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on April 20, 2019, 12:00 AM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
struct Customer{
    char name [52];
    char address[52];
    int account;
    double balance;
    double checks;
    double deposits;
};



int main(int argc, char** argv) {
    int cnum, dnum;
    
    Customer *cust= new Customer;
    cust->checks=0;
    cust->deposits=0;
    cust->balance=0;
    cout<<"Enter the customer's name:";
    cin.getline(cust->name,52);
    cout<<"Enter the customer's address:";
    cin.getline(cust->address,52);
    int accnum;
    cout<<"Enter the customer's account number:";
    cin>>accnum;
    while(accnum>99999||accnum<10000){
        cout<<"Invalid account number. Please reenter number:";
        cin>>accnum;
    }
    cust->account=accnum;
    cout<<"Enter how many checks the customer has written:";
    cin>>cnum;
    double check;
    for ( int i=0; i<cnum; i++){
        cout<<"Enter the amount the check was written for:";
        cin>>check;
        cust->checks-=check;
    }
    cout<<"Enter how many deposits the customer has:";
    cin>>dnum;
    double deposit;
    for (int j=0; j<dnum;j++){
        cout<<"Enter the amount the deposit is for:";
        cin>>deposit;
        cust->deposits+=deposit;
    } 
    cust->balance=(cust->deposits+cust->checks);
    cout<<"Current balance:$ "<<cust->balance<<endl;
    if (cust->balance<0){
        cust->balance-=20;
        cout<<"Your account has been overdrawn, and will be accessed a fee."<<endl;
        cout<<"The new balance is: $"<<cust->balance;
    }

    return 0;
}

