/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Player.h"
#include "Board.h"
#include "List.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <bits/stdc++.h>
Player::Player(){
    //get name
    moves=0;
    int a[5]={5,4,3,3,2};
    ships=new List<int>(5,a);
    cout<<"Enter player's name:";
    cin>>name;
    cin.ignore();
    board = new Board;
    active=true;
    pieces=17;
    vector<pair<int,int>>locations;
    int startrow, endrow, startcol, endcol;
    board->printboard();
    for (int i=0; i<5; i++){
        cin.clear();
        pair<int,int>locat;
        
        cout<<"Enter a length of "<<ships->getNth(i)<<" spaces"<<endl;
        cout<<"Enter the starting location's row:";
        cin>>startrow;
        cout<<"Enter the starting location's column:";
        cin>>startcol;
        locat.first=startrow;
        locat.second=startcol;
        locations.push_back(locat);
        cout<<"Enter the ending location's row:";
        cin>>endrow;
        cout<<"Enter the ending location's column:";
        cin>>endcol;
        if (startrow==endrow){
            if (startcol<endcol){
            for (int j=startcol; j<=endcol; j++){
                board->setString((startrow-1)*10+j, "occupied");
            }
            }
            if (startcol>endcol){
                for (int j=endcol; j>=startcol; j--){
                board->setString((startrow-1)*10+j, "occupied");
            }
            }
        
        }
        else if (startcol==endcol){
            if (startrow<endrow){
            for (int j=startrow; j<=endrow; j++){
                board->setString((startrow-1)*10+j, "occupied");
            }
            }
            if (startrow>endrow){
                for (int j=endrow; j>=startrow; j--){
                board->setString((startrow-1)*10+j, "occupied");
            }
            }
        }
    }//clear user input
    system("clear");
    //prompt input for ship locations
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            int x=locations[i].first-locations[j].first;
            int y=locations[i].second-locations[j].second;
            
            graph[i][j]=sqrt(pow(x,2)+pow(y,2));
        }
    }
}
bool Player::getStatus(){
    return active;
}
void Player::setStatus(bool sta){
    active=sta;
}
bool Player::getOccu(int row, int col){
    return board->getOccup((row-1)*10+col);
}
void Player::setBoard(int row, int col, string mark){
    if (mark=="hit")pieces--;
    board->setString((row-1)*10+col,mark);
}
void Player::printBoard(){
    board->printboard();
}
void Player::addMove(){
    moves++;
}
int Player::getMove(){
    return moves;
}
int Player::minKey(int key[], bool mstSet[])  
{  
    
    int min = INT_MAX, min_index;  
  
    for (int v = 0; v < V; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  
    return min_index;  
}  
void Player::printMST(int parent[], int graph[5][5])  
{  
    int total=0;
    cout<<"Edge \tWeight\n";  
    for (int i = 1; i < V; i++)  {
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  
        total+=graph[i][parent[i]];
        }
    cout<<"The total minimum distance was "<<total<<" miles";
}  
void Player::primMST(int graph[5][5])  
{  
     
    int parent[V];  
      
     
    int key[V];  
      
    
    bool mstSet[V];  
  
    
    for (int i = 0; i < V; i++)  
        key[i] = INT_MAX, mstSet[i] = false;  
  
      
    key[0] = 0;  
    parent[0] = -1;   
  
    
    for (int count = 0; count < V - 1; count++) 
    {  
          
        int u = minKey(key, mstSet);  
  
         
        mstSet[u] = true;  
  
         
        for (int v = 0; v < V; v++)  
  
              
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])  
                parent[v] = u, key[v] = graph[u][v];  
    }  
  
   
    printMST(parent, graph);  
}

