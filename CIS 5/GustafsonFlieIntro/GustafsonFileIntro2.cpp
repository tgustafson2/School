// All necessary include directives here
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

//main function here
int main ()
{
	string filename;
	
	//prompt user for filename
	cout << "Enter name of file you want to read: ";
	// cin>> filename;
	getline(cin,filename,'\n');
	//declare an ifstream object for file input
	ifstream inputFile;
	
	// try to open the file
	inputFile.open(filename.c_str());
	if(inputFile)
	{
		int input, sum=0, count=0;
		//read in all integer values in the file until -999999 encountered
		do
		{
			if((input file >> input))
			{
				cout << "Found the value: " << input << endl;
				
				if (input== -999999) break;
				sum=sum+input;
				count++;
			}
			else break;
		} while ( input!= -999999);
		
		//close the file when we are done
		inputFile.close();
		
		//output the average
		cout<< "Average: " << setw(10) << fixed << setprecision(5);
		cout<< sum/(float)count << endl;
		
	}
	else
	{
		cout <<"File could not be opended for reading.."<< endl;
		return 1;
	}
	return 0; // this line is optional
	
}