/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on April 12, 2019, 12:57 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <cctype>


using namespace std;

/*
 * 
 */
struct board{
    string mark;
    bool occupied;
    
};
struct player{
    //string name ;
    char name[52];
    int pieces;
    bool active;
    board map [10][10];
};

enum Axislab{
    A,B,C,D,E,F,G,H,I,J};
    
    Axislab convert (char);
    void display (player *);


int main(int argc, char** argv) {
    int num_players;
    cout<<"Enter the number of players (2-6):";
    cin>>num_players;
    while (num_players<2||num_players>6){
        cout<<"Invalid amount. Reenter amount:";
        cin>>num_players;
    }
    const int num= num_players;
    player * plyrs=nullptr;
    plyrs= new player[num_players];
    int victory=num_players;
    fstream battleship_setup;
    Axislab rows;
    battleship_setup.open("battleship_setup.dat", ios::in| ios::binary);
    for (int i=0; i<num_players; i++){
        cin.ignore();
        cout<<"Enter player "<<(i+1)<<"'s name:";
        cin>>plyrs[i].name;
        plyrs[i].pieces=17;
        plyrs[i].active=true;
                
    }
    for (int i=0;i<num_players; i++){
        for (int j=0; j<10; j++){
            for (int k=0; k<10; k++){
                battleship_setup.read (reinterpret_cast<char *> (&plyrs[i].map[j][k]), sizeof(plyrs[i].map));
            }
        }
    }
    battleship_setup.close();
    for(int index=0; index<num_players; index++){
        char startletter, endletter;
        Axislab startp, endp;
        int startnp, endnp;
        cin.clear();
        for (int input=0; input<5;input++){
            int size;
            if (input==0){
                size=5;
            }
            else if(input==1){
                size=4;
            }
            else if(input==2){
                size=3;
            }
            else if(input==3){
                size=3;
            }
            else if(input==4){
                size=2;
            }
            cout<<plyrs[index].name<<endl;
        cout<<"Enter a length of "<<size<<" spaces using A-J for rows and 0-9 for columns."<<endl;
        cout<<"Enter the starting location's row:";
        cin>>startletter;
        if(startletter<'a' || startletter>'j'){
            if(startletter<'A' || startletter>'J'){
                cout<<"Invalid input. Reenter row:";
                cin>>startletter;
            }
        }
        
        cout<<"Enter the starting location's column:";
        cin>>startnp;
        if (startnp<0||startnp>9){
            cout<<"Invalide input. Reenter column:";
            cin>>startnp;
        }
        
        startp=convert(startletter);
        cout<<"Enter the ending location's row:";
        
        //cin.ignore();
        cin>>endletter;
        if(endletter<'a' || endletter>'j'){
            if(endletter<'A' || endletter>'J'){
                cout<<"Invalid input. Reenter row:";
                cin>>endletter;
            }
        }
        
        endp=convert(endletter);
        cout<<"Enter the ending location's column:";
        cin>>endnp;
        if (endnp<0||endp>9){
            cout<<"Invalide input. Reenter column:";
            cin>>endnp;
        }
        system("clear");
        //cout<<"after np";
        
        if (startp==endp){
            if (startnp>endnp){
                int tempi=endnp;
                endnp=startnp;
                startnp=tempi;
            }
            
            for (int i=0; i<size; i++){
                plyrs[index].map[startp][i+startnp].occupied=true;
                
            }
        }
        else if (startnp==endnp){
            if (startp>endp){
                Axislab temp=endp;
                endp=startp;
                startp=temp;
            }
            for (rows=startp; rows<=endp; rows=static_cast<Axislab>(rows+1)){
                plyrs[index].map[rows][startnp].occupied=true;
            }
        }
        }
        
    }
    
    
    while (victory>1){
        for (int q=0; q< num_players; q++){
        for (int p=0; p<num_players; p++){
            display (&plyrs[p]);
        }
        
    
        if (plyrs[q].active==true){
            string pname;
            
            int tracker, acol;
            char arow;
            Axislab arowconv;
            do{
                cout<<"Enter the player's name you want to hit:";
                cin.ignore();
                cin>>pname;
                while (pname!=plyrs[0].name&&pname!=plyrs[1].name&&pname!=plyrs[2].name&&pname!=plyrs[3].name&&
                        pname!=plyrs[4].name&&pname!=plyrs[5].name){
                    cout<<"Invalid name. Reeneter name:";
                    cin>>pname;
                }
                
                if(pname==plyrs[0].name){
                    tracker=0;
                }
                else if (pname==plyrs[1].name){
                    tracker=1;
                }
                else if (pname==plyrs[2].name){
                    tracker=2;
                }
                else if (pname==plyrs[3].name){
                    tracker=3;
                }
                else if (pname==plyrs[4].name){
                    tracker=4;
                }
                else if (pname==plyrs[5].name){
                    tracker=5;
                }
                cout<<"Enter the row you want to hit:";
                cin>>arow;
                if(arow<'a' || arow>'j'){
            if(arow<'A' || arow>'J'){
                cout<<"Invalid input. Reenter row:";
                cin>>arow;
            }
        }
                arowconv=convert(arow);
                cout<<"Enter the column you want to hit:";
                cin>>acol;
                 if (acol<0||acol>9){
            cout<<"Invalid input. Reenter column:";
            cin>>acol;
        }
                if(plyrs[tracker].map[arowconv][acol].occupied==true){
                    plyrs[tracker].map[arowconv][acol].mark="hit";
                    plyrs[tracker].pieces-=1;
                    cout<<"Hit"<<endl;
                    if (plyrs[tracker].pieces==0){
                        victory-=1;
                    }
                }
                else if (plyrs[tracker].map[arowconv][acol].occupied==false){
                    plyrs[tracker].map[arowconv][acol].mark="miss";
                }
            }while(plyrs[tracker].map[arowconv][acol].occupied==true);
            for (int check=0; check<num_players;check++){
                if (plyrs[check].pieces==0){
                    plyrs[check].active=false; 
                }
            }
        }
        
     
     }
    }
    cout<<"Congrats you have won.";
    return 0;
}

Axislab convert (char c){
    char con=c;
    c=toupper(con);
    Axislab rtn;
    
    switch (c){
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


void display (player * p){
    cout<<p->name<<endl;
            
            for (int x =0;x<10; x++){
      if (x==0){cout<<"  0  1  2  3  4  5  6  7  8  9"<<endl;}
       if (x==0){ cout<<"A ";}
                    
                    else if(x==1){ cout<<"B ";}
                    
                    else if(x==2){ cout<<"C ";}
                    
                    
                    else if (x==3){ cout<<"D ";}
                    
                    else if (x==4){ cout<<"E ";}
                    
                    else if (x==5){ cout<<"F ";}
                    
                    else if (x==6){ cout<<"G ";}
                    
                    else if (x==7){ cout<<"H ";}
                    
                    else if (x==8){ cout<<"I ";}
                   
                    else if (x==9){ cout<<"J ";}
     for (int y=0; y<10; y++){
     
              
                    
      
                if (p->map[x][y].mark=="miss"){
      cout<<"O  ";}
                else if (p->map[x][y].mark=="hit"){
      cout<<"X  ";}
                else{
                    cout<<"___";
                }
      
      
     
                }
      cout<<endl;
            }
}