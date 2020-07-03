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
        ll c[n];
        for(ll i=0;i<n;i++){
            cin>>c[i];
        }
        ll h[n];
        for(ll i=0;i<n;i++){
            cin>>h[i];
        }
        ll arr[n]={0};
        for(ll i=0;i<n;i++){
            int start = i-c[i];
            if(start<0){
                start =0;
            }
            arr[start]++;
            int end = i+c[i];

            if(end<(n-1)){
                arr[end+1]--;
            }
        }
        for(int i=1;i<n;i++){
            arr[i] += arr[i-1];
        }
        sort(arr,arr+n);
        sort(h,h+n);
        ll co=0;
        for(ll i=0;i<n;i++){
            if(h[i]!=arr[i]){
                co=1;
                break;
            }
        }
        if(co==1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
        t--;
    }

    return 0;
}
