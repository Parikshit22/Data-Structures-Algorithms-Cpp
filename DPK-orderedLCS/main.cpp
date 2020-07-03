#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int dp[100][100][10];
int m,n;
int in[100];
int out[100];
int KLCS(int i, int j,int k){
    if(i==m||j==n){
        return 0;
    }
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    int res =0;
    if(in[i]==out[j]){
        res = 1+KLCS(i+1,j+1,k);
    }
    else{
        if(k>0){
            res = 1+KLCS(i+1,j+1,k-1);
        }
        res = max(res,KLCS(i,j+1,k));
        res = max(res,KLCS(i+1,j,k));
    }
    dp[i][j][k] = res;
    return res;
}

int main()
{
    int k;
    cin>>m;
    cin>>n;
    cin>>k;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<m;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>out[i];
    }
    cout<<KLCS(0,0,k);

    return 0;
}
