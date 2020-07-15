/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on October 1st, 2019, 7:45 PM
 */

//Libraries
#include <cstdlib>//Random number seed
#include <ctime>//Set the seed
#include <iostream>//I/O
#include <set>
#include <iterator>
#include <map>
#include <vector>
using namespace std;

//No Global Constants

//Function Prototypes
int *fillAry(int,int);
void prntAry(int *,int,int);
void prntMod(vector<int>);


vector<int> mode(const int *,int);


//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize=35;
    int modNum=10;
    int *ary=fillAry(arySize,modNum);
    
    //Print the initial array
    prntAry(ary,arySize,10);
    
    //Calculate the mode array
    vector<int> modeAry=mode(ary,arySize);
    
    //Print the modal information of the array
    prntMod(modeAry);
    
    //Delete allocated memory
    delete []ary;
    
    
    //Exit stage right
    return 0;
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
    cout<<"Mode Freq = "<<maxFreq<<endl;
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
    cout<<"Number of modes = "<<modes[0]<<endl;
    return modes;
}


void prntMod(vector<int> ary){
    cout<<endl;
    cout<<"The number of modes = "<<
            ary[0]<<endl;
    cout<<"The max Frequency = "<<
            ary[1]<<endl;
    if(ary[0]==0){
        cout<<"The mode set = {null}"<<endl;
        return;
    }
    cout<<"The mode set = {";
    for(int i=2;i<ary[0]+1;i++){
        cout<<ary[i]<<",";
    }
    cout<<ary[ary[0]+1]<<"}"<<endl;
}



void prntAry(int *array,int n,int perLine){
    //Output the array
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(array+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n, int modNum){
    //Allocate memory
    int *array=new int[n];
    
    //Fill the array with 2 digit numbers
    for(int i=0;i<n;i++){
        *(array+i)=i%modNum;
        //*(array+i)=rand()%modNum;
    }
    
    //Exit function
    return array;
}