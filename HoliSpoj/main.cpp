#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int V;
class Graph{
public:
    unordered_map<int, list<pair<int ,int > > > m;
    Graph(){}
    void addedge(int u,int v,int dist,bool bidir=true){
        m[u].push_back(make_pair(v,dist));
        if(bidir){
            m[v].push_back(make_pair(u,dist));
        }
    }
    int helper(int src,map<int,bool> &visited, map<int, int> &nodecount, int &ans){
        visited[src] = true;
        nodecount[src] =1;
        for(auto i:m[src]){
            if(!visited[i.first]){
                visited[i.first] = true;
                nodecount[src]  = nodecount[src]+ helper(i.first,visited,nodecount,ans);
                ans += 2*(min(nodecount[i.first],V-nodecount[i.first]))*i.second;
            }
        }
        return nodecount[src];
    }
    void dfs(int src){
    map<int ,bool> visited;
    map<int , int> nodecount;
    int ans = 0;
    helper(1,visited,nodecount,ans);
    cout<<ans;
    }
};

int main()
{  V=4;
    Graph g;
    g.addedge(1,2,3);
    g.addedge(2,3,2);
    g.addedge(4,3,2);
    g.dfs(1);
    return 0;
}
