/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on October 25, 2019, 5:00 PM
 */
#include <cstdlib>//Random number seed
#include <ctime>//Set the seed
#include <iostream>//I/O
#include <set>
#include <iterator>
#include <iomanip>
#include <map>
#include <vector>
using namespace std;

//No Global Constants

//Function Prototypes

int *Roll();
void prntResu(int, int, int, int, int);

vector<int> mode(const int *,int);


//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    srand(static_cast <unsigned int> (time(0)));
    int *dice;
    int fourSame=0, threeSame=0, pair2=0, pair1=0;
    int tests=100000;
    
    
    //Print the initial array
    
    
    //Calculate the mode array
    for (int i=0; i<tests; i++){
        dice=Roll();
        vector<int> modeAry=mode(dice,4);
        if (modeAry[1]==4)fourSame++;
        else if (modeAry[1]==3)threeSame++;
        else if (modeAry[1]==2){
            if (modeAry[0]==1)pair1++;
            else pair2++;
        }
        delete []dice;
        modeAry.clear();
        
    }
    
    
    //Print the modal information of the array
    prntResu(fourSame, threeSame, pair2, pair1, tests);
    
    //Delete allocated memory

    
    
    //Exit stage right
    return 0;
}

int *Roll(){
    int * rolls=new int[4];
    for (int i=0; i<4; i++){
        rolls[i]=rand()%6+1;
    }
    return rolls;
}

vector<int> mode(const int *array,int arySize){
    set<int> modeset;
    map<int, int> frequency;
    vector<int>modes(2);
    int maxFreq=0;
    for(int i=0; i<arySize; i++){
        if (modeset.count(array[i])==0){
        modeset.insert(array[i]);
        frequency[array[i]]=1;
        }
        else {
            frequency[array[i]]++;
            if (maxFreq<frequency[array[i]])maxFreq=frequency[array[i]];
        }
    }
    //cout<<"Mode Freq = "<<maxFreq<<endl;
    //Find the number of modes
    int count=0;
    int nModes=0;
    modes[0]=0;
    modes[1]=maxFreq;
    map<int,int> ::iterator itr;
    for (itr=frequency.begin(); itr!=frequency.end();++itr){
        if(maxFreq!=1){
        if(itr->second==maxFreq){
            modes[0]++;
            modes.push_back(itr->first);
        }
        }
    }
    //cout<<"Number of modes = "<<modes[0]<<endl;
    return modes;
}


void prntResu(int four, int three, int two, int one, int loops){
    cout<<setprecision(4)<<fixed;
    cout<<"Probability of 4 of a kind: "<<(float)four/loops<<endl;
    cout<<"Probability of 3 of a kind: "<<(float)three/loops<<endl;
    cout<<"Probability of 2 pairs: "<<(float)two/loops<<endl;
    cout<<"Probability of 1 pair: "<<(float)one/loops<<endl;
}