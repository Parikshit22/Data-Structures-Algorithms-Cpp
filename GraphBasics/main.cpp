#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Graph{
public:
    int v;
    vector<vector<int> > s;
    Graph(int v){
        this->v = v;
    }
};

int main()
{
    Graph G(5);
    map<int ,vector<int > > h;
    for(int i=0;i<2;i++){
        cout<<"enter vertices connected to "<<i<<"th vertice"<<endl;
        G.s.push_back(vector<int>());
        int num;
        cin>>num;
        while(num!=-1){
            G.s[i].push_back(num);
            cin>>num;
        }
        h.insert(make_pair(i,G.s[i]));
    }

    /*
    if we use unordered map than we should use this to iterrate
    for(int it=0;it!=h.bucket_count();it++){
        cout<<it<<"-> ";
        for(int j=0;j<(G.s)[it].size();j++){
            cout<<(G.s)[it][j]<<",";
       }
       cout<<endl;
    }
    */

    for(auto it=h.begin();it!=h.end();it++){
        cout<<it->first<<"-> ";
        for(auto j:(it->second)){
            cout<<j<<",";
       }
       cout<<endl;
    }

    return 0;
}
