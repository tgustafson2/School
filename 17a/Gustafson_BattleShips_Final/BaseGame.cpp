/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "BaseGame.h"


Axislab BaseGame::conv(char row){
    row=toupper(row);
    Axislab rtn;
    
    switch (row){
        case 'A':
            rtn=A;
     
            break;
        case 'B':
            rtn=B;
            break;
        case 'C':
            rtn=C;
            break;
        case'D':
            rtn=D;
            break;
        case 'E':
            rtn=E;
            break;
        case 'F':
            rtn=F;
            break;
        case 'G':
            rtn=G;
            break;
        case 'H':
            rtn=H;
            break;
        case'I':
            rtn=I;
            break;
        case 'J':
            rtn=J;
            break;
        
    }
    return rtn;
    }
    bool BaseGame::attack(string name, char row, int col){
        Axislab rowconv=conv(row);
        int tracker;
                if(name==getName(0)){
                    tracker=0;
                }
                else if (name==getName(1)){
                    tracker=1;
                }
                else if (name==getName(2)){
                    tracker=2;
                }
                else if (name==getName(3)){
                    tracker=3;
                }
                else if (name==getName(4)){
                    tracker=4;
                }
                else if (name==getName(5)){
                    tracker=5;
                }
        if (players[tracker]->getOccupied(rowconv, col)==true){
            players[tracker]->setMark("hit",rowconv, col);
            players[tracker]->subtractPieces(1);
            cout<<players[tracker]->getPieces()<<endl;
            cout<<"Hit"<<endl;
            
            if (players[tracker]->getPieces()==0){
                //cout<<playercount<<"in if loop"<<endl;
                playercount--;
                
                players[tracker]->setActive(false);
            }
            if (playercount==1){
                return false;
            }
            return true;
        }
        else if (players[tracker]->getOccupied(rowconv, col)==false){
            players[tracker]->setMark("miss", rowconv, col);
            return false;
        }
    }
ostream & operator <<(ostream &strm, const BaseGame &obj){
    
    for (int i=0; i<obj.getStartingplayer(); i++){
        strm<<obj.getName(i)<<endl;
                    for (int x =0;x<10; x++){
      if (x==0){strm<<"  0  1  2  3  4  5  6  7  8  9"<<endl;}
       if (x==0){ strm<<"A ";}
                    
                    else if(x==1){ strm<<"B ";}
                    
                    else if(x==2){ strm<<"C ";}
                    
                    
                    else if (x==3){ strm<<"D ";}
                    
                    else if (x==4){ strm<<"E ";}
                    
                    else if (x==5){ strm<<"F ";}
                    
                    else if (x==6){ strm<<"G ";}
                    
                    else if (x==7){ strm<<"H ";}
                    
                    else if (x==8){ strm<<"I ";}
                   
                    else if (x==9){ strm<<"J ";}
     for (int y=0; y<10; y++){
     
              
                    
      
                if (obj.getMark(i,x,y)=="miss"){
      strm<<"O  ";}
                else if (obj.getMark(i,x,y)=="hit"){
      strm<<"X  ";}
                else{
                    strm<<"___";
                }
      
      
     
                }
      cout<<endl;
            }
    }
}