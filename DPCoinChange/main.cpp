#include <iostream>

using namespace std;
int dp[1000];
int coinchange(int *arr,int n,int len){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int res = INT_MAX;
    for(int i=0;i<len;i++){
        if(n-arr[i]>=0){
            res = min(res,coinchange(arr,n-arr[i],len));
        }
    }
    dp[n] = (res+1);
    return res+1;
}
int optimal(int *arr,int n,int len){
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        int res = INT_MAX;
        for(int j=0;j<len;j++){
            if(n-arr[j]>=0){
                int ans = dp[n-arr[j]];
                res = min(res,ans);
            }
        }
        dp[i] = 1+(res);
    }
    return dp[n];
}

int main()
{
    int coins[] = {1,7,10};
    int n;
    cin>>n;
    int len = sizeof(coins)/sizeof(int);
    cout<<optimal(coins,n,len);
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }

    return 0;
}
