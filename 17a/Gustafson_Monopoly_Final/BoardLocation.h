/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BoardLocation.h
 * Author: tgust
 *
 * Created on May 29, 2019, 7:37 PM
 */
 
#ifndef BOARDLOCATION_H
#define BOARDLOCATION_H

using namespace std;
class BoardLocation{
private:
    string topname;
    string bottomname;
    int location;
public:
    BoardLocation(string topname, string bottomname, int location){
        this->topname=topname;
        this->bottomname=bottomname;
        this->location=location;
    }
    void GoToJail(Player jplayer);
    int FreeParking();
    int Tax();
    enum Status{Owned, Mortgaged, Unowned, NonProperty}; 
};

#endif /* BOARDLOCATION_H */

