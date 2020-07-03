#include <iostream>

using namespace std;
class A{
    int a;
    const int b;
    int &c=a;
public:
    A(int x):b(5){
        a = x;
    }
};
int main()
{
    A obj(2);
    return 0;
}
