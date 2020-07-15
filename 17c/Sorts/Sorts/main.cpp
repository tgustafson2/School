/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on November 24, 2019, 12:13 AM
 */
//System Libraries
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
double opCnt=0;
//Function Prototypes
struct Data{
    int size;
    int *sortit;
    int *working;
};
//Execution Begins Here
int *fillAry(int);
void prntAry(int *,int,int);
void swap(int *, int *);
int prtiShn (int *,int,int);
void quikSrt(int *,int,int);
void heapify(int *,int, int);
void heapSrt(int *, int);
void shelSrt(int *, int);
Data *fill(int);               //Fill the Array
void print(Data *,int);        //Print the array
void merge(Data *,int,int,int);//Merge 2 Arrays algorithm
void mrgSort(Data *,int,int);  //Merge Sort Recursions
void destroy(Data *);          //Deallocate
void mrkSort(Data *);          //Mark sort/my sorting algorithm
void callMerg ();
//Execution Begins 
int main(int argc, char** argv) {
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int *array;
    int size=1000;
    int perLine=20;
    int begin, end;
    int loops=1000;
    //Initialize/Input Data/Variables
    for (int i=0;i<loops; i++){
    //array=fillAry(size);

    //Display output
    //prntAry(array,size,perLine);
    callMerg();
    //Sort
    //begin=time(0);
    //quikSrt(array,0,size-1);
    //end=time(0);
    //Display output
    //
    //prntAry(array,size,perLine);
    
    //Clean up dynamic memory
    /*delete []array;*/}
    
    cout<<"N   "<<size<<endl<<"ops "<<opCnt/loops;
    //Exit program
    return 0;
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=rand();//[10-99]
    }
    return array;
}

// A utility function to swap two elements 
void swap(int* a, int* b) { 
    opCnt+=3;
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int prtiShn(int *arr,int low,int high){ 
    opCnt+=4;
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element 
    opCnt+=3;
    for (int j = low; j <= high - 1; j++){ 
        // If current element is smaller than the pivot 
        opCnt+=5;
        if (arr[j] < pivot) 
        { 
            opCnt+=2;
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    opCnt+=5;
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

/* The main function that implements QuickSort 
arr --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quikSrt(int *arr,int low,int high){ 
    opCnt++;
    if (low < high){ 
            /* pi is partitioning index, arr[p] is now 
        at right place */
        opCnt+=2;
        int pi = prtiShn(arr, low, high); 

        // Separately sort elements before 
        // partition and after partition 

        opCnt+=4;
        quikSrt(arr, low, pi - 1); 
        quikSrt(arr, pi + 1, high); 
    } 
} 
// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int *arr, int n, int i) {
    opCnt+=7;
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 

    // If left child is larger than root 
    opCnt+=4;
    if (l < n && arr[l] > arr[largest]){ 
        opCnt+=1;    
        largest = l;}
    

    // If right child is larger than largest so far
    opCnt+=4;
    if (r < n && arr[r] > arr[largest]){
        opCnt+=1;
            largest = r; }

    // If largest is not root 
    opCnt+=1;
    if (largest != i) 
    { 
        opCnt+=3;
            swap(arr[i], arr[largest]); 

            // Recursively heapify the affected sub-tree 
            opCnt+=1;
            heapify(arr, n, largest); 
    } 
} 

void heapSrt(int *arr, int n) { 
    // Build heap (rearrange array) 
    opCnt+=4;
    for (int i = n / 2 - 1; i >= 0; i--){ 
            heapify(arr, n, i); 
            opCnt+=3;
    }

    // One by one extract an element from heap
    opCnt+=2;
    for (int i=n-1; i>=0; i--) 
    { 
        opCnt+=6;
            // Move current root to end 
            swap(arr[0], arr[i]); 

            // call max heapify on the reduced heap 
            heapify(arr, i, 0); 
    } 
} 
void shelSrt(int *arr, int n) { 
    // Start with a big gap, then reduce the gap 
    opCnt+=3;
    for (int gap = n/2; gap > 0; gap /= 2){ 
        opCnt+=3;
        // Do a gapped insertion sort for this gap size. 
        // The first gap elements a[0..gap-1] are already in gapped order 
        // keep adding one more element until the entire array is 
        // gap sorted
        opCnt+=2;
        for (int i = gap; i < n; i += 1){ 
            opCnt+=2;
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i 
            int temp = arr[i]; 
            opCnt+=2;

            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found 
            int j;
            opCnt+=5;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){ 
                
                opCnt+=10;
                    arr[j] = arr[j - gap]; }
            

            // put temp (the original a[i]) in its correct location 
            arr[j] = temp;
            opCnt+=2;
        
        } 
    } 
} 
void mrkSort(Data *a){
    //Utilize mark sort as a comparison
    for(int pos=0;pos<a->size-1;pos++){
        for(int lst=pos+1;lst<a->size;lst++){
            if(a->sortit[pos]>a->sortit[lst]){
                int temp=a->sortit[pos];
                a->sortit[pos]=a->sortit[lst];
                a->sortit[lst]=temp;
            }
        }
    }
}

void destroy(Data *a){
    //Deallocate data elements
    delete []a->sortit;
    delete []a->working;
    delete a;
}

void mrgSort(Data *a,int beg,int end){
    opCnt+=9;
    int center=(beg+end)/2;//Split the task down the middle
    if((center-beg)>1){mrgSort(a,beg,center);
    opCnt+=1;
    }//Got to be an array to split
    if((end-center)>1){mrgSort(a,center,end);
    opCnt+=1;}//Got to be an array to split
    merge(a,beg,center,end);//Merge the sorted arrays into 1 larger sorted array
}

void merge(Data *a,int beg,int nlow,int nhigh){
    //Create a merged array
    opCnt+=4;
    int span=nhigh-beg;    //Span the range to merge
    int cntl=beg,cnth=nlow;//Independent counters to merge the split
    //Fill the array
    opCnt+=2;
    for(int i=0;i<span;i++){
        opCnt+=2;
        if(cntl==nlow){//Low done fill with the higher end of array
            a->working[i]=a->sortit[cnth++];
            opCnt+=3;
        }else if(cnth==nhigh){//High done fill with lower end of array
            a->working[i]=a->sortit[cntl++];
            opCnt+=4;
        }else if(a->sortit[cntl]<a->sortit[cnth]){
            a->working[i]=a->sortit[cntl++];//Fill with lower end
            opCnt+=5;
        }else{
            a->working[i]=a->sortit[cnth++];//Fill with higher end
            opCnt+=5;
        }
    }
    //Copy back from the working array to the sorted array
    opCnt+=2;
    for(int i=0;i<span;i++){
        opCnt+=6;
        a->sortit[beg+i]=a->working[i];
    }
}

void print(Data *a,int perLine){
    //First print the unsorted array
    cout<<endl;
    for(int i=0;i<a->size;i++){
        cout<<a->sortit[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Data *fill(int n){
    //Allocate memory
    Data *data=new Data;
    data->size=n;
    data->sortit=new int[n];
    data->working=new int[n];
    for(int i=0;i<n;i++){
        data->sortit[i]=rand();
    }
    return data;
}
void callMerg (){
     //Allocate the arrays, Run on Mac
    //Mark sort data 10,000 -> 1/2 second, 100,000 -> 50 seconds
    //Merge sort  1,000,000 -> 1/2 second, 10,000,000 -> 5 seconds
    //          100,000,000 -> 60  seconds
    int n=10000,perLine=5;
    Data *a=fill(n);
    //Print the arrays
    //print(a,perLine);
    //Sort the arrays then print
    int beg=time(0);
    mrgSort(a,0,a->size);
    //mrkSort(a);
    //int totTime=time(0)-beg;
    //cout<<"Total Run Time = "<<totTime<<" Seconds"<<endl;
    //print(a,perLine);
    //Deallocate data
    destroy(a);
}
