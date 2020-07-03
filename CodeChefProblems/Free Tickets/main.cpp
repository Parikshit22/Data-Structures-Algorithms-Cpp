#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V;
    int E;
    cin>>V;
    cin>>E;
    long long dp[V][V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            dp[i][j] = INT_MAX;
        }
    }
    for(int i=0;i<V;i++){
        dp[i][i]=0;
    }
    for(int i=0;i<E;i++){
        int u;
        int v;
        cin>>u;
        cin>>v;
        int dist;
        cin>>dist;
        dp[u-1][v-1] = dist;
        dp[v-1][u-1] = dist;
    }
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            if(i==k){
                continue;
            }
            for(int j=0;j<V;j++){
                if(j==k){
                    continue;
                }
                long long x = (dp[i][k]+dp[k][j]);
                dp[i][j] = min(dp[i][j],x);
            }
        }
    }
    long long m = INT_MIN;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(i==j){
                continue;
            }
            m = max(m,dp[i][j]);
        }
    }
    cout<<m<<endl;
    return 0;
}
