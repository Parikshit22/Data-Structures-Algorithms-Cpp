#include <iostream>

using namespace std;
void GCD(int a,int b){
    if(b==0){
        cout<<a;
    }
    GCD(b,a%b);
}
int main()
{   int a,b;
    cin>>a>>b;
    if(a<=b){
        GCD(a,b);
    }
    else{
        GCD(b,a);
    }
    return 0;
}
