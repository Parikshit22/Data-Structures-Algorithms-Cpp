#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
class Movie{
public:
    string Title;
    int ReleaseDate;
    void Print(){
        cout<<"Movie Name "<<Title<<" Release Date "<<ReleaseDate<<endl;
    }
};
bool compare(Movie a, Movie b){
    if((a.Title).length()<=(b.Title).length()){
        if(a.Title<=b.Title){
        return true;}
    }
    return false;
}
int main()
{   Movie marr[]= {
                    {"Worldwide",2009},
                    {"WorldIsEnding",2004},
                    {"SeeYouLater",1998},
                    {"Everything Is Ok",2017},
                    {"Hello",1994}
                     };

    int n = sizeof(marr)/sizeof(Movie);
    sort(marr,marr+n,compare);
    for(int i=0;i<n;i++){
        marr[i].Print();
    }



    return 0;
}
