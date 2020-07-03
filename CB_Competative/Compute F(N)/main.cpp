#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;


int main()
{
    vector<ll> arr;
    ll t;
    cin>>t;
    while(t>0){
        ll n;
        cin>>n;
        int b = n/2;
        if(n%2==0){
            cout<<b<<endl;
        }
        else{
            cout<<-(b+1)<<endl;
        }

        t--;
    }
    return 0;
}
