#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n;
class Graph{
public:
    unordered_map<int , list<int> > m;
    Graph(){}
    void add(int u,int v){
        m[u].push_back(v);
    }
    int print(){
        vector<int> v;
        int j=0;
        for(auto i: m){
            v.push_back(m[i.first].size()+1);
        }
        int ans = ((n)*(n-1))/2;
        for(int i=0;i<v.size();i++){
            ans -= ((v[i])*(v[i]-1))/2;
        }
        return ans;
    }


};
int main()
{
    cin>>n;
    int p;
    cin>>p;
    Graph g;
    for(int i=0;i<p;i++){
        int temp1,temp2;
        cin>>temp1>>temp2;
        g.add(temp1,temp2);
    }
    cout<<g.print();

    return 0;
}
