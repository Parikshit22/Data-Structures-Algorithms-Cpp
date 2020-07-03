#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t>0){
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        ll sum = arr[0];
        for(ll i=1;i<n;i++){
            sum = sum^arr[i];
        }
        ll num=0;
        ll temp;
        ll series=0;
        for(ll i=0;i<n-1;i++){
            series = series^arr[i];
            temp = sum^series;
            if(temp == series){
                num++;
            }
        }
        cout<<num<<endl;
        t--;
    }
    return 0;
}
