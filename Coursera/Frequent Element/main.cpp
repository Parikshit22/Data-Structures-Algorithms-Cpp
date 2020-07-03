#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{   map<int,int > arr;
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        arr[x]++;
    }
    int maxm = INT_MIN;
    int val;
    for(auto i : arr){
        if(i.second==maxm){
            if(val<i.first){
                val = i.first;
            }
        }
        if(i.second>maxm){
            maxm = i.second;
            val = i.first;
        }
    }
    cout<<val;
    return 0;
}
