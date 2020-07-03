#include <iostream>

using namespace std;
int fibonacci(int n){

    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    int ans=(fibonacci(n-1)+fibonacci(n-2));
    return ans;

}


int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        cout<<fibonacci(i)<<" ";
    }
    /*Simple Method without Recursion
    int a=0;
    int b=1;
    int i=0;
    while(i<=n){
            if(i==0){
                cout<<a<<" ";
            }
            if(i==1){
                cout<<b+a<<" ";
            }
            if(i>=2){
            cout<<a+b<<" ";
            int c =b;
            b=a+b;
            a = c;}
            i++;

    }*/

    return 0;
}
