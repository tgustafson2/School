/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: johnnie Huerta
 *
 * Created on December 13, 2018, 11:24 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

/*
 * 
 */


void bubbleSort(int [], int);
double linearSearchDOU(double[], int, double);
int linearSearchSTRING(string, int, int);
double binarySearchDOU(double[], int, int, double);
int binarySearchSTRING(string [], int, int, int);


int main(int argc, char** argv){

   int rows;



    // declare all of our parallel arrays
    int student_id[rows];
    string first_name[rows];
    string last_name[rows];
    double gpa[rows];
    int choice;

    cout << "Choose an option to sort: " << endl;
    cout << "1. Student ID " << endl;
    cout << "2. Last Name " << endl;
    cout << "3. GPA " << endl;


    cin >> choice;

    int choiceS; // choice for search

    cout << "Choose an option to search: " << endl;
    cout << "1. Last name " << endl;
    cout << "2. GPA " << endl;
    
    double searchGPA;
    string searchNAME;
    int result, result2;
    
    cin >> choiceS;



    //switch case for sorting 
    switch(choice){
        case 1:{
            
        cout << "Unsorted: " << endl;
        
        output_records(student_id, first_name, last_name, gpa, rows);

        cout << "Sorted: " << endl;

        bubbleSort(student_id, rows);

        output_records(student_id, first_name, last_name, gpa, rows);

            if(choiceS ==1){
                cout << "What name would you like to search " << endl;
                cin >> searchNAME;

                result = linearSearchSTRING(last_name, rows, searchNAME);
                result2 = binarySearchSTRING(last_name, rows - 1, searchNAME);

            }
            else if(choiceS == 2){
                cout << "What GPA # would you like to search " << endl;
                cin >> searchGPA;

                result = linearSearchDOU(gpa, 0, rows - 1, searchGPA);
                result2 = binarySearchDOU(gpa, 0, rows -1, searchGPA);

            }

        }
        case 2:{

        cout << "Unsorted: " << endl;
        
        output_records(student_id, first_name, last_name, gpa, rows);

        cout << "Sorted: " << endl;

        bubbleSort(student_id, rows);

        output_records(student_id, first_name, last_name, gpa, rows);


            if(choiceS ==1){
                cout << "What name would you like to search " << endl;
                cin >> searchNAME;

                result = linearSearchSTRING(last_name, rows, searchNAME);
                result2 = binarySearchSTRING(last_name, rows - 1, searchNAME);



            }
            else if(choiceS == 2){
                cout << "What GPA # would you like to search " << endl;
                cin >> searchGPA;

                result = linearSearchDOU(gpa, 0, rows - 1, searchGPA);
                result2 = binarySearchDOU(gpa, 0, rows -1, searchGPA);


            }

        }
        case 3:{

        cout << "Unsorted: " << endl;
        
        output_records(student_id, first_name, last_name, gpa, rows);

        cout << "Sorted: " << endl;

        bubbleSort(student_id, rows);

        output_records(student_id, first_name, last_name, gpa, rows);


            if(choiceS ==1){
                cout << "What name would you like to search " << endl;
                cin >> searchNAME;

                result = linearSearchSTRING(last_name, rows, searchNAME);
                result2 = binarySearchSTRING(last_name, rows - 1, searchNAME);

            }
            else if(choiceS == 2){
                cout << "What GPA # would you like to search " << endl;
                cin >> searchGPA;

                result = linearSearchDOU(gpa, 0, rows - 1, searchGPA);
                result2 = binarySearchDOU(gpa, 0, rows -1, searchGPA);

            }
        }
    }


        
    



        


}

void bubbleSort(int pass[], int rows){

int i, j; 
   for (i = 0; i < rows-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < rows-i-1; j++)  
           if (pass[j] > pass[j+1]) 
              swap(&pass[j], &pass[j+1]);


}


double linearSearchDOU(double pass[], int rows, double search){


 int i; 
    for (i = 0; i < rows; i++) 
        if (pass[i] == search) 
            return i; 
    return -1; 


}
int linearSearchSTRING(string pass[], int rows, int search){


 int i; 
    for (i = 0; i < rows; i++) 
        if (pass[i] == search) 
            return i; 
    return -1; 


}


double binarySearchDOU(double pass[], int l, int rows, double search){
    
    while (l <= rows) { 
        int m = l + (rows - l) / 2; 
  
        // Check if x is present at mid 
        if (pass[m] == search) 
            return m; 
  
        // If x greater, ignore left half 
        if (pass[m] < search) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            rows = m - 1; 
    } 
  
    // if we reach here, then element was 
    // not present 
    return -1; 






}

int binarySearchSTRING(string pass[], int l, int rows, int serach){

    while (l <= rows) { 
        int m = l + (rows - l) / 2; 
  
        // Check if x is present at mid 
        if (pass[m] == search) 
            return m; 
  
        // If x greater, ignore left half 
        if (pass[m] < search) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            rows = m - 1; 
    } 
  
    // if we reach here, then element was 
    // not present 
    return -1; 






}