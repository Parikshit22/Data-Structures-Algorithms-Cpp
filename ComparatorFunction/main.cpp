#include <iostream>
#include <bits/stdc++.h>

using namespace std;
bool compare(pair<string ,int > a,pair<string, int> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}

int main()
{
    vector <pair<string , int> > v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string x;
        int y;
        cin>>x;
        cin>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    return 0;
}
