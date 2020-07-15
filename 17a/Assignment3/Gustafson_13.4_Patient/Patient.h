/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Patient.h
 * Author: tgust
 *
 * Created on April 30, 2019, 11:28 PM
 */

#ifndef PATIENT_H
#define PATIENT_H
#include <string>
using namespace std;
class Patient{
private:
    string fname;
    string mname;
    string lname;
    string address;
    string city;
    string state;
    string zip;
    string phonenumber;
    string emercontact;
    string emernum;
    
    
public:
    Patient(string a, string b, string c, string d, string e,string f, string g,
            string h, string i, string j){
        fname=a;
        mname=b;
        lname=c;
        address=d;
        city=e;
        state=f;
        zip=g;
        phonenumber=h;
        emercontact=i;
        emernum=j;
        
    }
    void setfname(string a){
        fname=a;
    }
    void setmname(string a){
        mname=a;
    }
    void setlname(string a){
        lname=a;
    }
    void setaddress(string a){
        address=a;
    }
    void setcity(string a){
        city=a;
    }
    void setstate(string a){
        state=a;
    }
    void setzip(string a){
        zip=a;
    }
    void setphonenumber(string a){
        phonenumber=a;
    }
    void setemercontact(string a){
        emercontact=a;
    }
    void setemernum(string a){
        emernum=a;
    }
    string getfname(){
        return fname;
    }
    string getmname(){
        return mname;
    }
    string getlname(){
        return lname;
    }
    string getaddress(){
        return address;
    }
    string getcity(){
        return city;
    }
    string getstate(){
        return state;
    }
    string getzip(){
        return zip;
    }
    string getphonenumber(){
        return phonenumber;
    }
    string getemercontact(){
        return emercontact;
    }
    string getemernum(){
        return emernum;
    }
    
};


#endif /* PATIENT_H */

