/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on April 20, 2019, 9:06 PM
 */

#include <iostream>
#include <iomanip>


using namespace std;

/*
 * 
 */
struct EmployeePay{
    char name[52];
    double hours;
    double payrate;
    double totalpay;
    
};
int main(int argc, char** argv) {
    char comname[52];
    cout<<"Enter the Company's name:";
    cin.getline(comname,52);
    char address[52];
    cout<<"Enter the company's address:";
    cin.getline(address,52);
    double payrate, hours;
    do {
        EmployeePay *paycheck=new EmployeePay;
        double pay;
        cout<<"Enter the employee name:";
        cin.getline(paycheck->name,52);
        cout<<"Enter their rate of pay:";
        cin>>payrate;
        paycheck->payrate=payrate;
        cout<<"Enter their hours worked:";
        cin>>hours;
        paycheck->hours=hours;
        if (hours<40){
            pay=((paycheck->payrate)*(paycheck->hours));
        }
        else if (hours>=40&&hours<50){
            
            pay=((paycheck->payrate)*((paycheck->hours)-40)*2);
            pay+=((paycheck->payrate)*40);
        }
        else if (hours >=50){
            pay=((paycheck->payrate)*40);
            pay+=((paycheck->payrate)*2*10);
            pay+=((paycheck->payrate)*((paycheck->hours)-50)*3);
        }
        paycheck->totalpay=pay;
        
        cout<<comname<<endl;
        cout<<address<<endl;
        cout<<"Name:  "<<paycheck->name<<" Amount:$ "<<paycheck->totalpay<<endl;
        cout<<"Amount:";
        
        cout<<"Signature Line:"<<endl;
        }while((hours)>=0&&(hours)>=0);
            
        
        
        
        
        
        
        
    
    
    

    return 0;
}

