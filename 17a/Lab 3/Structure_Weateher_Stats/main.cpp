#include <iostream>
#include<iomanip>
using namespace std;

struct Weather{
    string month;
    int rainfall;
    int lowtemp;
    int hightemp;
    int average;
};

int main(){
	//your code here
    float tempavg=0;
    float rainavg=0;
    Weather month[12];
    for (int index=0; index<12; index++){
        cin>>month[index].month;
        cin>>month[index].rainfall;
        cin>>month[index].lowtemp;
        cin>>month[index].hightemp;
        month[index].average=(month[index].lowtemp+month[index].hightemp)/2;
        tempavg+=month[index].average;
        rainavg+=month[index].rainfall;
                
    }
    tempavg/=12;
    rainavg/=12;
    
    for (int i=0; i<12; i++){
        for (int j=0; j<11;j++){
            if (month[j].lowtemp>month[j+1].lowtemp){
                Weather temp;
                temp=month[j];
                month[j]=month[j+1];
                month[j+1]=temp;
            }
        }
    }
    
    
    cout<<"Average Rainfall "<<showpoint<<setprecision(1)<<rainavg<<" inches/month"<<endl;
    cout<<"Lowest Temperature "<<month[0].month<<"  "<<month[0].lowtemp;
    cout<<" Degrees Fahrenheit"<<endl;
    cout<<"Highest Temperature "<<month[11].month<<"  "<<month[11].hightemp;
    cout<<" Degrees Fahrenheit"<<endl;
    cout<<"Average Temperature for the year "<<setprecision(2)<<tempavg<<" Degrees Fahrenheit"<<endl;
	return 0;
}