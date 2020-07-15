/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>

#include "Prob2Sort.h"
using namespace std;


/*template<class T>
T *Prob2Sort<T>::sortArray(const T* str, int size, bool as){
    T *test = new T[size];
    T temp;
    for(int i=0;i<size;i++){
        test[i]=str[i];
    }
    bool swap;
    do{
        for(int i=0;i<size-1;i++){
            if(as==true){
                if(test[i]>test[i+1]){
                    swap=true;
                    temp=test[i];
                    test[i+1]=test[i];
                    test[i+1]=temp;
                }
            }
            else{
                if(test[i]<test[i+1]){
                    swap=true;
                    temp=test[i];
                    test[i+1]=test[i];
                    test[i+1]=temp;
                }
            }
        }
    }while(swap==true);
    return test;
}
template<class T>
//char *zc=rc.sortArray(ch2p,10,16,column,ascending);
T *Prob2Sort<T>::sortArray(const T *str,int y,int x,int col,bool as){
    T *test = new T[x*y];
// cout<<x*y<<endl;
    for(int i=0;i<x*y;i++){
        test[i]=str[i];
    }
// for(int i=0;i<x*y;i++){
//    cout<<test[i];
//   }
    col-=1;
    bool swap;
    T temp;
// cout<<"sort function\n";
    do{
//    cout<<"swap=false\n";
        swap=false;
        for(int i=0;i<y-1;i++){
//      cout<<"i="<<i<<endl;
            if(as==true){
                if(test[i*x+col]>test[(i+1)*x+col]){
                    swap=true;
                    for(int j=0;j<x;j++){
                        temp=test[i*x+j];
                        test[i*x+j]=test[(i+1)*x+j];
                        test[(i+1)*x+j]=temp;
                    }
                }
            }
            else{
                if(test[i*x+col]<test[(i+1)*x+col]){
                    swap=true;
                    for(int j=0;j<x;j++){
                        temp=test[i*x+j];
                        test[i*x+j]=test[(i+1)*x+j];
                        test[(i+1)*x+j]=temp;
                    }
                }
            }
        }
    }while(swap==true);
    return test;
}*/
template<class T>
T* Prob2Sort<T>::sortArray(const T* arr, int size, bool ascending)
{
    // call to generic column-based, with number of cols = 1, sort col = 1
    return sortArray(arr, size, 1, 1, ascending);
}

template<class T>
T* Prob2Sort<T>::sortArray(const T* arr, int row, int col, int sort_col, bool ascending)
{
    if(sort_col < 1 || sort_col > col || row < 1 || col < 1)
    {
        // invalid values, return NULL
        return NULL;
    }
    int i, j, minmax, tmp;

    if(index)
    {
        delete [] index;
    }
    index = new int[row];

    for(i = 0; i < row; i++) // initial ordering
        index[i] = i;

    //start sorting
    for(i = 0; i < row; i++)
    {
        minmax = i;
        for(j = i+1; j < row; j++)
        {
            if(ascending)
            {
                //element location: row_no * no_of_cols + col_no
                // -1 to change from 1 based index to 0 based index
                if(arr[index[j] * col + sort_col - 1] < arr[index[minmax] * col + sort_col - 1])
                    minmax = j;
            }
            else
            {
                if(arr[index[j] * col + sort_col - 1] > arr[index[minmax] * col + sort_col - 1])
                    minmax = j;
            }
        }
        //swap indices
        tmp = index[i];
        index[i] = index[minmax];
        index[minmax] = tmp;
    }

    //copy in sorted order
    T* sorted = new T[row * col];
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            sorted[i * col + j] = arr[index[i] * col + j];
        }
    }
    return sorted;
}