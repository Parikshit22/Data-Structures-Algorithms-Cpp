#include <iostream>

using namespace std;
class A{
    void fun(){}
    void foo(){}
    friend class B;

};

class B{
 friend void A:: fun();
 friend void A:: foo();
};
int main()
{   A obj1;
    B obj2;
    return 0;
}
