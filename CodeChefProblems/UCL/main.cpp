#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool mycompare(pair<string,pair<int,int> > p1,pair<string,pair<int,int> > p2){
    if(p2.second.first==p1.second.first){
        return p1.second.second>p2.second.second;
    }
    return p1.second.first>p2.second.first;
}

int main()
{
    int t;
    cin>>t;
    while(t>0){
        unordered_map<string,pair<int ,int > > m;
        for(int i=0;i<12;i++){
            string t1;
            string t2;
            string ignore;
            int s1;
            int s2;
            cin>>t1;
            cin>>s1;
            cin>>ignore;
            cin>>s2;
            cin>>t2;
            if(s1>s2){
                m[t1].first = m[t1].first+3;
            }
            else if(s2>s1){
                m[t2].first = m[t2].first+3;
            }
            else{
                m[t1].first = m[t1].first+1;
                m[t2].first = m[t2].first+1;
            }
            m[t1].second = m[t1].second+(s1-s2);
            m[t2].second = m[t2].second+(s2-s1);
        }
        vector<pair<string,pair<int,int> > > v;
        for(auto iterator = m.begin();iterator!=m.end();iterator++ ){
            v.push_back(*iterator);
        }
        sort(v.begin(),v.end(),mycompare);
        cout<<v[0].first<<" "<<v[1].first<<endl;

        t--;


    }
    return 0;
}
