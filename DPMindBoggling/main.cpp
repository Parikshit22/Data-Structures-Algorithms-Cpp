#include <iostream>

using namespace std;
int dp[100];
int mb(int *a,int k){
    dp[0] = 0;
    dp[1] = a[1]*1;
    for(int i=2;i<k;i++){
        dp[i] = max(((i*a[i])+dp[i-2]),dp[i-1]);
    }
    return dp[k-1];
}

int main()
{   int k=5;
    int a[k]={0};
    int arr[] = {3,4,0,1,1,3,2,1,2,3,4,4};
    int n = sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++){
        a[arr[i]]++;
    }
    cout<<mb(a,k);

    return 0;
}
