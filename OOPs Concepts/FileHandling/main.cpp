#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

int main()
{   /*
    ofstream out;
    out.open("abc.txt");
    out<<"hello";
    out.close();
    */
    ifstream in;
    in.open("abc.txt");
    char ch;
    in>>ch;
    while(!in.eof()){
        cout<<ch;
        in>>ch;
    }
    in.close();
    getch();
    return 0;
}
