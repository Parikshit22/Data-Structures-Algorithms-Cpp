#include <iostream>

using namespace std;
int dp[100][100];
int Winefn(int *arr,int s,int e,int year){
    if(dp[s][e]!=-1){
        return dp[s][e];
    }
    if(s>e){
        return 0;
    }

    int ans1 = year*arr[e]+Winefn(arr,s,e-1,year+1);
    int ans2 = year*arr[s]+Winefn(arr,s+1,e,year+1);
    int ans = max(ans1,ans2);
    dp[s][e] = ans;
    return ans;
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<Winefn(arr,0,n-1,1)<<endl;

    return 0;
}
