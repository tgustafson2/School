/* 
 * File:   main.cpp
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include <cmath>

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void xfunction (unsigned short);
void bfunction (unsigned short);
void ffunction (unsigned short);
void evenxfunction (unsigned short);
void evenbfunction (unsigned short);
void evenffunction (unsigned short);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    unsigned short x;
    char shape;       //f-> forward b->backward x->cross
    
    //Input or initialize values Here
    cout<<"Create a numbered shape that can be sized."<<endl;
    cout<<"Input an integer number [1,50] and a character [x,b,f]."<<endl;
    cin>>x>>shape;
    
    //Draw the shape
    if (x%2==1){
    if ( shape=='x'){
        xfunction (x);
    }
    else if (shape == 'f'){
        ffunction (x);
    }
    else if (shape == 'b'){
        bfunction (x);
    }
    }
    else if (x%2==0){
        if ( shape=='x'){
        evenxfunction (x);
    }
    else if (shape == 'f'){
        evenffunction (x);
    }
    else if (shape == 'b'){
        evenbfunction (x);
    }
    }

    
    //Exit
    return 0;
}
void xfunction(unsigned short value){
    for (unsigned short rows=0; rows<value; rows++){
        for (unsigned short col=0; col<value; col++){
            if (col==rows || col==((value-1)-rows)){
                cout<<(value-col);
            }
            else cout<<" ";
        }
        cout<<endl;
    }
}
void ffunction(unsigned short value){
    for (unsigned short rows=0; rows<value; rows++){
        for (unsigned short col=0; col<value; col++){
            if ( col==((value-1)-rows)){
                cout<<(value-col);
            }
            else cout<<" ";
        }
        cout<<endl;
    }
}
void bfunction(unsigned short value){
    for (unsigned short rows=0; rows<value; rows++){
        for (unsigned short col=0; col<value; col++){
            if (col==rows){
                cout<<(value-col);
            }
            else cout<<" ";
        }
        cout<<endl;
    }
}
void evenxfunction(unsigned short value){
    for (unsigned short rows=0; rows<value; rows++){
        for (unsigned short col=0; col<value; col++){
            if (col==rows || col==((value-1)-rows)){
                cout<<(col+1);
            }
            else cout<<" ";
        }
        cout<<endl;
    }
}
void evenffunction(unsigned short value){
    for (unsigned short rows=0; rows<value; rows++){
        for (unsigned short col=0; col<value; col++){
            if ( col==((value-1)-rows)){
                cout<<(col+1);
            }
            else cout<<" ";
        }
        cout<<endl;
    }
}
void evenbfunction(unsigned short value){
    for (unsigned short rows=0; rows<value; rows++){
        for (unsigned short col=0; col<value; col++){
            if (col==rows){
                cout<<(col+1);
            }
            else cout<<" ";
        }
        cout<<endl;
    }
}




/* Author: Thomas Gustafson
 * Created on March 2 2019 AND 4:47
 * Purpose:  Cross one-side or the other
*/