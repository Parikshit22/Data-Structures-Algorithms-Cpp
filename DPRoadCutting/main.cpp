#include <iostream>

using namespace std;
int dp[100];
int roadcutting(int *arr,int n){
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans = 0;
    if(n<=0){
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(n-i>=0){
            int q = arr[i-1]+roadcutting(arr,n-i);
            ans = max(q,ans);
        }
    }
    dp[n] = ans;
    return ans;
}

int main()
{
    int n = 4;
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    int arr[n] = {2,3,2,5};
    cout<<roadcutting(arr,n);
    return 0;
}
