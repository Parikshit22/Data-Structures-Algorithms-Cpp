#include <iostream>

using namespace std;
class car{
    int speed;
    string name;

public:
    void setter(int a, string b){
        speed = a;
        name = b;
    }
    void display();
    void fun(){
        cout<<"hello";
    }
    int fun(){
        cout<<"hii";
    }

};
inline void car:: display(){
    cout<<speed<<" "<<name<<endl;
}
// inline can be written at both at the time of declaration or defination
int main()
{
    car c;
    c.setter(10,"bmw");
    c.display();
    return 0;
}
