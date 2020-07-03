#include <iostream>

using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t>0){
        ll n,k,d;
        cin>>n>>k>>d;
        ll stop[n+1];
        for(ll i=0;i<n;i++){
            cin>>stop[i];
        }
        stop[n] = k;
        int lane[n+1];
        for(ll i=0;i<n;i++){
            cin>>lane[i];
        }
        if(lane[n-1]==1){
            lane[n] = 0;
        }
        else{
            lane[n] =1;
        }
        ll dis = stop[1];
        ll diff = stop[1];
        int i =1;
        while(i<n){
            if(lane[i]==lane[i+1]){
                dis = stop[i+1];
                diff = stop[i];
                i++;
            }
            else{
                if(stop[i]-stop[i-1]<=1){
                    break;
                }
                dis = stop[i+1];
                diff = stop[i+1]-stop[i];
                i++;
                if(diff<d){
                    break;
                }
            }
        }

        cout<<dis<<endl;
        t--;
    }
    return 0;
}
