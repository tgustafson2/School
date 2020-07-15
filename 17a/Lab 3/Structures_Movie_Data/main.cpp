#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct MovieData
{
    string title;
    string director;
    int year;
    int runtime;
};

void dispdata (const MovieData &);


int main(){
	//your code here
    int mnum;
    cout<<"This program reviews structures"<<endl;
    cout<<"Input how many movies, the Title of the Movie, Director, Year Released,"
            " and the Running Time in (minutes)."<<endl;
    cin>>mnum;
    
    MovieData *movie= nullptr;
    movie= new MovieData[mnum];
    for (int index=0; index<mnum; index++){
        cin.ignore();
        getline(cin, movie[index].title);
        getline(cin, movie[index].director);
        cin>>movie[index].year;
        cin>>movie[index].runtime;
    }
    for (int index=0; index<mnum; index++){
        dispdata (movie[index]);
    }
    
    
	return 0;
}

void dispdata (const MovieData &m){
    cout<<endl;
    cout<<setw(11)<<left<<"Title:";
    cout<<m.title<<endl;
    cout<<setw(11)<<left<<"Director:";
    cout<<m.director<<endl;
    cout<<setw(11)<<left<<"Year:";
    cout<<m.year<<endl;
    cout<<setw(11)<<left<<"Length:";
    cout<<m.runtime<<endl;
    
    
}
    