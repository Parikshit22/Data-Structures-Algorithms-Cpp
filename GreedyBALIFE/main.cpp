#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans =0;
    int total =0;
    for(int i=0;i<n;i++){
        total+=arr[i];
    }
    total = total/n;
    for(int i=1;i<n;i++){
        int s1 = 0;
        int e1 = i-1;
        int size1 = e1-s1+1;
        int num1=0;
        for(int j=s1;j<=e1;j++){
            num1+=arr[j];
        }
        num1 = abs((size1*total)-num1);
        ans = max(ans,num1);
    }
    cout<<ans;
    return 0;
}
