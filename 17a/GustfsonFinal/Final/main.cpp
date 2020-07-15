/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on June 6, 2019, 6:34 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Employee.h"
#include "SavingsAccount.h"
#include "Prob1Random.h"
//I am on a 64 bit windows 10
using namespace std;

/*
 * 
 */
template<class T>
class Prob3Table
{
	protected:
		int rows;                                 //Number of rows in the table
		int cols;                                 //Number of cols in the table
		T *rowSum;                                //RowSum array
		T *colSum;                                //ColSum array
		T *table;                                 //Table array
		T grandTotal;                             //Grand total
		void calcTable(void){
grandTotal = 0;
for(int i = 0; i < rows; i++){
rowSum[i] = 0;
for(int j = 0; j < cols; j++){
rowSum[i] += table[i * cols + j];
}
/*for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cout<<naugT[i*cols+j]<<" ";*/
grandTotal += rowSum[i];
}

for(int k = 0; k < cols; k++){
    colSum[k]=0;
for(int l = 0; l < rows; l++){
colSum[k] += table[l * cols + k];
}
}
};                     //Calculate all the sums
	public:
		Prob3Table(char *filename,int rows,int cols) {
                    
ifstream in(filename);
if(in.fail()){
cout << "ERROR: could not read input file " << filename << endl;
exit(1);
}
table = new T[rows * cols];
this->rows = rows;
this->cols = cols;
for(int i = 0; i < rows; i++)
for(int j = 0; j < cols; j++)
in >> table[i * cols + j];

in.close();
rowSum = new T[rows];
colSum = new T[cols];
calcTable();
};               //Constructor then Destructor
		~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
		const T *getTable(void){return table;};
		const T *getRowSum(void){return rowSum;};
		const T *getColSum(void){return colSum;};
		T getGrandTotal(void){return grandTotal;};
};
template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
	protected:
		T *augTable;                                  //Augmented Table with sums
	public:
		Prob3TableInherited(char* filename, int rows, int cols):Prob3Table<T>(filename, rows, cols){

augTable = new T[(rows+1) * (cols+1)];
for(int i = 0; i < rows; i++){
for(int j = 0; j < cols; j++){
augTable[i * (cols + 1) + j] = Prob3Table<T>::table[i * cols + j];}
}
for(int r = 0; r < rows; r++){
augTable[r * (cols + 1) + cols] = Prob3Table<T>::rowSum[r];
}
for( int c = 0; c < cols; c++){
augTable[rows * (cols + 1) + c] = Prob3Table<T>::colSum[c];
}
augTable[(rows +1)* (cols+1) - 1] = Prob3Table<T>::getGrandTotal();
}
;          //Constructor
		~Prob3TableInherited(){delete [] augTable;};  //Destructor
		const T *getAugTable(void){return augTable;}; 
};
template<class T>
class Prob2Sort
{
private:
    int *index;
public:
    Prob2Sort()
    { index = NULL; }
    ~Prob2Sort()
    { delete []index; }

    T* sortArray(const T* type, int i, bool max)
    { return sortArray(type, i, 1, 1, max); }

    T* sortArray(const T* a, int row, int column, int sort, bool ascending){
        T* array = new T[(row * column)];
        bool sorted = true;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++)
                array[column * i + j] = a[column * i + j];
        }
        


            if(ascending == false){
                for(int i = 0; i < row-1 ; i++){
                    if(array[column * i + sort] < array[column * (i + 1) + sort]){
                      
                        for(int j = 0; j < column; j++){
                            T temp;
                            temp = array[i * column +j];
                            array[i * column + j] = array[(i + 1) * column + j];
                            array[(i + 1) * column + j] = temp;
                        }
                    }
                }
            }

            else{for (int l=(row)-1; l>0; l--){
                for(int i = 0; i < row-1 ; i++){
                    if(array[column * i + sort-1] > array[column * (i + 1) + sort-1]){
                     
                        for(int j = 0; j < column; j++){
                            T temp;
                            temp = array[i * column + j];
                            array[i * column + j] = array[(i + 1) * column + j];
                            array[(i + 1) * column + j] = temp;
                        }
                    }
                }
            }
            }
       
        return array;
    }
};
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
int main(int argc, char** argv) {
    int inN;
        do{
         
         cout<<"Enter the problem:";
         cin>>inN;
         
         switch(inN){
          case 1:    problem1();break;
          case 2:    problem2();break;
          case 3:    problem3();break;
          case 4:    problem4();break;
          case 5:    problem5();break;
          case 6:    problem6();break;
}
        }while(inN<7);

    return 0;
}

void problem1(){
    
   
    	char n=5;
	char rndseq[]={18,33,56,79,125};
	int ntimes=100000;

	Prob1Random a(n,rndseq);
	for(int i=1;i<=ntimes;i++)
	{
		a.randFromSet();
	}
	int *x=a.getFreq();
	char *y=a.getSet();
	for(int i=0;i<n;i++)
	{
		cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
	}
	cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}
void problem2(){
        cout<<"The start of Problem 2, the sorting problem"<<endl;
	Prob2Sort<char> rc;
	bool ascending=true;
	ifstream infile;
	infile.open("Problem2.txt",ios::in);
	char *ch2=new char[10*17];
	char *ch2p=ch2;
	while(infile.get(*ch2)){cout<<*ch2;ch2++;}
	infile.close();
       

	cout<<"Sorting on which column"<<endl;
	int column;
	cin>>column;
	char *zc=rc.sortArray(ch2p,10,17,column,ascending);
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<17;j++)
		{
			cout<<zc[i*17+j];
		}
	}
	delete []zc;
}
void problem3(){
        cout<<"Entering problem number 3"<<endl;
	int rows=5;
	int cols=6;
	Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
	const int *naugT=tab.getTable();
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cout<<naugT[i*cols+j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	const int *augT=tab.getAugTable();
	for(int i=0;i<=rows;i++)
	{
		for(int j=0;j<=cols;j++)
		{
			cout<<augT[i*(cols+1)+j]<<" ";
		}
		cout<<endl;
	}
}
void problem4(){
        SavingsAccount mine(-300);

	for(int i=1;i<=10;i++)
	{
		mine.Transaction((float)(rand()%500)*(rand()%3-1));
	}
	mine.toString();
	cout<<"Balance after 7 years given 10% interest = "
		<<mine.Total((float)(0.10),7)<<endl;
	cout<<"Balance after 7 years given 10% interest = "
		<<mine.TotalRecursive((float)(0.10),7)
		<<" Recursive Calculation "<<endl;
}
void problem5(){
        	Employee Mark("Mark","Boss",215.50);
	Mark.setHoursWorked(-3);
	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(20.0),
		Mark.setHoursWorked(25));
	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(40.0),
		Mark.setHoursWorked(25));
	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(60.0),
		Mark.setHoursWorked(25));
	Mark.toString();

	Employee Mary("Mary","VP",50.0);
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(40));
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(50));
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(60));
	Mary.toString();
}
void problem6(){
    cout<<"3.75 is"<<endl<<"in hex 3.C"<<endl<<"in octal 3.6"<<endl<<"in Binary 11.11"
            <<endl<<"in hex float 78000003"<<endl;
    cout<<".7 is"<<endl<<" in hex .B3 with 3 repeating"<<endl<<"in octal .54631463 with 1463 repeating"
            <<endl<<"in Binary .101100 with 1100 repeating"<<endl<<"in hex float 59999901"<<endl;
    cout<<"89.9 is"<<endl<<" in hex 59.E6 with 6 repeating"<<endl<<"in octal 131.71463 with 1463 repeating"<<endl
            <<"in binary 1011001.1110011 with 0011 repeating"<<endl<<"in hex float 59E66607"<<endl;
}