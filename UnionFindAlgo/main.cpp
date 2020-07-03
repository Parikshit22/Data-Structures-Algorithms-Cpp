#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int V;
int E;
class e{
public:
    int src;
    int dest;
};
class Graph{
public:
    e *edge;
    Graph(){
        edge = new e[E];
    }
    bool ufa(){
        map<int,int> parent;
        map<int,int> ranknode;
        for(int i=0;i<V;i++){
            parent[i] = -1;
            ranknode[i] = 0;
        }
        for(int i=0;i<E;i++){
            if(ranknode[edge[i].src]==ranknode[edge[i].dest]){
                if(parent[edge[i].src]==-1&&parent[edge[i].dest]==-1){
                    parent[edge[i].src] = edge[i].dest;
                    ranknode[edge[i].dest]++;
                }
                else if(parent[edge[i].src]>parent[edge[i].dest]){
                    parent[edge[i].dest]=parent[edge[i].src];
                    ranknode[parent[edge[i].src]]++;
                }
                else if(parent[edge[i].src]==parent[edge[i].dest]){
                    return true;
                }
                else{
                    parent[edge[i].src]=parent[edge[i].dest];
                    ranknode[parent[edge[i].dest]]++;
                }
            }
            else if(ranknode[edge[i].src]>ranknode[edge[i].dest]){
                parent[edge[i].dest] = edge[i].src;
                ranknode[edge[i].src]++;
            }
            else{
                parent[edge[i].src] = edge[i].dest;
                ranknode[edge[i].dest]++;
            }
        }
        return false;

    }
};

int main()
{   Graph *graph = new Graph();
    V = 5;
    E = 5;
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 2;
    graph->edge[2].dest = 3;

    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 2;
    graph->edge[3].dest = 4;

    // add edge 1-4 (or A-E in above figure)
    graph->edge[4].src = 4;
    graph->edge[4].dest = 0;
    if(graph->ufa()){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}
