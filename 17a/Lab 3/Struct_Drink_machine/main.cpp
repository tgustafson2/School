#include <iostream>
#include <iomanip>

using namespace std;

struct Drinkinfo{
    string name;
    float cost;
    int invnt;
};

int sale (Drinkinfo &);

int main(){
	//your code here
    int total=0;
    int change=0;
    Drinkinfo machine[5]={
        {"Cola", 75,20},
        {"Root Beer", 75,20},
        {"Lemon-Lime", 75, 20},
        {"Grape Soda", 80, 20},
        {"Cream Soda", 80, 20}
    };
    string drink;
    getline(cin, drink);
    
    
    do{
        
                for (int index=0; index<5;index++){
            cout<<setw(11)<<left<<machine[index].name<<machine[index].cost
                    <<"  "<<machine[index].invnt<<endl;
            
            
        }   
            cout<<"Quit"<<endl;
        
        if (drink=="Cola")
            
        {change= sale(machine[0]);
        total+= machine[0].cost;
        }
        else if (drink=="Root Beer")
            
            {change=sale (machine[1]);
            total+= machine[1].cost;
        }
        else if (drink=="Lemon-Lime")
        
            {change=sale (machine[2]);
            total+= machine[2].cost;
        }
        else if (drink=="Grape Soda")
        
            {change=sale (machine[3]);
            total+= machine[3].cost;
        }  
        else if (drink=="Cream Soda")
            
            {change=sale (machine[4]);
            total+= machine[4].cost;
        } 
        

            cout<<change<<endl;
                
            cin.ignore();
        
        getline(cin, drink);
        
    }while(drink !="Quit");
    for (int index=0; index<5;index++){
            cout<<setw(11)<<left<<machine[index].name<<machine[index].cost
                    <<"  "<<machine[index].invnt<<endl;
            
            
        } 
    cout<<"Quit"<<endl;
    cout<<total<<endl;
	return 0;
}
int sale (Drinkinfo &c){
    int money, change=0;
    cin>>money;
    if(money<=0||money>=100){
        cout<<"Please enter a different amount."<<endl;
        cin>>money;
    }
    
    c.invnt-=1;
    change=(money-c.cost);
        
}


