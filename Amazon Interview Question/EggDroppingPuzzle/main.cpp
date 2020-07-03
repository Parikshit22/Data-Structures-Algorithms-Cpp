#include <iostream>

using namespace std;
int dp[100][100];
int compute(int n,int k){
    if(n==0){
        return k;
    }
    if(k==0||k==1){
        return k;
    }
    int ans = INT_MAX,res;
    for(int i=1;i<=k;i++){
        res = max(compute(n-1,i-1),compute(n,k-i));
        if(res<ans){
            ans = res;
        }
    }

    return ans+1;
}

int main()
{
    int k;
    cin>>k;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;k++){
            dp[i][j] = -1;
        }
    }
    cout<< compute(1,n);
    return 0;
}
