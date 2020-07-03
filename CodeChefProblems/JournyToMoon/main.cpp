#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class graph{
public:
    map<int,list<int> > h;
    graph(){}

    void addedge(int v,int u){
        h[v].push_back(u);
        h[u].push_back(v);
    }
    void dfshelper(int node,map<int,int> &visited,int &sum){
        visited[node] = true;
        for(auto i : h[node]){
            if(!visited[i]){
                dfshelper(i,visited,sum);
                sum++;
            }
        }
    }

    void dfsnodes(){
        map<int,int> visited;
        for(auto i: h){
            if(!visited[i.first]){
                int sum = 1;
                dfshelper(i.first,visited,sum);
                cout<<sum<<endl;
            }
        }
    }
};

int main()
{
    graph g;
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(1,5);
    g.addedge(5,6);
    g.addedge(7,8);
    g.dfsnodes();
    return 0;
}
