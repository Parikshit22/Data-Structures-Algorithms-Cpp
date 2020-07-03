#include <iostream>

using namespace std;



class Complex{
    int real;
    int img;
public:
    Complex(){};
    Complex(int r,int i){
        real = r;
        img = i;
    }
    void SetReal(int r){
        real = r;
    }
    void SetImg(int i){
        img = i;
    }
    int GetReal(){
        return real;
    }
    int GetImg(){
        return img;
    }
    void Print(){
        if(img>=0){
            cout<<real<<"+"<<img<<"i"<<endl;
        }
        else{
            cout<<real<<"-"<<img<<"i"<<endl;
        }
    }

    void add(Complex &X){
        real += X.GetReal();
        img += X.GetImg();
    }
    void operator+(Complex &X){
        real += X.GetReal();
        img += X.GetImg();
    }
    void operator!(){
        img *= -1;
    }
    int operator[](string s){
        if(s=="Real"){
            return real;
        }
        else{
            return img;
        }
    }

};
void operator>>(istream& io,Complex &X){
    int i;
    int j;
    io>>i>>j;
    X.SetReal(i);
    X.SetImg(j);

    }
void operator<<(ostream& io,Complex &X){
    X.Print();
}
int main()
{   Complex a(5,3);
    Complex b(2,4);
    Complex c;

    cin>>c;
    cout<<c;
    a.Print();
    return 0;
}
