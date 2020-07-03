#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Fruit{
public:
    string name;
    int price;
    string city;
    Fruit(){}
    Fruit(string name,int price,string city){
        this->name = name;
        this->price = price;
        this->city = city;
    }
};

int main(){
    unordered_map<string,Fruit> h;
    Fruit f("Apple",110,"jaipur");
    pair<string,Fruit>mypair(f.name,f);
    h.insert(mypair);
    Fruit f1("chiku",80,"chirana");
    h.insert(make_pair(f1.name,f1));
    Fruit f2("Mango",100,"mumbai");
    h["Mango"] = f2;
    for(auto i=0;i<h.bucket_count();i++){
        cout<<"elemets in "<<i<<" th bucket is-> ";
        for(auto it=h.begin(i);it!=h.end(i);it++){
            cout<<it->first<<","<<it->second.price<<","<<it->second.city<<"||";
        }
        cout<<endl;
    }

return 0;
}
