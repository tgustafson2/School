/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int &,int &);//Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;      
    
    
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}

void read(int array [][COLMAX],int &row,int &col){
    cout<<"Input a table and output the Augment row,col and total sums."<<endl;
    cout<<"First input the number of rows and cols. <20 for each"<<endl;
    cout<<"Now input the table."<<endl;
    
    cin>>row>>col;
    for (int index=0; index<row; index++){
        for (int index2=0; index2<col; index2++){
            cin>>array [index][index2];
        }
    }
    
}
void sum(const int array [][COLMAX],int row,int col,int augarray [][COLMAX]){
    int augrow, augcol;
    augrow=row+1;
    augcol=col+1;
    int colsum=0;
    int rowsum=0;
    int finalsum=0;
    for(int index=0; index<row; index++){
        rowsum=0;
        for (int index2=0; index2<col; index2++){
            augarray[index][index2]=array[index][index2];
            rowsum+=array[index][index2];
        }
        augarray [index][col]=rowsum;
    }
     for(int index3=0; index3<col; index3++){
         rowsum=0;
        for (int index4=0; index4<row; index4++){
            
            rowsum+=array[index4][index3];
        }
        augarray [row][index3]=rowsum;
     }
    for (int sumindex=0; sumindex<augrow; sumindex++){
        finalsum+=augarray [sumindex][col];
    }
    augarray [row][col]=finalsum;
    
}
void print(const int arr[][COLMAX],int row,int col,int width){
   for (int index=0; index<row; index++){
       for (int index2=0; index2<col; index2++){
           cout<<setw(width)<<right<<arr[index][index2];
       }
       cout<<endl;
   } 
}