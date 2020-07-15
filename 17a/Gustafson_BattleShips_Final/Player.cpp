/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Player.h"
#include "BaseGame.h"

void Player::setOccupied(){
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
            cout<<name<<endl;
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
        
        startp=BaseGame::conv(startletter);
        cout<<"Enter the ending location's row:";
        
        //cin.ignore();
        cin>>endletter;
        if(endletter<'a' || endletter>'j'){
            if(endletter<'A' || endletter>'J'){
                cout<<"Invalid input. Reenter row:";
                cin>>endletter;
            }
        }
        
        endp=BaseGame::conv(endletter);
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
                map.setOccupied(startp,(i+startnp));
                
            }
        }
        else if (startnp==endnp){
            if (startp>endp){
                Axislab temp=endp;
                endp=startp;
                startp=temp;
            }
            for (int j=startp; j<=endp; j=static_cast<Axislab>(j+1)){
                map.getOccupied(j, startnp);
            }
        }
        }
        
        cin.ignore();

}