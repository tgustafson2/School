/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on December 11, 2019, 9:40 PM
 */
//System Libraries
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
struct Clerk{
    bool busy;
    int worktime;
    int timeused;
};
//struct Cust{
//    int timewaited;
//};

//Execution Begins Here

int main(int argc, char** argv) {
    //Set random number seed here

    //Declare Variables
    
    int maxtime=0,totalwaited=0,totalcustomers=0;
    queue<int>customers;//arrive at 4/minute
    vector <Clerk> clerks;//add when line gets to 5 customers remove extra clerk when line gets to zero
    Clerk clerk1,clerk2,clerk3;
    clerk1.busy=false;
    clerk1.worktime=60;
    clerk1.timeused=0;
    clerk2.busy=false;
    clerk2.worktime=120;
    clerk2.timeused=0;
    clerk3.busy=false;
    clerk3.worktime=80;
    clerk3.timeused=0;
    clerks.push_back(clerk1);
    clerks.push_back(clerk2);
    clerks.push_back(clerk3);
    for (int sec=0; sec<=36000;sec+=5){
        for (int i=0; i<clerks.size();i++){
            if (clerks[i].busy==true){
                if (clerks[i].worktime==clerks[i].timeused){
                    clerks[i].busy=false;
                    clerks[i].timeused=0;
                }
                else
                    clerks[i].timeused+=5;
            }
        }
        if (sec%15==0){
            customers.push(0);
            totalcustomers++;
        }
        if (customers.size()>0){
            for (int i=0; i<clerks.size();i++){
                if ( clerks[i].busy==false && customers.size( ) > 0 ){
                    clerks[i].busy=true;
                    totalwaited+=customers.front();
                    if (customers.front()>maxtime){
                        maxtime=customers.front();
                    }
                    customers.pop();
                }
                    
            }
        }
        for (int i=0; i<customers.size();i++){
            int wait=customers.front();
            wait+=5;
            customers.push(wait);
            customers.pop();
            
        }
        if (customers.size()%5==0&&customers.size()!=0){
            Clerk clerk;
            clerk.busy=false;
            clerk.worktime=60;
            clerk.timeused=0;
            clerks.push_back(clerk);
        }
        if (customers.size()==0&&clerks.size()>3){
            clerks.pop_back();
        }
        
    }
    cout<<"The longest time waited was "<<maxtime<<" seconds"<<endl;
    cout<<"The average wait time was "<<totalwaited/totalcustomers<<" seconds"<<endl;
    cout<<totalcustomers;

    //Initialize Variables

    //Process inputs to outputs/map
    

    //Display the results

    //Clean up and exit stage right
    return 0;
}
