#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Graph{
public:
    map<int,list<int> >h;
    Graph(){}
    void addedge(int u,int v){
        h[u].push_back(v);
    }
    int path(int src,int des){
        queue<int> q;
        map<int,int>dist;
        map<int,int>parent;
        q.push(src);
        for(auto i:h){
            dist[i.first] = INT_MAX;
        }
        dist[src] = 0;
        parent[src] = src;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int neighbour:h[node]){
                if(dist[neighbour]>dist[node]+1){
                    dist[neighbour] = dist[node]+1;
                    q.push(neighbour);
                    parent[neighbour] = node;
                }
            }
        }
        int point = des;
        while(point!=src){
            cout<<point<<"=>";
            point = parent[point];}
            cout<<src;
            cout<<endl;
        return dist[des];



    }
};

int main()
{   Graph g;
    int n = 36;

    // Maintain a board array
    int board[n+50] = {0};

    // Example Board with '-' sign denoting snake
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    for(int u=0;u<=n;u++){
        for(int dice = 1;dice<=6;dice++){
            int v = u+dice+board[dice+u];
            g.addedge(u,v);
        }
    }
    cout<<g.path(0,36);
    return 0;
}
