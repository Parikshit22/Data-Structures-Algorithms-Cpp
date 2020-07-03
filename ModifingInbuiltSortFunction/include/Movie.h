#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>

class Movie{
public:
    string Title;
    int ReleaseDate;
    void Print(){
        cout<<"Movie Name "<<Title<<" Release Date "<<ReleaseDate<<endl;
    }
};

#endif // MOVIE_H
