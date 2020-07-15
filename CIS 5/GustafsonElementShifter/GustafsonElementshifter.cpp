#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int *expandarray (int *, int);
void displayarray (int[],int);

int main(){
	
	int size;
	
	
	cout<<"Enter how many elements you want the initial array to contain:";
	cin>>size;
	if (size<=0)
		exit(0);
	
	
	
	int *numarr= new int[size];
	
	for (int index=0; index<size; index++){
		cout<<"Enter the value you want stored in the "<<index<<" element: ";
		cin>>numarr[index];
	}
	
	cout<<"Here are the contents of the original array\n";
	displayarray (numarr, size);
	
	int *duparr= nullptr;
	int size1=size+1;
	duparr=expandarray(numarr, size);
	cout<<"Here are the contents of the new array\n";
	displayarray (duparr, size1);
	
	delete [] numarr;
	delete [] duparr;
	duparr= nullptr;
	
	
	
	
	
	
	
}



int *expandarray(int *arr, int size2){
	
	int *newArray = nullptr;
	
	if (size2<=0)
	return nullptr;
	
	newArray = new int [size2+1];
	
	for ( int index =0; index<size2; index++){
		newArray[0]=0;
		newArray[index+1]= arr [index];
	}
	
	return newArray;
}

void displayarray (int *arr, int size3){
	for (int index=0; index<size3; index++)
	cout <<arr[index]<<" ";
	cout<<endl;
	
}
