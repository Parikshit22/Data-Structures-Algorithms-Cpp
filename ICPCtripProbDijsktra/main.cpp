#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class fare{
public:
    string city;
    int train;
    int flight;
    fare(string city,int train,int flight){
        this->city = city;
        this->train = train;
        this->flight = flight;
    }
};
class Graph{
public:
    unordered_map <string,list<fare> > m;
    Graph(){}
    void addedge(string u,string v,int flight,int train,bool bidir=true){
        fare f(v,train,flight);
        m[u].push_back(f);
        if(bidir){
            fare f2(u,train,flight);
            m[v].push_back(f2);
        }
    }
    void print(){
        for(auto i : m){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<"("<<j.city<<","<<j.train<<","<<j.flight<<")";
            }
            cout<<endl;
        }
    }

    map<string,int> dijsktra(string src){
        map<string,int> dist;
        set<pair<int,string> > s;
        for(auto i: m){
            dist[i.first] = INT_MAX;
        }
        dist[src] = 0;
        s.insert(make_pair(dist[src],src));

        while(!s.empty()){
            auto p = *(s.begin());
            string node = p.second;
            int nodedist = p.first;
            s.erase(s.begin());
            for(auto childpair : m[node]){
                if(nodedist+childpair.train<dist[childpair.city]){
                    string dest = childpair.city;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[dest] = nodedist+childpair.train;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }
        return dist;
    }

};

int main()
{   Graph g;
    g.addedge("amritsar","jaipur",5,4);
    g.addedge("amritsar","delhi",3,8);
    g.addedge("delhi","jaipur",2,6);
    g.addedge("delhi","bhopal",7,14);
    g.addedge("jaipur","pune",6,5);
    g.addedge("pune","mumbai",2,3);
    g.addedge("bhopal","mumbai",6,3);
    g.addedge("pune","goa",11,6);
    g.addedge("goa","bangalore",5,3);
    g.addedge("mumbai","bangalore",8,6);
    int ans = INT_MAX;
    map<string,int>Delhidist = g.dijsktra("delhi");
    map<string,int>Bangaloredist = g.dijsktra("bangalore");
    for(auto i:g.m){
        for(auto nearpair : g.m[i.first]){
            int flightfare = nearpair.flight;
            string des1 = i.first;
            string des2 = nearpair.city;
            int d = Delhidist[des1]+flightfare+Bangaloredist[des2];
            ans = min(ans,d);
        }
    }
    int noflight = Delhidist["bangalore"];
    cout<<min(noflight,ans);
    return 0;
}
