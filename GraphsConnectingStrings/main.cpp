#include <iostream>
#include <bits/stdc++.h>

using namespace std;
template<typename T>
class Graph{
public:
    map<T,list<T> > h;
    Graph(){

    }
    void addedge(T u, T v,bool bidir = false){

        h[u].push_back(v);
        if(bidir){
            h[v].push_back(u);
        }
    }
    void print(){
        for(auto i =h.begin();i!= h.end();i++){
            cout<<i->first<<"->";
            for(auto j : h[i->first]){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
    void bfs(T src){
        queue <T> q;
        map <T,bool> visited;
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            for(auto neigbour: h[node]){
                if(!visited[neigbour]){
                    q.push(neigbour);
                    visited[neigbour] = true;
                }
            }
        }
    }
    void dfs(T src){
        map<T,bool> visited;
        stack<T> s;
        s.push(src);
        visited[src] = true;
        while(!s.empty()){
            T node = s.top();
            for(auto neighbour: h[node]){
                if(visited[neighbour]==false){
                    s.push(neighbour);
                    visited[neighbour]=true;
                    break;
                }
            }
            if(s.top()==node){
                cout<<s.top()<<" ";
                s.pop();
            }
        }
    }
    void Helper(T node,map<T,bool> &visited){
        for(T neighbour:h[node]){
            if(visited[neighbour]==false){
                visited[neighbour]=true;
                Helper(neighbour,visited);
            }
        }
        cout<<node<<" ";
    }
    void dfsRecurrsively(T src){
        map<T,bool> visited;
        visited[src] = true;
        Helper(src,visited);
    }
    void TopologicalHelper(T node,map<T,bool> &visited, list<T> &l){
        visited[node]=true;
        for(T neighbour:h[node]){
            if(visited[neighbour]==false){
                TopologicalHelper(neighbour,visited,l);
            }
        }
        l.push_front(node);
    }
    void dfstopologicalsort(){
        map<T,bool>visited;
        list<T> l;
        for(auto i:h){
            if(!visited[i.first]){
                TopologicalHelper(i.first,visited,l);
            }
        }
        for(auto i:l){
            cout<<i<<"-->";
        }
    }
    void BFSTopologicalSort(){
        queue<T> q;
        map<T,int>indegree;
        for(auto i : h){
            indegree[i.first] = 0;
        }
        for(auto i:h){
            T node = i.first;
            for(auto neighbour : h[node]){
                    indegree[neighbour]++;
            }
        }
        for(auto i : indegree){
            if(i.second==0){
                q.push(i.first);

            }
        }
        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node<<" ";

            for(auto neighbour:h[node]){
                    indegree[neighbour]--;
                    if(indegree[neighbour]==0){
                        q.push(neighbour);
                    }
                }

        }

    }
    bool IsCyclePresent(T src){
        map<T,bool>visited;
        map<T,T> parent;
        queue<T> q;
        q.push(src);
        while(!q.empty()){
            T node = q.front();
            q.pop();
            visited[node]= true;
            for(auto neighbour : h[node] ){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    parent[neighbour] = node;
                    visited[neighbour] = true;
                }
                else if(visited[neighbour]==true&&parent[node]!=neighbour){
                    return true;
                }
            }
        }
        return false;
    }
    bool HelperCycle(int node, map<T,bool> &visited, map<T,bool> &instack){
        visited[node] = true;
        instack[node] = true;
        for(auto neighbour : h[node]){
            if(visited[neighbour]&&HelperCycle(neighbour,visited,instack)||instack[neighbour]==true){
                return true;
            }
        }
        instack[node] = false;
        return false;
    }
    bool IsCycleReccursivelyDFS(int src){
        map<T,bool> visited;
        map<T,bool> instack;
        for(auto i: h){
            T node = i.first;
            if(!visited[node]){
                bool value = HelperCycle(node,visited,instack);
                if(value){
                    return true;
                }
            }
        }
        return false;
    }
    void path(T src){
        queue<T> q;
        map<T,int> dist;
        map<T,T> parent;
        for(auto i=h.begin();i!=h.end();i++){
            dist[i->first] = INT_MAX;
        }
        q.push(src);
        dist[src] =0;
        while(!q.empty()){
            T node = q.front();
            q.pop();
            for(auto neighnour:h[node]){
                if(dist[neighnour]==INT_MAX){
                    q.push(neighnour);
                    dist[neighnour] = dist[node]+1;
                }
            }
        }

        for(auto j :h){
            T node = j.first;
            cout<<node<<" is at distance of "<<dist[node]<<" from "<<src<<endl;
        }
    }

};
int main()
{   /*
    Graph<string> g;
    g.addedge("modi","putin",true);
    g.addedge("putin","trump");
    g.addedge("putin","Pope");
    g.addedge("modi","trump",true);
    g.addedge("prabhu","modi");
    g.addedge("yogi","modi",true);
    g.addedge("yogi","prabhu");

    g.print();
    */
    Graph<char> i;
    i.addedge('e','p');
    i.addedge('m','p');
    i.addedge('p','y');
    i.addedge('y','w');
    i.addedge('e','h');
    i.addedge('k',NULL);
    i.print();
    i.dfstopologicalsort();
    cout<<endl;
    i.BFSTopologicalSort();
    return 0;
}
