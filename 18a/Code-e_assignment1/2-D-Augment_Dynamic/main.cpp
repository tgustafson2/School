/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on March 17, 2019, 6:38 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */

int **getData(int &, int &);
void prntDat (const int * const*, int, int);
int **augment(const int * const*, int, int);
void destroy (int **, int);




int main(int argc, char** argv) {
    int rows=0, cols=0;
    int ** data=nullptr;
    int ** augArr=nullptr;
    data=getData(rows, cols);
    prntDat(data, rows, cols);
    rows+=1;
    cols+=1;
    
    augArr=augment(data, rows, cols);
    prntDat(augArr, rows, cols);
    destroy (data, rows);
    destroy (augArr, rows);

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
void prntDat(const int * const *a,int row,int COL){
    cout<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<COL;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
 
int **augment (const int * const * data, int rows, int cols){
    int ** augArr=nullptr;
    cout<<"in augment";
    augArr= new int * [rows];
    for (int h=0; h<rows; h++){
        augArr[h]=new int [cols];
    }
    for (int i=0; i<rows; i++){
        *(*(augArr)+i)=0;
    }
    for (int j=0; j<cols; j++){
        *(*(augArr+j))=0;
    }
    for (int i=1; i<rows; i++){
        for (int j=1; j<cols;j++){
            *(*(augArr+i)+j)=*(*(data+i-1)+j-1);
        }
    }
    return augArr;
    
}


void destroy (int **arr, int rows){
    for (int i=0; i<rows; i++){
        delete [] arr[i];
    }
    delete []arr;
}