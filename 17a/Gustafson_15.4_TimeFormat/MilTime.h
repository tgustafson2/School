/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MilTime.h
 * Author: tgust
 *
 * Created on May 17, 2019, 6:21 PM
 */

#ifndef MILTIME_H
#define MILTIME_H
#include <string>
#include "Time.h"

using namespace std;

class MilTime: public Time {
    private:
        int milhours;
        int milseconds;
    public:
        MilTime(int ihours, int iseconds){
            if (ihours>2359||ihours<0){
                cout<<"Invalid hours. Reenter hours:";
                cin>>ihours;
            }
            if (iseconds>59||iseconds<0){
                cout<<"Invalid seconds. Reenter seconds:";
                cin>>iseconds;
            }
            milhours=ihours;
            milseconds=iseconds;
            sec=iseconds;
            sethour();
            setmin();
        }
        void setTime(int ihours, int iseconds){
            if (ihours>2359||ihours<0){
                cout<<"Invalid hours. Reenter hours:";
                cin>>ihours;
            }
            if (iseconds>59||iseconds<0){
                cout<<"Invalid seconds. Reenter seconds:";
                cin>>iseconds;
            }
            milhours=ihours;
            milseconds=iseconds;
            sec=iseconds;
            sethour();
            setmin();
        }
        void setmin(){
         
            
            min=(milhours/10)%10*10;
            min+=(milhours%10);
            
        }
        void sethour(){
            hour=milhours/100;
            if (hour==0){
                hour=12;
            }
            if (hour>12){
                hour-=12;
            }
            
        }
        string getHourf(){
            string milhour;
            milhour=to_string(milhours)+":"+to_string(milseconds);
            return milhour;
        }
        string getStandHr(){
            string stdTime;
            stdTime=to_string(hour)+":";
            stdTime+=to_string(min)+":";
            stdTime+=to_string(sec);
            return stdTime;
        }
};


#endif /* MILTIME_H */

