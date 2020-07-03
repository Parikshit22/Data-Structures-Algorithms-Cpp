#include <iostream>

using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t>0){
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        ll maxm = 0;
        for(ll i=1;i<n;i++){
            ll cnt = 0;
            for(ll j = i-1;j>=0;j--){
                if(arr[j]%arr[i]==0){
                    cnt++;
                }
            }
            maxm = max(cnt,maxm);
        }
        cout<<maxm<<endl;
        t--;
    }
    return 0;
}
