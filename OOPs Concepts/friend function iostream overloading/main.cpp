#include <iostream>

using namespace std;
class A{
    int a;
    int b;
    friend ostream& operator<<(ostream &, A );
    friend istream& operator<<(istream &, A );
public:
    void setdata(int x,int y){
        a = x;
        b = y;
    }
};
ostream& operator<<(ostream &dout, A c){
    cout<<c.a<<" "<<c.b<<endl;
}
istream& operator>>(istream &dout, A &c){
    int x,y;
    cin>>x>>y;
    c.setdata(x,y);
}
int main()
{
    A obj;
    cin>>obj;// operator >>(cin,obj);
    cout<<obj;
    return 0;
}
