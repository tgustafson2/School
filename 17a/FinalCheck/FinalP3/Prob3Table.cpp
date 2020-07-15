/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <fstream>
#include <iostream>
#include "Prob3Table.h"
template <class T>

Prob3Table<T>::Prob3Table(char *filename,int r,int c) //Constructor then Destructor
{
ifstream in(filename);
if(in.fail()){
cout << "ERROR: could not read input file " << filename << endl;
exit(1);
}
table = new T[r * c];
rows = r;
cols = c;
for(int i = 0; i < r; i++)
for(int j = 0; j < c; j++)
in >> table[i * c + j];

in.close();
rowSum = new T[r];
colSum = new T[c];
calcTable();
}

template<class T>
void Prob3Table<T>::calcTable(void) //Calculate all the sums
{
grandTotal = 0;
for(int r = 0; r < rows; r++){
rowSum[r] = 0;
for(int c = 0; c < cols; c++){
rowSum[r] += table[r * cols + c];
}

grandTotal += rowSum[r];
}

for(int c = 0; c < cols; c++){
colSum[c] = 0;
for(int r = 0; r < rows; r++){
colSum[c] += table[r * cols + c];
}
}
}