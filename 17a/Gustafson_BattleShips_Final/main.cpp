/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on June 3, 2019, 5:27 PM
 */

#include <cstdlib>
#include "BaseGame.h"
//#include "EnhancedGame.h"

using namespace std;

/*
 * 
 */
void basegame();
void enhanced();
int main(int argc, char** argv) {
    cout<<"Would you like to play the basic battleships or the enhanced version?"<<endl;
    cout<<"1 for basic, 2 for enhanced";
    int choice;
    cin>>choice;
    cin.ignore();
    switch (choice){
        case 1: basegame();break;
        //case 2: enhanced();break;
    }


    return 0;
}
void basegame(){
        int players;
    cout<<"Enter the number of players:";
    cin>>players;
    int playcount=players;
    cin.ignore();
   

    BaseGame battleships(players);
    cout<<playcount;
    //cout<<battleships.getPlayercount();
        while (playcount>1){
            //cout<<"Start of while loop";
            
        for (int q=0; q< players; q++){
        //for (int p=0; p<num_players; p++){
        //    display (&plyrs[p]);
        //}
        //output boards with operator overloading
            cout<<battleships.getPlayercount()<<endl;
            cout<<battleships;
    
        if (battleships.getActive(q)==true){
           
            string pname;
            
            int tracker, acol;
            char arow;
            do{
                cout<<battleships.getName(q)<<" enter the player's name you want to attack:";
              
                cin>>pname;
                cin.ignore();
                while (pname!=battleships.getName(0)&&pname!=battleships.getName(1)
                        &&pname!=battleships.getName(2)&&pname!=battleships.getName(3)
                        &&pname!=battleships.getName(4)&&pname!=battleships.getName(5)){
                    cout<<"Invalid name. Reeneter name:";
                    cin>>pname;
                    cin.ignore();
                }
                
                
                cout<<"Enter the row you want to hit:";
                cin>>arow;
                if(arow<'a' || arow>'j'){
            if(arow<'A' || arow>'J'){
                cout<<"Invalid input. Reenter row:";
                cin>>arow;
            }
        }
                cout<<"Enter the column you want to hit:";
                cin>>acol;
                 if (acol<0||acol>9){
            cout<<"Invalid input. Reenter column:";
            cin>>acol;
        }

            }while(battleships.attack(pname,arow,acol, playcount)==true);

        }
            //cout<<"After if attack loop"<<endl;
        
     
     }
    }
    cout<<"End of Game";
    for (int i; i<players; i++){
        if (battleships.getActive(i)==true){
            cout<<"End of game";
            cout<<"Congratulations "<<battleships.getName(i)<<", you have won.";
        }
    }
}
