/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on May 31, 2019, 7:37 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>


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
int main(int argc, char** argv) {
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

    return 0;
}

