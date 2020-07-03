#include <iostream>

using namespace std;
#define ll long long
ll sum(ll num){
    int c = 0;
    while(num>0){
        c+=num%10;
        num = num/10;
    }
    return c;
}
int main()
{
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ll maxm = INT_MIN;
        ll mul;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mul = arr[i]*arr[j];
                ll ans = sum(mul);
                maxm = max(ans,maxm);
            }
        }
        cout<<maxm<<endl;
        t--;
    }
    return 0;
}
