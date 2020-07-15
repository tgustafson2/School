/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on March 14, 2019, 5:36 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
//no const
int **getData(int &, int  &);
void prntDat( int **, int, int);
void destroy (int**, int, int);
int sum ( int **, int, int);



int main(int argc, char** argv) {
    int rows=0, cols=0;
    int sumArr=0;
    int ** data=nullptr;
    data=getData(rows, cols);
    
    prntDat (data, rows, cols);
    sumArr=sum(data,rows,cols);
    cout<<sumArr;
    destroy(data, rows, cols);

    return 0;
}

int **getData(int &rows, int &cols){
    cin>>rows>>cols;
    
    int ** DataArr=nullptr;
    DataArr= new int * [rows];
    for (int h=0; h<rows; h++){
        DataArr[h]=new int [cols];
    }
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols;j++){
            cin>>*(*(DataArr+i)+j);
        }
    }
    return DataArr;
}
void prntDat( int **Data, int rows, int cols){
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols;j++){
            cout<<*(*(Data+i)+j);
            if (j<cols-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
void destroy (int** Data, int rows, int cols){
    for (int i=0; i<rows; i++){
        delete [] Data[i];
    }
    delete []Data;
}
int sum ( int **Data, int rows, int cols){
    int sum=0;
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols;j++){
            sum+=*(*(Data+i)+j);
        }
    }
    return sum;
}