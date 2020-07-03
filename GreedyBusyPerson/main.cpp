#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int ,int> a,pair<int, int> b){
    return a.second<b.second;
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int ,int> > v;
    for(int i=0;i<n;i++){
        int x;
        int y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end(),compare);
    int ft = v[0].second;
    int ct = 1;
    for(int i=1;i<v.size();i++){
        if(v[i].first>=ft){
            ct++;
            ft= v[i].second;
        }
    }
    cout<<ct;
    return 0;
}
