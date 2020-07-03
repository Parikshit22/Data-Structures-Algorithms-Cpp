#include <iostream>

using namespace std;
int arr[100];
int dp[100][100];
int mixtures(int *arr,int n){
    for(int i =0;i<n;i++){
        dp[i][i] = arr[i];
    }
    int ans =INT_MAX;
    int x;
    int y;

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            dp[i][j] = (dp[i+1][j]+arr[i])%100;
            if(dp[i+1][j]*arr[i]>=dp[i][j-1]*arr[j]){
                x = dp[i][j-1];
                ans+=x*arr[j];
            }
            else{
                x = dp[i+1][j];
                ans+= x*arr[i];
            }


        }
    }
    return ans;
}
int sumof(int s,int e){
    int sum=0;
    for(int i=s;i<=e;i++){
        sum += arr[i];
        sum %=100;
    }
    return sum;
}
int Mixture(int s,int e){
    if(s>=e){
        return 0;
    }
    if(dp[s][e]!=-1){
        return dp[s][e];
    }
    dp[s][e] = INT_MAX;
    for(int k=0;k<=e;k++){
        dp[s][e] = min(dp[s][e],Mixture(s,k)+Mixture((k+1),e)+sumof(s,k)*sumof(k+1,e));
    }
    return dp[s][e];
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<mixtures(arr,n);
    return 0;
}
