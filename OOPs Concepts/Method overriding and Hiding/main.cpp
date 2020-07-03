#include <iostream>

using namespace std;
class A{
public:
    void fun(int c){}
    void fun2(){cout<<"hello";}
    int fun(){return 2;}
};
class B: public A{
public:
    void fun(){} //method overriding
    void fun2(int x){cout<<"nope"<<endl;} //method hiding
};

int main()
{
    B obj;
    A o;
    o.fun2(3);

    cout<<o.fun();
    return 0;
}
