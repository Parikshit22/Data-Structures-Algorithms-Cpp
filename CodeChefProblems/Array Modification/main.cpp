#include <iostream>

using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t>0){
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        for(ll i=0;i<k;i++){
            ll a = i%n;
            ll b = n-(i%n)-1;
            arr[a] = arr[a]^arr[b];
        }
        for(ll i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        t--;
    }
    return 0;
}
