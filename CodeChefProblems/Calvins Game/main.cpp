#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long k;
    cin>>k;
    vector<long long> arr;
    for(long long i=0;i<n;i++){
        long long temp;
        cin>>temp;
        arr.push_back(temp);
    }
    long long i= k;
    long long dp[n-k];
    int j=0;
    int maxm = 0;
    int index = i;
    if(arr[i+1]>0){
        dp[j]=arr[i+1];
        i++;
        maxm += dp[j];
    }
    else if(arr[i+1]<=0&&arr[i+2]>0){
        dp[j] = arr[i+2];
        i = i+2;
        maxm += dp[j];
    }
    else{
        if(dp[i+1]>dp[i+2]){
            dp[j] = arr[i+1];
            i = i+1;
        }
        else{
            dp[j] = arr[i+2];
            i = i+2
        }
    }
    j++;
    index = i;
    while(i<n){
        if()
    }

    return 0;
}
