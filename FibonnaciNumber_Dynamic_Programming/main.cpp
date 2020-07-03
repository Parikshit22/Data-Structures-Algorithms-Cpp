#include <iostream>

using namespace std;
int dp[1000];
int fibonaccidp_top_down(int n){
    if(dp[n]!= -1){
        return dp[n];
    }
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int ans = fibonaccidp_top_down(n-1)+fibonaccidp_top_down(n-2);
    dp[n] = ans;
    return ans;
}
int fibonaccidp_bottom_up(int n){
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int fibonacci(int n){

    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int ans = fibonacci(n-1)+fibonacci(n-2);
    return ans;

}


int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    cout<<fibonaccidp_bottom_up(n);
    //cout<<fibonaccidp_top_down(n);
    //cout<<fibonacci(n);
    return 0;
}
