/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Weathertrack.cpp
 * Author: tgust
 *
 * Created on February 22, 2019, 6:33 PM
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;




/*
 * 
 */
//Declare Global constants for days and months
const int month=3;
const int days=30;
//Function prototypes to count and out put the days
void weatherdays (char[][30],int);
void showdays (int, int, int, int);


int main() {
    //Declare counter variables, variables for day types, and initialize array
    int num, count, raindays, clouddays, sun_days;
    char weather [month][days];
    fstream rainfile;
    
    //Open file, might need to change file location for computer
    rainfile.open("c:/Users/tgust/Downloads/source_code/source_code/Chapter 07/RainOrShine.txt");
    //Read file to array
    for (num=0; num<month; num++){
        count=0;
        
        while(count<days && rainfile>>weather[num][count]){
            
            
            count++;
            
        }
    }
    rainfile.close();
    //close file, and use for loop to count the day types in the array
    for (num=0; num<month; num++){
        weatherdays (weather, num);
    }
    //set variables to 0
    raindays=0;
    clouddays=0;
    sun_days=0;
    //count day types
    for (num=0; num<month; num++){
        
        for (count=0; count<days; count++){
            if (weather [num][count]=='R'){
            raindays+=1;
        }
        else if (weather [num][count]=='C'){
            clouddays+=1;
        }
        else if (weather [num][count]=='S'){
            sun_days+=1;
        }
        }
            
            
    }
    cout<<"There are a total of "<<raindays<<" rainy days, "<<clouddays
            <<" cloudy days, "<< sun_days<< " sunny days.";
    
    

    return 0;
}


void weatherdays (char weatherrecord [][days], int num){
    //Declare variables
    int wcount;
    int rainydays=0;
    int cloudydays=0;
    int sunnydays=0;
    //Use for loop to count day types
    for (wcount=0; wcount<days; wcount++){
        if (weatherrecord [num][wcount]=='R'){
            rainydays+=1;
        }
        else if (weatherrecord [num][wcount]=='C'){
            cloudydays+=1;
        }
        else if (weatherrecord [num][wcount]=='S'){
            sunnydays+=1;
        }
        
    }
    //pass day type to showdays function
    showdays(rainydays, cloudydays, sunnydays, num);
}

void showdays(int rain, int cloud, int sun, int monthnum){
    //determine which month is being counted and output the day types
  if (monthnum==0){
      cout<<"June has ";
  }   
  else if (monthnum==1){
      cout<<"July has ";
  }
  else if (monthnum==2){
      cout<<"August has ";
  }
  cout<<rain<<" rainy days, "<<cloud<<" cloudy days, "<<sun<<" sunny days."<<endl;
}
  