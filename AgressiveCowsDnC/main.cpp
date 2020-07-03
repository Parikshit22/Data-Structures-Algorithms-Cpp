#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool ispossible(ll *a,ll n,ll c,ll ans){
    ll cow = 1;
    ll idx = a[0];
    for(ll i=1;i<n;i++){
        if(a[i]-idx>=ans){
            cow++;
            idx = a[i];
        }
    }
    if(cow>=c){
        return true;
    }
    return false;

}
ll bncow(ll *a,ll n,ll c){
    ll s,e;
    s = 1,000,000,001;
    e = -1;
    for(ll i=0;i<n;i++){
        s = min(s,a[i]);
        e = max(e,a[i]);
    }
    e = e-s;
    s = 1;
    ll ans;
    while(s<=e){
        ll mid = (s+e)/2;
        if(ispossible(a,n,c,mid)){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }

    }
    return ans;
}


int main() {
    ll n,c;
    cin>>n>>c;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<bncow(a,n,c);
}
