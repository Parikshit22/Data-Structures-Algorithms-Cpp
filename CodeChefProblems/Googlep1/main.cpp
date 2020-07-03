#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool countsetbits(ll n){
    int count=0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    if(count%2==0){
        return true;
    }
    return false;
}
int main()
{   int t;
    cin>>t;
    ll ty;
    while(t>0){
        cout<<"Case #"<<ty<<": ";
        ty++;
        ll n;
        ll q;
        cin>>n>>q;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        pair<ll,ll> pr[q];
        for(ll i=0;i<q;i++){
            ll p;
            ll v;
            cin>>p>>v;
            pr[i].first = p;
            pr[i].second = v;
        }
        ll maxm;
        for(ll i=0;i<q;i++){
            arr[pr[i].first] = pr[i].second;
            maxm = 0;
            for(ll m=0;m<n;m++){
                for(ll l=m;l<n;l++){
                    ll num=0;
                    for(ll r=m;r<=l;r++){
                        num = num^arr[r];
                    }
                    if(countsetbits(num)){
                        maxm = max((l-m+1),maxm);
                    }
                }
            }
            cout<<maxm<<" ";
        }
        cout<<endl;
        t--;
    }
    return 0;
}
