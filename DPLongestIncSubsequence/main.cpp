#include <iostream>

using namespace std;
int dp[100];
int LIS(int *arr,int n){
    for(int i=0;i<n;i++){
        dp[i] = 1;
    }
    for(int i=1;i<n;i++){
        int ans =0;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                ans = max(ans,1+dp[j]);
            }
        }
        dp[i] = ans;
    }
    int maxm=0;
    for(int i=0;i<n;i++){
        maxm = max(maxm,dp[i]);
    }
    return maxm;
}

int main()
{
    int arr[] = {2,2,2,3,3,1,4,5};
    int n = sizeof(arr)/sizeof(int);
    cout<<LIS(arr,n);

    return 0;
}
