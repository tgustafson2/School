#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
/*void bubblesort(double[], string[], int);
void swap(double &, double &, string &, string &);
*/

int main(){
	const int months=12;
	int index;
	double rainfall[months];
	float total, average, lowest, highest;
	string monthnames [months]={"January","February","March",
								"April","May","June", "July",
								"August", "Septmember","October",
								"November","December"};
	
	
	cout<< fixed<<showpoint<<setprecision(2);
	
	for (index =0; index<months; index++){
		cout<<"Enter the rainfall for "<<monthnames[index]<<"(in inches):";
		cin>>rainfall[index];
	}
	total=0;
	for (index=0; index<months; index++){
		total+=rainfall[index];
	}
	
	average=total/months;
	//bubblesort(rainfall, monthnames,months);
	
		int maxElement;
	
	for (maxElement=months-1; maxElement>0; maxElement--){
		for(index=0; index<maxElement; index++){
			if (rainfall[index]>rainfall[index+1]){
				int temp=rainfall[index];
	rainfall [index]=rainfall[index+1];
	rainfall[index+1]=temp;
	string temp2=monthnames[index];
	monthnames[index]=monthnames[index+1];
	monthnames[index+1]=temp2;	;
			}
		}
	}
	
	ofstream rainfallstats;
	rainfallstats.open("rain.txt");
	
	
	/*double stats;
	string names;
	int count;
	for (count=0; count<months; count++){
	rainfallstats<<rainfall[count]<<endl;}
	for (count=0; count<months; count++){
	rainfallmonths<<monthnames[count]<<endl;}
	/*while(rainfallstats>>stats && rainfallmonths>>names){
		cout<<names<<" "<<stats;
	I tried to read the contents of the file to check if I wrote the arrays to the file.
	I'm not sure why it won't work.
	
	
	*/
	
	rainfallstats<< fixed<<showpoint<<setprecision(2);
	rainfallstats<<"The total rainfall is:"<<setw(28)<<right<<total<<"\n";
	rainfallstats<<"The average rainfall per month is:"<<setw(16)<<right<<average<<"\n";
	rainfallstats<<setw(12)<<left<<monthnames[11]<<"has the highest rainfall at:"<<setw(10)<<right<<rainfall[11]<<"\n";
	rainfallstats<<setw(12)<<left<<monthnames[0]<<"has the lowest rainfall at:"<<setw(11)<<right<<rainfall[0]<<"\n";
	

	rainfallstats.close();
        ifstream rainfallmonths.open;
        rainfallmonths.open("rain.txt");
        cout>>rainfallmonths;
	

	cout << "Files written!" << endl;
	
	
	cout<<"The total rainfall is:"<<setw(28)<<right<<total<<"\n";
	cout<<"The average rainfall per month is:"<<setw(16)<<right<<average<<"\n";
	cout<<setw(12)<<left<<monthnames[11]<<"has the highest rainfall at:"<<setw(10)<<right<<rainfall[11]<<"\n";
	cout<<setw(12)<<left<<monthnames[0]<<"has the lowest rainfall at:"<<setw(11)<<right<<rainfall[0]<<"\n";
}

/*void bubblesort(double array[],string array[],int size){
		
		int maxElement;
		int index;
	
	for (maxElement=size-1; maxElement>0; maxElement--){
		for(index=0; index<maxElement; index++){
			if (rainfall[index]>rainfall[index+1]){
				swap(rainfall [index], rainfall[index+1],monthnames[index],monthnames[index+1])

			}
		}
	}
}
void swap(double &a, double &b, string &c, string &d){
	double temp=rainfall[index];
	rainfall [index]=rainfall[index+1];
	rainfall[index+1]=temp;
	string temp2=monthnames[index];
	monthnames[index]=monthnames[index+1];
	monthnames[index+1]=temp2;	;
}
Also I tried to write it as three separate programs, but it kept saying conflicting declaration
If it is possible could you let me know how, if it isn't why is it not possible?



*/
