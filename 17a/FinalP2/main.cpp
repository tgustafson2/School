/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tgust
 *
 * Created on June 1, 2019, 2:50 PM
 */
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;
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
int main (int argc, char**argv){
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
	cout<<endl;
}
    