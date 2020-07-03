#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin>>t;
    while(t>0){
        long long n;
        cin>>n;
        long long b;
        cin>>b;
        long long i=1;
        long long ans;
        while(n>0){
            n = n-b;
            ans = i%b;
            i++;
        }
        if(ans==0){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
        t--;
    }
    return 0;
}
