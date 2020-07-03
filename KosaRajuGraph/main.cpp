#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class graph{
public:
    map<int,list<int> > for_m;
    map<int,list<int> > rev_m;
    Graph(){}
    void addedge(int u,int v){
        for_m[u].push_back(v);
        rev_m[v].push_back(u);
    }
    void dfshelper(int src,map<int,bool> &visited,map<int,list<int> > m){
        visited[src]= true;
        for(auto neighbour: m[src]){
            if(!visited[neighbour]){
                visited[neighbour]= true;
                dfshelper(neighbour,visited,m);
            }
        }
    }
    bool check(int src){
        map<int,bool> visited;
        dfshelper(src,visited,for_m);
        for(auto i:for_m){
            if(!visited[i.first]){
                return false;
            }
        }
        for(auto i:for_m){
            visited[i.first] = false;
        }
        dfshelper(src,visited,rev_m);
        for(auto i:rev_m){
            if(!visited[i.first]){
                return false;
            }
        }
        return true;
    }
};
int main()
{   graph g;
    g.addedge(1,2);
    g.addedge(3,1);
    g.addedge(2,3);
    if(g.check(1)){
        cout<<"yes";
    }
    else{
        cout<<"NO";
    }
    return 0;
}
