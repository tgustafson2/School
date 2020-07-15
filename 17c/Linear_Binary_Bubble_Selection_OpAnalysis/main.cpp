/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on October 15th, 2019, 10:05 AM
 * Purpose:  Common searching and sorting algorithms
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries Here

//Global Constants 
double opeq,oplt,opinc,opindex,opmin,opgt,opplus,opeqtest,opdiv;

//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void prntAry(const int [],int,int);
void fillAry(int [],int,int,int);
void swap(int &,int &);
void smlLst(int [],int,int);
void mrkSort(int [],int);
int  linSrch(int [],int, int);
int  binSrch(int [],int, int);
void bublSrt(int [],int);
void selSort(int [],int);
void copyAry(int [],int [],int);
void printOp();

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int SIZE=100;
    int array[SIZE],brray[SIZE];
    int lowRng=100,highRng=200;
    int perLine=10;
        
    //Finish initializing the rest of the array
    fillAry(array,SIZE,highRng,lowRng);
    copyAry(brray,array,SIZE);
    opeq=oplt=opinc=opindex=opmin=opgt=opplus=opeqtest=opdiv=0;
    //Print the values in the array
    prntAry(array,SIZE,perLine);
    prntAry(brray,SIZE,perLine);
    
    //Sort the array the for all positions
    //mrkSort(array,SIZE);
    bublSrt(array,SIZE);
    cout<<"The op analysis for bublSrt"<<endl;
    printOp();
    opeq=oplt=opinc=opindex=opmin=opgt=opplus=opeqtest=opdiv=0;
    selSort(brray,SIZE);
    cout<<"The op analysis for selSrt"<<endl;
    printOp();
    opeq=oplt=opinc=opindex=opmin=opgt=opplus=opeqtest=opdiv=0;
    
    //Test the linear search by randomly choosing a value and
    //determine if found;
    int value=rand()%(highRng-lowRng+1)+lowRng;
    cout<<"Using the Linear Search"<<endl;
    cout<<"The value "<<value<<" was found at position "
            <<linSrch(array,SIZE,value)<<endl;
    cout<<"The op analysis for Linear search"<<endl;
    printOp();
    opeq=oplt=opinc=opindex=opmin=opgt=opplus=opeqtest=opdiv=0;
    cout<<"Using the Binary Search"<<endl;
    cout<<"The value "<<value<<" was found at position "
            <<binSrch(brray,SIZE,value)<<endl;
    cout<<"The op analysis for Binary Search"<<endl;
    printOp();
    opeq=oplt=opinc=opindex=opmin=opgt=opplus=opeqtest=opdiv=0;
    
    
    //Print the values in the array
    prntAry(array,SIZE,perLine);
    prntAry(brray,SIZE,perLine);

    //Exit
    return 0;
}
void printOp(){
    cout<<"# of eq operations    = "<<opeq<<endl;
    cout<<"# of lt operations    = "<<oplt<<endl;
    cout<<"# of inc operations   = "<<opinc<<endl;
    cout<<"# of div operations  = "<<opdiv<<endl;
    cout<<"# of index operations = "<<opindex<<endl;
    cout<<"# of minus operations = "<<opmin<<endl;
    cout<<"# of gt operations    = "<<opgt<<endl;
    cout<<"# of plus operations  = "<<opplus<<endl;
    float optot=opeq+oplt+opinc+opdiv+opindex+opmin+opgt+opplus;
    cout<<"# of tot operations   = "<<optot<<endl;
}
void copyAry(int copyIt[],int source[],int n){
    for(int i=0;i<n;i++){
        copyIt[i]=source[i];
    }
}

void selSort(int a[],int n){
    //Loop and declare variables
    int indx,min;
    opeq+=1;oplt+=1;opmin+=1;
    for(int pos=0;pos<n-1;pos++){
        //Find the smallest in the list, swap after finding
        oplt+=2;opmin+=1;opinc+=1;
        opeq+=3;opplus+=1;opindex+=1;
        min=a[pos];indx=pos;
        for(int i=pos+1;i<n;i++){
            opgt+=1;opindex+=1;
            if(a[i]<min){
                opindex+=1;opeq+=2;
                min=a[i];
                indx=i;
            }
        }
        //Perform the swap
        opindex+=3;opeq+=2;
        a[indx]=a[pos];
        a[pos]=min;
    }
}

void bublSrt(int a[],int n){
    //Keep looping and comparing until no swaps are left
    bool swap;
    do{
        opeq+=2;oplt+=1;opmin+=1;
        swap=false;
        //Check the list and Swap when necessary
        for(int i=0;i<n-1;i++){
            opindex+=2;opgt+=1;
            if(a[i]>a[i+1]){
                opeq+=4;opindex+=4;
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
            }
        }
        opeqtest+=1;
    }while(swap);
}

int  binSrch(int a[],int n, int val){
    //Initialize end points which are indexes
    int lowEnd=0;
    int highEnd=n-1;
    opeq+=2;opmin+=1;
    //Loop until value found not indexes
    do{
        opeq+=1;opplus+=1;opdiv+=1;opeqtest+=1;opgt+=1;opindex+=1;
        int middle=(highEnd+lowEnd)/2;
        if(val==a[middle]){
            opgt-=1;opindex-=1;
            return middle;
        }
        else if(val>a[middle]){lowEnd=middle+1;
        opeq+=1;opplus+=1;}
        else {highEnd=middle-1;
        opeq+=1;opmin+=1;}
        opgt+=1;opeqtest+=1;
    }while(lowEnd<=highEnd);
    
    //Not found
    return -1;
}

int  linSrch(int a[],int n, int val){
    opeq+=1;oplt+=1;
    for(int indx=0;indx<n;indx++){
        oplt+=1;opeqtest+=1;opindex+=1;
        if(val==a[indx])return indx;
        opinc+=1;
    }
    return -1;
}

void fillAry(int a[],int n,int hr,int lr){
    for(int indx=0;indx<n;indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}

void prntAry(const int a[],int n,int perLine){
    //Print the values in the array
    cout<<endl<<"The Array Values"<<endl;
    for(int indx=0;indx<n;indx++){
        cout<<a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void mrkSort(int a[],int n){
    for(int pos=0;pos<n-1;pos++){
        smlLst(a,n,pos);
    }
}

void smlLst(int a[],int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i]){
            swap(a[pos],a[i]);
        }
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}