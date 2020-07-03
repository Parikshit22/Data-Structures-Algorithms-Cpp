#include <iostream>

using namespace std;
class B;
class A{
    int a;
    int b;
    public:
    void setdata(int x,int y){
        a= x;
        b = y;
    }
    friend void fun(A,B);
};
class B{
    int d;
    friend void fun(A,B);
    public:
     void setdata(int x){
        d= x;

    }

};
void fun(A c,B d){
    cout<<c.a<<" "<<c.b<<" "<<d.d<<endl;
}
int main()
{
    A a;
    B b;
    b.setdata(9);
    a.setdata(3,4);
    fun(a,b);
    return 0;
}
