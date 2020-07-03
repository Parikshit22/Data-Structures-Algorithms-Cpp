#include <iostream>

using namespace std;
int arr[1000][1000];
int dp[1000][1000];
int a,b;
int RobotAndPath(int m,int n){
    if(m==a-1&&n==b-1){
        return 1;
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    if(arr[m][n+1]==-1&&arr[m+1][n]==-1){
            return 0;
        }
    if(m==a||n==b){
        return 0;
    }
    int x = 0;
    if(m<a||n<b){
        if(arr[m][n+1]!=-1){
            x += RobotAndPath(m,n+1);
        }
        if(arr[m+1][n]!=-1){
            x += RobotAndPath(m+1,n);
        }
    }
    dp[m][n]= x;
    return x;
}
int BottomUpApproch(int row,int col){
    if(dp[0][0]==-1){
        return 0;
    }
    if(dp[row-1][col-1]==-1){
        return 0;
    }
    for(int i=0;i<col;i++){
        if(dp[0][i]==-1){
            break;
        }
        dp[0][i] = 1;
    }
    for(int i=0;i<row;i++){
        if(dp[i][0]==-1){
            break;
        }
        dp[i][0] = 1;
    }
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(dp[i][j]==-1){
                continue;
            }
            if(dp[i-1][j]!=-1){
                dp[i][j] = dp[i-1][j];
            }
            if(dp[i][j-1]!=-1){
                dp[i][j]+= dp[i][j-1];
            }
        }
    }
    return dp[row-1][col-1];
}

int main()
{
    cin>>a>>b;
    int k;
    cin>>k;

    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        dp[x-1][y-1] = -1;
        arr[x-1][y-1] = -1;
    }
    cout<<BottomUpApproch(a,b);
    return 0;
}
