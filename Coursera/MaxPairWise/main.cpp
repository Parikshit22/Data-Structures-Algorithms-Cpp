#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long num;
    cin>>num;
    vector<long long> arr(num);
    for(long long i =0;i<num;i++){
        cin>>arr[i];
    }
    long long maxm = INT_MIN;
    long long smaxm = INT_MIN;
    for(long long i=0;i<num;i++){
        if(arr[i]>=maxm){
            smaxm = maxm;
            maxm = arr[i];
            continue;
        }
        if(arr[i]>smaxm){
            smaxm = arr[i];
        }
    }
    cout<<maxm*smaxm<<endl;
    return 0;
}
