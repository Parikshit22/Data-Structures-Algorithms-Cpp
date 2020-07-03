#include <bits/stdc++.h>

using namespace std;
# define ll long long
int main()
{
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int pos = n-2;
        while(pos>=0){
            if(pos == 0){
                if(arr[pos]>arr[pos+1]){
                    swap(arr[pos],arr[pos+1]);
                    pos--;
                }
            }
            else{
                if((arr[pos]-arr[pos+1])>=(arr[pos-1]-arr[pos])){
                    swap(arr[pos+1],arr[pos]);
                    pos = pos-2;
                }
                else if((arr[pos]-arr[pos+1])<(arr[pos-1]-arr[pos])){
                    swap(arr[pos-1],arr[pos]);
                    pos = pos-3;
                }
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum +=(i+1)*arr[i];
        }
        cout<<sum<<endl;
        t--;
    }

    return 0;
}
