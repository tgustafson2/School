/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinarySearch.cpp
 * Author: tgust
 *
 * Created on February 23, 2019, 12:24 PM
 */

#include <iostream>
#include <string>
using namespace std;

void bubblesortlast( string [], int);
void binarysearch(string [], int, string);
void swap (string &, string &);



int main()
{
    string search;
	const int NUM_NAMES = 20;
	string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                               "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
                               "Looney, Joe", "Wolfe, Bill", "James, Jean",
                               "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
                               "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth" };

	// Insert your code to complete this program
        cout<<"Enter the name of the person you are searching for.\n";
        cout<<"Enter as Last Name, First Name:";
        cin>> search;
        binarysearch (names, NUM_NAMES, search);
	return 0;
}

void bubblesortlast (string namearr[], int num_names ){
    
    int maxElement;
    int index;
    for (maxElement=num_names-1; maxElement>0; maxElement--){
        for (index=0; index<maxElement; index++){
      
    string last1=namearr[index];
    string last2=namearr[index+1];
   
    if(last1>last2){
        swap(namearr[index], namearr[index+1]);
    }
        }
    }
}

void swap(string &c, string &d){
    
    
    string temp2=c;
    c=d;
    d=temp2;


}


void binarysearch(string names[], int num_names,string search){
        
  
  
        bubblesortlast(names, num_names);
        int first = 0,
                last = num_names-1,
                middle,
                position=-1;
        bool found = false;
        while (!found && first<=last){
            middle = (first+last)/2;
            if (names[middle]==search){
                found=true;
                position=middle;
            }
            else if (names[middle]>search){
                last=middle-1;
            }
            else
                first=middle+1;
            
                
        }
        cout<<"The name "<< names[middle]<< " was found.";
       
    }
