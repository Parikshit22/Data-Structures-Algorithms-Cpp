#include <iostream>

using namespace std;
class Parent{
public:
    Parent(int x){
    }


};
class Child: public Parent{
public:
    Child(int a):Parent(a){}
    //or you can declare your own default constructor in parent class.
};
int main()
{
    Child a(4);
    return 0;
}
