#include<bits/stdc++.h>

using namespace std;
class A
{public:
    int x;
protected:
    int y;
private:
    int z;
    public:
    A(){
    cout<<"this is A";
    }
    void fun(){
        cout<<"in a";
    }

};

class B : public A
{public:
    B(){
    cout<<"this is b";
    }
    // x is public
    // y is protected
    // z is not accessible from B

    void fun(){
        cout<<"in b";
    }
};

class C : protected A
{
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A    // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};

int main(){

    A *a = new B();
    a->fun();
return 0;
}
