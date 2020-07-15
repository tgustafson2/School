// All necessary include directives here
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
// main function here
int main ()
{
	string filename;
	
	//prompt user for filename;
	cout<< "Enter name of file you want to write: ";
	getline(cin,filename,'\n');
	
	//declare an ofstream object for file output
	ofstream outputFile;
	
	//try to open the file
	outputFile.open(filename.c_str());
	
	if (outputFile)
	{
		float input;
		do
		{
			//prompt user for integer to input, -999999 stops the loop and closes the file
			cout<< "Enter a number (-999999 to stop): ";
			cin>> input;
			
			if ( input == -999999) break;
			
			outputFile << setw(8) << input "\r\n";
			outputFile.flush();
		
		} while(input != -999999);
	}
	else
	{
		cout << "File could not be opened for writing..." << endl;
		return 1;
	}
	outputFile.close();
	cout << "File named: " << filename << "written." << endl;
	
	//your main program goes here
	return 0; // this line is optional
	}

