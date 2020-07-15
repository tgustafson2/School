// learn how to read data from a text file called "students.txt" for
// learning how to work with parallel arrays, sorting and searching

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
void bubblesortgpa(int[] , string[] , string[] , double[] , int);
void bubblesortid (int[], string[], string[], double[], int);
void bubblesortlast(int[], string[], string[], double[], int);

int linearsearch (int [], int, int); // for studentid
int linearsearch (double [], int, double); // for gpa
int linearsearch (string [], int, string); // for student name

void binarysearch (int[], string [], string [], double [], int, int); // binary search for student id
void binarysearch (int[], string [], string [], double [], int, double); // binary search for gpa
void binarysearch (int[], string [], string [], double [], int, string); // binary search for student name

void swap (int &, int &, string &, string &, string &, string &, double &, double &);

void output_records(int id[], string first[], string last[], double g[], 
        int rows)
{
    cout << "Student ID        First Name       Last Name GPA " << endl;
    cout << "=================================================" << endl;
    
    for(int c=0;c<rows;c++)
    {
        cout << setw(10) << id[c];
        cout << "   " << setw(15) << first[c];
        cout << " " << setw(15) << last[c];
        cout << " " << setw(4) << fixed << setprecision(2) << g[c] << endl;
    }
}

int get_number_of_records()
{
    ifstream inFile;
    inFile.open("students.txt");
    
    if (inFile)
    {
        int count=0;
        string line;
        
        do
        {
            getline(inFile,line,'\n');
            count++;
        } while (line != "");
        
        inFile.close();
        
        return count-1;
    }
    else
    {
        return -1;  // -1 means we could not open the file, -1 records is an error        
    }

}

int main(int argc, char** argv) {

    int rows = get_number_of_records();

    string studentid="studentid";
    string studentname="studentname";
    string gpasort="gpa";
    
    if (rows==-1)
    {
        cout << "Could not open the file: students.txt" << endl;
        return 1;
    }
    
    // declare all of our parallel arrays
    int student_id[rows];
    string first_name[rows];
    string last_name[rows];
    double gpa[rows];
    string sorter, search;
    sorter="null";
    search="null";
    // reopen the file students.txt to populate the arrays.
    ifstream inFile;
    inFile.open("students.txt");
    
    if(inFile)
    {
        // read in all the data
        for(int c=0;c<rows;c++)
        {
            inFile >> student_id[c];    // read in the student id
            
            string tb;
            
            getline(inFile, tb, '\t');
            getline(inFile, first_name[c], '\t'); // read in tab delimited first name            
            // inFile >> first_name[c];
            getline(inFile, last_name[c], '\t'); // read in tab delimited last name
            //inFile >> last_name[c];
            
            inFile >> gpa[c]; // read the gpa
        }
        
        inFile.close();
         
    cout<<"Would you like to sort by student id, student last name, or gpa?\n";
    cout<<"Valid inputs are studentid, studentname, and gpa.";
    cin>> sorter;

    while (!(sorter==studentid || sorter==studentname || sorter==gpasort)){
        cout<<"Invalid input. Please enter valid input.";
        cin>>sorter;
    }
    if(sorter==studentid){
        bubblesortid (student_id, first_name, last_name, gpa, rows);
    }
    else if (sorter == studentname){
        bubblesortlast (student_id, first_name, last_name, gpa, rows);
    }
    else if (sorter ==gpasort){
        bubblesortgpa (student_id, first_name, last_name, gpa, rows);
    }
   
        
        
        
        output_records(student_id, first_name, last_name, gpa, rows);
    }
    else 
    {
        cout << "Could not open the file: students.txt" << endl;
        return 1;
     
      
        
        
    }
    
 cout<<"Would you like to search by last name, student id, or gpa(same inputs as previously)?";
    cin>>search;
    while (!(search==studentname || search==gpasort || search==studentid)){
        cout<<"Invalid input. Please enter valid input.";
        cin>>search;
    }
    if (search==studentname){
        string searchkey="studentnames";
        string nvalue;
        double gvalue=0;
        cout<<"Enter the last name of the student you are looking for:";
        cin>>nvalue;
   int searchval= linearsearch(last_name, rows, nvalue );
   // do a check for searchval==-1, if -1 then value not found
   while (searchval==-1){
       searchval=0;
       cout<<"Name not found, please reenter name.";
       cin>>nvalue;
       
       searchval= linearsearch(last_name, rows, nvalue );
   }
  cout<<"A linear search returns\n";
   cout << setw(10) << student_id[searchval];
        cout << "   " << setw(15) << first_name[searchval];
        cout << " " << setw(15) << last_name[searchval];
        cout << " " << setw(4) << fixed << setprecision(2) << gpa[searchval] << endl;
        binarysearch(student_id, first_name, last_name, gpa, rows, nvalue);
    }
    else if(search==gpasort){
        string searchkey="gpa";
        double gvalue;
        string nvalue;
        nvalue="null";
        cout<<"Enter the GPA of the student you are looking for:";
        cin>>gvalue;
        int found_index= linearsearch(gpa, rows, gvalue);
        
        // do a check for found_index==-1, if -1 then value not found
        while (found_index==-1){
            found_index=0;
       cout<<"GPA not found, please reenter GPA.";
       cin>>nvalue;
        found_index= linearsearch(last_name, rows, nvalue );
   }
  cout<<"A linear search returns\n";
   cout << setw(10) << student_id[found_index];
        cout << "   " << setw(15) << first_name[found_index];
        cout << " " << setw(15) << last_name[found_index];
        cout << " " << setw(4) << fixed << setprecision(2) << gpa[found_index] << endl;
        binarysearch(student_id, first_name, last_name, gpa, rows, gvalue);
    }
    else if(search==studentid){
       
        int ivalue;
      
        cout<<"Enter the ID of the student you are looking for:";
        cin>>ivalue;
        int found_index= linearsearch(student_id, rows, ivalue);
        // do a check for found_index==-1, if -1 then value not found
        while (found_index==-1){
            found_index=0;
       cout<<"ID not found, please reenter ID.";
       cin>>ivalue;
        found_index= linearsearch(student_id, rows, ivalue );
   }
        
  cout<<"A linear search returns\n";
   cout << setw(10) << student_id[found_index];
        cout << "   " << setw(15) << first_name[found_index];
        cout << " " << setw(15) << last_name[found_index];
        cout << " " << setw(4) << fixed << setprecision(2) << gpa[found_index] << endl;
        binarysearch(student_id, first_name, last_name, gpa, rows, ivalue);
        
    }
    
    return 0;
}


void bubblesortid (int id[], string first [], string last [], double g[], int rows){
    
    
    int maxElement;
    
    int index;
    for (maxElement=rows-1; maxElement>0; maxElement--){
        for (index=0; index<maxElement; index++){
            if (id[index]>id[index+1]){
                swap(id[index], id[index+1], first [index], 
                         first[index+1], last [index],
                         last[index+1], g[index],  g[index+1]);
            }
           
        }
    }
    
    
    
}

//done

void bubblesortlast (int id[], string first [], string last [],
        double g[], int rows){
    
    int maxElement;
    int index;
    for (maxElement=rows-1; maxElement>0; maxElement--){
        for (index=0; index<maxElement; index++){
      
    string last1=last[index];
    string last2=last[index+1];
   
    if(last1>last2){
        swap(id[index], id[index+1], first [index], 
                         first[index+1], last [index],
                         last[index+1], g[index],  g[index+1]);
    }
        }
    }
}

//done

void bubblesortgpa (int id[], string first [], string last [], double g[], int rows){
     
     int maxElement;
    int index;
    for (maxElement=rows-1; maxElement>0; maxElement--){
      
        for (index=0; index<maxElement; index++){
             
            if (g[index]>g[index+1]){
                
                swap(id[index], id[index+1], first [index], 
                         first[index+1], last [index],
                         last[index+1], g[index],  g[index+1]);
            }
           
        }
    }
       
}
//done

int linearsearch (int student_id[], int size, int value) // for student id
{
	int index=0;
 	int position=-1;
  	bool found = false;
  	while (index<size && !found){
  		if (student_id[index]==value){
  			found=true;
  			position=index;
  	}
  	index++;
  	}
  	return position;	
}

int linearsearch (double gp[], int size, double value) // for gpa
{
	int index=0;
 	int position=-1;
  	bool found = false;
  	while (index<size && !found){
  		if (gp[index]==value){
  			found=true;
  			position=index;
  	}
  	index++;
  	}
  	return position;	
}

int linearsearch (string name[], int size, string value1) // for student name
{
 int index=0;
 int position=-1;
  bool found = false;
  while (index<size && !found){
  if (name[index]==value1){
  found=true;
  position=index;
  }
  index++;
  }
  return position;
}
//done
void binarysearch(int studentid[], string firstname[], string lastname[], double gp[], int rows, string search){
        
  
  
        bubblesortlast(studentid, firstname, lastname, gp, rows);
        int first = 0,
                last = rows-1,
                middle,
                position=-1;
        bool found = false;
        while (!found && first<=last){
            middle = (first+last)/2;
            if (lastname[middle]==search){
                found=true;
                position=middle;
            }
            else if (lastname[middle]>search){
                last=middle-1;
            }
            else
                first=middle+1;
                
        }
         cout<<"A binary search returns\n";
   cout << setw(10) << studentid[position];
        cout << "   " << setw(15) << firstname[position];
        cout << " " << setw(15) << lastname[position];
        cout << " " << setw(4) << fixed << setprecision(2) << gp[position] << endl;
       
    }
   
void binarysearch (int studentid[], string firstname[], string lastname[], double gp[], int rows, int search){
     bubblesortid(studentid, firstname, lastname, gp, rows);
        int first = 0,
                last = rows-1,
                middle,
                position=-1;
        bool found = false;
        while (!found && first<=last){
            middle = (first+last)/2;
            if (studentid[middle]==search){
                found=true;
                position=middle;
            }
            else if (studentid[middle]>search){
                last=middle-1;
                
            }
            else
                first=middle+1;
      
                
        }
              cout<<"A binary search returns\n";
        cout << setw(10) << studentid[position];
        cout << "   " << setw(15) << firstname[position];
        cout << " " << setw(15) << lastname[position];
        cout << " " << setw(4) << fixed << setprecision(2) << gp[position] << endl;
        
                                                                     }
//done
void binarysearch(int studentid[], string firstname[], string lastname[], double gp[], int rows, double search){
      bubblesortgpa(studentid, firstname, lastname, gp, rows);
        int first = 0,
                last = rows-1,
                middle,
                position=-1;
        bool found = false;
        while (!found && first<=last){
            middle = (first+last)/2;
            if (gp[middle]==search){
                found=true;
                position=middle;
            }
            else if (gp[middle]>search){
                last=middle-1;
                
            }
            else
                first=middle+1;
                
        }
         cout<<"A binary search returns\n";
   cout << setw(10) << studentid[position];
        cout << "   " << setw(15) << firstname[position];
        cout << " " << setw(15) << lastname[position];
        cout << " " << setw(4) << fixed << setprecision(2) << gp[position] << endl;
}
//done
void swap(int &a, int &b, string &c, string &d, string &e, string &f,
        double &g, double &h){
    
    int temp1=a;
    a=b;
    b=temp1;
    string temp2=c;
    c=d;
    d=temp2;
    
    string temp3=e;
    e=f;
    f=temp3;
    
    double temp4=g;
    g=h;
    h=temp4;


}
//done
