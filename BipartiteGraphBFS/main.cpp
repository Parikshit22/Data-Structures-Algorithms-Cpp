#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Graph{
public:
    map<int,list<int> > m;
    Graph(){}
    void addedge(int u,int v,bool bidir = true){
        m[u].push_back(v);
        if(bidir){
            m[v].push_back(u);
        }
    }
    bool check(int src){
        map<int,bool> visited;
        map<int,bool> colour;
        queue<int> q;
        visited[src] = true;
        colour[src] = true;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i:m[node]){

                if(!visited[i]){
                    visited[i] = true;
                    colour[i] = !colour[node];
                    q.push(i);
                }
                else if(visited[i]){
                    if(colour[i]==colour[node]){
                        return false;

                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Graph g;
    g.addedge(1,3);
    g.addedge(2,1);
    g.addedge(3,2);
    g.addedge(3,4);

    if(g.check(1)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}
