#include <iostream>

using namespace std;
int mincost(int grid[3][3],int r,int c){
    int dp[3][3] = {};
    dp[0][0] = grid[0][0];
    for(int i = 1;i<c;i++){
        dp[0][i] = dp[0][i-1]+grid[0][i];
    }
    for(int i = 1;i<r;i++){
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
        }
    }
    return dp[r-1][c-1];
}

int main()
{
    int grid[3][3] = {{1,2,3},
                      {4,8,2},
                      {1,5,3}};
    int c = sizeof(grid[0])/sizeof(grid[0][0]);
    int r = sizeof(grid)/sizeof(grid[0]);

    cout<<mincost(grid,r,c);



    return 0;
}
