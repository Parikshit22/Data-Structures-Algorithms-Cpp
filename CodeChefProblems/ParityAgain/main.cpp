#include <iostream>
#include <vector>
using namespace std;
bool count(int x){
    int ans=0;
    while(x>0){
        ans += x&1;
        x = x>>1;
    }
    if(ans%2==0){
        return true;
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t>0){
        int q;
        cin>>q;
        vector<int> a;
        int e=0;
        int o=0;
        while(q>0){
            int x;
            cin>>x;
            if(a.empty()){
                a.push_back(x);
                bool even = count(x);
                if(even){
                    e++;
                }
                else{
                    o++;
                }
            }
            else{
                a.push_back(x);
                bool even = count(x);
                if(even){
                    e++;
                }
                else{
                    o++;
                }
                int s = a.size();
                for(int i=0;i<s-1;i++){
                    int p = (a[i]^x);
                    a.push_back(p);
                    bool even1 = count(p);
                    if(even1){
                        e++;
                    }
                    else{
                        o++;
                    }
                }
            }
            cout<<e<<" "<<o<<endl;
            q--;
        }
        t--;
    }
    return 0;
}
