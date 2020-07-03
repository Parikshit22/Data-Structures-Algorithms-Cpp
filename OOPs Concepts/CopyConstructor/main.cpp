#include <iostream>

using namespace std;
class A{
    public:
    A(int x){
        cout<<"parametrized constructor"<<endl;
    }
    //now as we have declared a parameterized constructor so we need to
    //initialize the default constructor by our own, complier will not do it now.

    A(){
        cout<<"default constructor"<<endl;
    }
    //Also the compiler make default copy constructor by it's own.
    //we can even overwrite copy constructor.
    A(A &a){
        cout<<"Copy constructor"<<endl;
    }
    // Here we need to pass argument in reference as while initializing th copy constructor
    // will be called again and again so it'll struck in infinite loop.


};
int main()
{   A c(8);
    A a;
    A b(a);
    return 0;
}
