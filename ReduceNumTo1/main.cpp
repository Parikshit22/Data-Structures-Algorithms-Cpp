#include <iostream>

using namespace std;
int dp[1000];
int NumTo1_BottomUP(int n){
    int q1,q2,q3;
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i=4;i<=n;i++){
        q1 = INT_MAX;
        q2 = INT_MAX;
        q3 = INT_MAX;
        if(n%3==0){
            q1 = 1+dp[i/3];
        }
        if(n%2==0){
            q2 = 1+dp[i/2];
        }
        q3 = 1+dp[i-1];
        dp[i] = min(q1,min(q2,q3));
    }
    return dp[n];
}
int NumTo1(int n){
    if(dp[n]!=-1){
        return dp[n];
    }
    int q1 = INT_MAX;
    int q2 = INT_MAX;
    int q3 = INT_MAX;
    if(n==1){
        dp[n] = 0;
        return 0;
    }
    if(n%3==0){
        q1 = 1+NumTo1(n/3);
    }
    if(n%2==0){
        q2 = 1+NumTo1(n/2);
    }

    q3 = 1+NumTo1(n-1);
    int ans = min(q1,min(q2,q3));
    dp[n] = ans;
    return ans;

}

int main()
{   int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    cout<<NumTo1_BottomUP(n);
    return 0;
}
