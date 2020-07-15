/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on April 21, 2019, 3:57 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>

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
struct EmployeePay{
    char name[52];
    double hours;
    double payrate;
    double totalpay;
    
};
struct Prime{
    int prime;
    int power;
};
struct Primes{
    Prime *prime;
    int nPrimes;
};
Primes *factor(int);
void prntPrm (Primes*);




void encrypt();
void decrypt();


void problem1 ();
void problem2 ();
void problem3 ();
void problem4 ();
void problem5 ();
void problem6 ();
void problem7 ();



int main(int argc, char** argv) {
    int inN;
        do{
         
         cout<<"Enter the problem:";
         cin>>inN;
         
         switch(inN){
          case 1:    problem1();break;
          case 2:    problem2();break;
          case 3:    problem3();break;
          case 4:    problem4();break;
          case 5:    problem5();break;
          case 6:    problem6();break;
          case 7:    problem7();break;
          }
        }while(inN<8);

    return 0;
}

void problem1(){
    int cnum, dnum;
    
    Customer *cust= new Customer;
    cust->checks=0;
    cust->deposits=0;
    cust->balance=0;
    cout<<"Enter the customer's name:";
    cin.ignore();
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
}
void problem2(){
    char comname[52];
    cout<<"Enter the Company's name:";
    cin.ignore();
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
        cin.ignore();
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
}
void problem3 (){
    cout<<"It is included in another project."<<endl;
}
void problem4 (){
   char input;
    cout<<"Enter 0 to decrypt a number and 1 to encrypt a number:";
    
    cin>>input;
    if (input=='0'){
        decrypt();
    }
    else if (input=='1'){
        encrypt();
    }
     
}
void problem5(){
    cout<<"The largest factorial for a byte variable is 5"<<endl;
    cout<<"The largest factorial for a float variable is 34"<<endl;
    cout<<"The largest factorial for a double variable is 170"<<endl;
    cout<<"The largest factorial for a short variable is 7"<<endl;
    cout<<"The largest factorial for a int variable is 12"<<endl;
    cout<<"The largest factorial for a long variable is 12"<<endl;
    cout<<"The largest factorial for a long long variable is 20"<<endl;
    
}
void problem6(){
    cout<<"2.875 in binary is 10.111, octal 2.7, and hex 2.E"<<endl;
    cout<<".1796875 in binary is .0010111, octal .134, and hex .2E"<<endl;
    cout<<"The 2s compliment for -2.875 is 11111110.0010 in binary, FD.2 in hex, and 375.2 in octal"<<endl;
    cout<<"The 2s compliment for .-.1796875 is .11010010 in binary, .D2 in hex, and .322 in octal"<<endl;
    cout<<"59999901 is .3125"<<endl;
    cout<<"59999902 is .15625"<<endl;
}
void problem7 (){
    int num=0;
    cout<<"Enter and integer between 2 and 10000:";
    
    cin>>num;
    cout<<"before leaving";
    Primes *factordat=factor(num);
    cout<<num<<" = ";
    prntPrm(factordat);
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
Primes *factor(int num){
    cout<<"before dynamic allocation.";
    Primes *factors=new Primes;
    for (int i=2; i<=num; i++){
        int pcounter=0;
        cout<<"in for loop";
        if (num %i ==0){
        pcounter++;
        factors->nPrimes=pcounter;}
        while (num % i ==0){
            num/=i;
            
            factors->prime->power +=1;
            factors->prime->prime=i;
            
        }
        
    }
    return factors;
}
void prntPrm (Primes* factors){
    for (int i=0; i<(factors->nPrimes); i++){
        cout<<(factors->prime->prime)<<"^"<<(factors->prime->power)<<" * ";
    }
}
