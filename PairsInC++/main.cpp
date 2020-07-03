#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
bool compare(pair<string,int> a,pair<string,int> b){
    return a.first>b.first;
    }

int main()
{   vector <pair<string,int> >v;
    int n;
    cin>>n;
    cin.get();
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int p;
        cin>>p;
        pair <string,int> mypair(s,p);
        v.push_back(mypair);
    }
    for(int i=0;i<n;i++){
        cout<<v[i].first<<":"<<v[i].second<<endl;
    }
    sort(v.begin(),v.end(),compare);

    return 0;
}
