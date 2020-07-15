/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SavingsAccount.h
 * Author: tgust
 *
 * Created on May 31, 2019, 7:39 PM
 */

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
using namespace std;
class SavingsAccount{
    	public:
		SavingsAccount(float);               //Constructor
		void  Transaction(float);            //Procedure
		float Total(float savint,int time);	         //Savings Procedure
		float TotalRecursive(float savint,int time);
		void  toString();                    //Output Properties
	private:
		float Withdraw(float);               //Utility Procedure
		float Deposit(float);                //Utility Procedure
		float Balance;                       //Property
		int   FreqWithDraw;                  //Property
		int   FreqDeposit;                   //Property
};

#endif /* SAVINGSACCOUNT_H */

