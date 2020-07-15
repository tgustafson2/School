/* 
 * File:   main.cpp
 * Author: Thomas Gustafson
 * Created on March 3, 2019 2:12
 * Purpose:  Summing, Finding the Max and Min of an integer array
 * Note:  Look at the output for the format for print
 */

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(int [],int);
int  stat(const int [],int,int &,int &);
void print(const int [],int,int,int,int);
void sort (int [], int);
void swap (int *, int *);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    sort(array, sizeIn);
    
    //Find the sum, max, and min
    sum= stat(array,sizeIn,max,min);//Output the sum, max and min
    
    //Print the results
    print(array,sizeIn,sum,max,min);//print the array, sum, max and min

    //Exit
    return 0;
}
void read (int arr[], int size){
    int count;
    
    
    cout<<"Enter your array elements: ";
    for (count=0; count<size;count++){
    cin>>arr[count];
    }
   
}
int stat (const int arr[], int size, int &max, int &min){
    int sum=0;
    max=arr[size];
    min=arr[0];
    for (int count=1; count<=size; count++){
        sum+=arr[count];
    }
    
    
    return sum;
}






void sort (int arr[], int size){
    int i, j;
    for (i=0;i<size;i++){
        for(j=0;j<size;j++){
            
            if (arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
    }
    
}
}




void print (const int arr[], int size,int sum, int max, int min ){
    for(int i=1;i<=size;i++){
        if(i<10){
        cout<<"a["<<i-1<<"] = "<<arr[i]<<endl;
        }
        else{
           cout<<"a["<<i-1<<"] = "<<arr[i]<<endl; 
        }
        
        
    }
    cout<<"Min  = "<<arr[1]<<endl;
        cout<<"Max  = "<<arr[size]<<endl;
        cout<<"Sum  = "<<sum<<endl;
}

void swap (int *a, int *b){
    
    int temp=*a;
    *a=*b;
    *b=temp;
}