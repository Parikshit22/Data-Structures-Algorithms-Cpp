#include <iostream>
#include <list>
using namespace std;
class Graph{
public:
    list<int> *l;
    int v;
    Graph(int v){
    this->v = v;
    l = new list<int>[v];
    }
    void addedge(int v,int u,bool bidir = false){
        l[v].push_back(u);
        if(bidir){
            l[u].push_back(v);
        }
    }
    void print(){
        for(int i=0;i<v;i++){
            cout<<i<<"->";
            for(int vertex : l[i]){
                cout<<vertex<<",";
            }
            cout<<endl;
        }
    }
};

int main()
{   Graph g(5);
    g.addedge(0,1,true);
    g.addedge(0,3);
    g.addedge(1,2,true);
    g.addedge(2,0,true);
    g.addedge(2,3);
    g.addedge(3,1);
    g.addedge(3,4,true);
    g.addedge(4,1,true);

    g.print();
    return 0;
}
