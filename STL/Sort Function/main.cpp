#include <iostream>
#include <algorithm>
using namespace std;
class Book{
public:
    string name;
    int price;
    Book(string name,int price){
        this->name = name;
        this->price = price;
    }
    void print(){
        cout<<this->name<<" "<<this->price<<endl;
    }
};

bool mycompare(Book a, Book b){
    if(a.price==b.price){
        return a.name>b.name;
    }
    return a.price<b.price;
}

int main()
{
    Book a[] = {Book("abs",323),Book("few",342),Book("fefg",34),Book("ab",34)};
    int n = sizeof(a)/sizeof(a[0]);
    sort(a,a+n,mycompare);
    for(int i=0;i<n;i++){
        a[i].print();
    }
    return 0;
}
