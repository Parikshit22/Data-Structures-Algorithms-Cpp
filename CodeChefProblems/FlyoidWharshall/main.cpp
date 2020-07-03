#include <iostream>

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
        dp[u][v] = dist;
        dp[v][u] = dist;
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
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
