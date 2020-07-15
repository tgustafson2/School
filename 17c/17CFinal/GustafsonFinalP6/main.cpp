/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on December 12, 2019, 1:30 PM
 */
//System Libraries
#include <iostream>
#include <cmath>
#include <bits/stdc++.h> 
using namespace std;

//User Libraries

//Global Constants
const int V=7;
//Function Prototypes
int minDistance(int [],bool[],int);
void dijkstra(int [][7],int,int);
int minDistance(int [], bool [],int );
void primMST(int [V][V]) ;
void printMST(int [], int [V][V]) ;

//Execution Begins Here

int main(int argc, char** argv) {
    //Set random number seed here

    //Declare Variables
    int vertices=7;
    //SFO is 0 or A, ORD is 1 or B, JFK is 2 or C, DFW is 3 or D, MIA is 4 or E, LAX is 5 or F,BOS is 6 or G
    int graph[7][7]={
        {0,1846,0,1464,0,339,2702},
        {1846,0,742,802,0,0,867},
        {0,742,0,0,1092,0,189},
        {1464,802,0,0,1123,1235},
        {0,0,1092,1123,0,2342,1258},
        {339,0,0,1235,2342,0,0},
        {2702,867,189,0,1258,0,0}
            };
    //Initialize Variables

    //Process inputs to outputs/map
    

    //Display the results
    cout << "Vertex\t||\tDistance from ORD vertex"<<endl;
    dijkstra(graph,1,vertices);
    cout << "Vertex\t||\tDistance from JFK vertex"<<endl;
    dijkstra (graph,2,vertices);
    primMST(graph);
    //Clean up and exit stage right
    return 0;
}
int minDistance(int distance[], bool D[],int vertex)
{
    int index;
    int min = INT_MAX;  
    
    for(int i = 0; i < vertex; i++)
    {
        if(D[i] == false && distance[i] <= min)      
        {
            min = distance[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int graph[][7], int source,int vertex) 
{
    int distance[vertex];                             
    bool D[vertex];
    
    for(int i = 0; i < vertex; i++)          
    {
        distance[i] = INT_MAX;
        D[i]=false;	
    }
    
    distance[source] = 0;    
    
    for(int i = 0; i < vertex; i++)                           
    {
        int temp = minDistance(distance, D,vertex);           
        D[temp] = true;    
        
        for(int i = 0; i < vertex; i++)                  
        {
            if(!D[i] && graph[temp][i] && distance[temp]!= INT_MAX && distance[temp] + graph[temp][i]<distance[i])
                distance[i] = distance[temp] + graph[temp][i];
        }
    }
    
//    cout << "Vertex\t||\tDistance from " << source<<" vertex"<<endl;
    
    for(int i = 0; i < vertex; i++)                       
    {
        char c = 65 + i;
        cout << c << "\t\t" << distance[i] << endl;
    }
}
int minKey(int key[], bool mstSet[])  
{  
    
    int min = INT_MAX, min_index;  
  
    for (int v = 0; v < V; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  
    return min_index;  
}  
void printMST(int parent[], int graph[V][V])  
{  
    int total=0;
    cout<<"Edge \tWeight\n";  
    for (int i = 1; i < V; i++)  {
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  
        total+=graph[i][parent[i]];
        }
    cout<<"The total minimum distance was "<<total<<" miles";
}  
void primMST(int graph[V][V])  
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