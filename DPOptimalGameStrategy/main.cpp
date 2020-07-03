#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int OGS(int *arr,int s,int e){
    if(s>e){
        return 0;
    }
    if(dp[s][e]!=-1){
        return dp[s][e];
    }
    if(s==e){
        return arr[s];
    }
    int q1 = arr[s]+min(OGS(arr,s+2,e),OGS(arr,s+1,e-1));
    int q2 = arr[e]+min(OGS(arr,s+1,e-1),OGS(arr,s,e-2));
    int ans = max(q1,q2);
    dp[s][e] = ans;
    return ans;
}
int main()
{   int arr[] = {7,3,1,6,2,8,1,0,4};
    int n=sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = -1;
        }
    }
    cout<<OGS(arr,0,n-1);
    return 0;
}
