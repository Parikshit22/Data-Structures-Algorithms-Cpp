#include <bits/stdc++.h>

using namespace std;
bool isprime(long long num){
    if(num==1){
        return false;
    }
    for(long long i=2;i*i<=num;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}
long long cc(long long num){
    long long c=0;
    for(long long i=1;i*i<=num;i++){
        if(num%i==0){
            if(isprime(i)){
                c++;
            }
            if(isprime(num/i)){
                c++;
            }
        }
    }
    return c;
}
int main(){
    long long n;
    cin>>n;
    long long k,s;
    cin>>k>>s;
    long long *arr =new long long[n];
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    long long dp[n][n]={0};
    for(long long i=0;i<n;i++){
        dp[i][i] = arr[i];
    }

    for(long long i=0;i<n;i++){
        for(long long j=i+1;j<n;j++){
            dp[i][j] = dp[i][j-1]*arr[j];
        }
    }
    for(long long i=0;i<n;i++){
        for(long long j=i;j<n;j++){
            dp[i][j] = cc(dp[i][j]);
        }
    }
    long long magic[n][n] = {0};
    long long maxm = INT_MIN;
    for(long long i=0;i<n;i++){
        for(long long j=i;j<n;j++){
            long long sum=0;
            for(long long l = i;l<=j;l++){
                sum+=arr[l];
            }
            magic[i][j] = sum*(k-dp[i][j]*s);
            maxm = max(maxm,magic[i][j]);
        }
    }
    cout<<maxm;

return 0;
}
