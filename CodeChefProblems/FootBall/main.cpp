#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int a[n];
        int b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        int maxm = 0;
        for(int i=0;i<n;i++){
            a[i]=20*a[i];
            b[i] = 10*b[i];
            a[i]=a[i]-b[i];
            if(a[i]<0){
                a[i]=0;
            }
            maxm = max(maxm,a[i]);
        }
        cout<<maxm<<endl;
        t--;
    }
    return 0;
}
