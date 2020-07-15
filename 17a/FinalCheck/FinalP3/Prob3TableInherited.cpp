/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Prob3TableInherited.h"
template <class T>
Prob3TableInherited::Prob3TableInherited(char* filename, int rows, int cols):Prob3Table<T>(filename, rows, cols)
{

augTable = new T[(rows+1) * (cols+1)];
for(int i = 0; i < rows; i++)
for(int j = 0; j < cols; j++)
augTable[i * (cols + 1) + j] = Prob3Table<T>::table[i * cols + j];

int r, c;
c = cols;
for( r = 0; r < rows; r++)
augTable[r * (cols + 1) + c] = Prob3Table<T>::rowSum[r];

r = rows;
for( c = 0; c < cols; c++)
augTable[r * (cols + 1) + c] = Prob3Table<T>::colSum[c];

augTable[(rows +1)* (cols+1) - 1] = Prob3Table<T>::getGrandTotal();
}


