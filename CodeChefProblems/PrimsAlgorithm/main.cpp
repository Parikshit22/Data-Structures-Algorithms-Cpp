#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
public:
    map<int,list<pair<int,int> > > m;
    Graph(){}
    void addedge(int u,int v,int d,bool bidir = true){
        m[u].push_back(make_pair(v,d));
        if(bidir){
            m[v].push_back(make_pair(u,d));
        }
    }
    void prims(int src){
        map<int,int> dist;
        vector<pair<int,int> > g;
        set<pair<int,int> > h;
        for(auto i: m){
            dist[i.first] = INT_MAX;
        }
        h.insert(make_pair(0,src));
        while(!h.empty()){
            auto t = *(h.begin());
            int node = t.second;
            int nodedist = t.first;
            h.erase(t);
            g.push_back(make_pair(node,nodedist));
            dist[node] = nodedist;
            for(auto i: m[node]){
                if(dist[i.first]>dist[node]+i.second){
                    auto f = h.find(make_pair(dist[i.first],i.first));
                    if(f!=h.end()){
                        h.erase(f);
                    }
                    dist[i.first]=dist[node]+i.second;
                    h.insert(make_pair(dist[i.first],i.first));
                }
            }
        }
        for(int i=0;i<g.size();i++){
            cout<<g[i].first<<" " <<g[i].second<<endl;
        }
    }
};

int main()
{   Graph g;
    g.addedge(1,2,1);
    g.addedge(1,4,7);
    g.addedge(1,3,4);
    g.addedge(2,3,10);
    g.addedge(3,4,3);
    g.prims(3);
    return 0;
}
