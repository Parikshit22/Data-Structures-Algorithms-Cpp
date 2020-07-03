#include <stdio.h>
#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ll n;
    cin>>n;
    int sum = 0;
    int b= 1;
    int a;
    while(true){
        a=n/(pow(5,b));
        if(a<=0){
            break;
        }
        sum+=a;
        b++;
    }
    cout<<sum<<endl;
    return 0;
}
