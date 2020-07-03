#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int compute(int W,int n,pair<int,int> *vw){
        if(W==0||n==0){
            return 0;
        }
        else if(W<vw[n-1].second){
            return compute(W,n-1,vw);
        }
        else{
            return max((vw[n-1].first+compute(W-vw[n-1].second,n-1,vw)),compute(W,n-1,vw));
        }
}
int main()
{   int n;
    cin>>n;
    int W;
    cin>>W;
    pair<int,int> vw[n];
    for(int i=0;i<n;i++){
        int v;
        int w;
        cin>>v>>w;
        vw[i].first = v;
        vw[i].second = w;
    }
    int a = compute(W,n,vw);
    cout<<a;
    return 0;
}
