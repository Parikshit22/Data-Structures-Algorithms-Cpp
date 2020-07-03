#include <iostream>
#include <algorithm>
using namespace std;

class item{
public:
    int weight;
    int price;
    int pw;
    item(){}
    void insertfn(int w,int p){
        weight = w;
        price = p;
        pw = (p/w);
    }

};
bool compare(item a,item b){
    return a.pw>b.pw;
}

int main()
{
    int n;
    cin>>n;
    int cap;
    cin>>cap;
    item a[n];
    for(int i=0;i<n;i++){
        int w;
        int p;
        cin>>w>>p;
        a[i].insertfn(w,p);
    }
    int ans =0;
    sort(a,a+n,compare);
    for(int i=0;i<n;i++){
        if(cap>=a[i].weight){
            ans +=a[i].price;
            cap = cap - a[i].weight;
        }
        else{
            ans += cap * a[i].pw;
            break;
        }

    }
    cout<<ans;
    return 0;
}
