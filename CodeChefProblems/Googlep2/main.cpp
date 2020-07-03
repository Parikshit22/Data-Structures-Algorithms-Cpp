#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    ll ty;
    while(t>0){
            cout<<"Case #"<<ty<<": ";
        ty++;
        ll n,q,m;
        cin>>n>>q>>m;
        if(m==0){
            for(ll i=0;i<q;i++){
                ll u;
                char o;
                cin>>u>>o;
            }
            for(ll i=0;i<q;i++){
                cout<<1<<" ";
            }
        }
        else{
            pair<ll,char> pr[q];
            for(ll i=0;i<q;i++){
                ll x;
                char a;
                cin>>x>>a;
                pr[i].first = x;
                pr[i].second = a;
            }
            map<ll,list<pair<ll,ll> > > mp;
            for(ll i=0;i<q;i++){
                if(pr[i].second=='C'){
                    for(ll j=0;j<m;j++){
                        if(mp.count(pr[i].first)){
                            if(mp[pr[i].first].front().second<j){
                                mp[pr[i].first].clear();
                                mp[pr[i].first].push_back(make_pair(i,j));
                                pr[i].first++;
                                pr[i].first = pr[i].first%n;
                                if(pr[i].first==0){
                                    pr[i].first = n;
                                }
                            }
                            else if(mp[pr[i].first].front().second==j){
                                mp[pr[i].first].push_back(make_pair(i,j));
                                pr[i].first++;
                                pr[i].first = pr[i].first%n;
                                if(pr[i].first==0){
                                    pr[i].first = n;
                                }
                            }
                        }
                        else{
                            mp[pr[i].first].push_back(make_pair(i,j));
                            pr[i].first++;
                            pr[i].first = pr[i].first%n;
                            if(pr[i].first==0){
                                pr[i].first = n;
                            }
                        }
                    }
                }
                else{
                    for(ll j=0;j<m;j++){
                        if(mp.count(pr[i].first)){
                            if(mp[pr[i].first].front().second<j){
                                mp[pr[i].first].clear();
                                mp[pr[i].first].push_back(make_pair(i,j));
                                pr[i].first--;
                                pr[i].first = pr[i].first%n;
                                if(pr[i].first==0){
                                    pr[i].first = n;
                                }
                            }
                            else if(mp[pr[i].first].front().second==j){
                                mp[pr[i].first].push_back(make_pair(i,j));
                                pr[i].first--;
                                pr[i].first = pr[i].first%n;
                                if(pr[i].first==0){
                                    pr[i].first = n;
                                }
                            }
                        }
                        else{
                            mp[pr[i].first].push_back(make_pair(i,j));
                            pr[i].first--;
                            pr[i].first = pr[i].first%n;
                            if(pr[i].first==0){
                                pr[i].first = n;
                            }
                        }
                    }
                }
            }
            ll ar[q] = {0};
            for(auto i: mp){
                for(auto j:mp[i.first]){
                    ar[j.first]++;
                }
            }
            for(ll i = 0;i<q;i++){
                cout<<ar[i]<<" ";
            }
        }
        cout<<endl;
        t--;
    }
    return 0;
}
