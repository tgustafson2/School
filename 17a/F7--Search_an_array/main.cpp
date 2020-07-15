/* 
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 * 
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()

using namespace std;

//User Libraries Here
#include <string>

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    
    
    

    
    print(match);
    
    //Exit
    return 0;
}

int srch1 (const char sntnce[],const char pattern[], int start){
    int position = -1;
    int index=0;
    int size= strlen(sntnce);
    int psize= strlen (pattern);
    bool found = false;
    string patr, sentence;
     patr.assign(pattern);
     sentence.assign(sntnce);
    
    position=sentence.find (patr,start);
    if (position==string::npos){
        return -1;
    }
    
    
    return position;
}
void srchAll (const char sntnce[], const char pattern [], int match[]){
    int size = strlen(sntnce);
    int count=0;
    int index=0;
    int retval;
    
    do{
        retval = srch1 (sntnce, pattern, index);
        match[count]=retval;
        count++;
        index=retval+1;
        //retval++;
        
    }while (retval!=-1);
    
    
}
void print (const char output[]){
    
    string str (output);
    cout<<str<<endl;
    
    ;
}
void print (const int output[]){
    
    
    int n=81;
    
    if (output[0]==-1){
            cout<<"None"<<endl;
            exit(0);
        }
    
    for(int index=0; index<n; index++){
        
        
     if (output[index]>-1){
        cout<<output[index]<<endl;
   }
     else if (output[index]==-1){
         exit(0);
     }
}
}
