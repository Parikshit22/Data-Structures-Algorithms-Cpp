#include <iostream>
#include <queue>
#include <functional>
using namespace std;
class Fruit{
public:
    int price;
    string name;
    Fruit(int p,string n){
        price = p;
        name = n;
    }
};
class mycompare{
public:
    bool operator()(Fruit a ,Fruit b){
        return a.price>b.price;

    }
};


int main()
{   /*
    priority_queue<int> pq;
    priority_queue<int,vector<int>,mycompare >minpq;
    for(int i=0;i<8;i++){
        pq.push(i*i);
    }
    cout<<"Max_heap"<<endl;
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    for(int i=0;i<8;i++){
         minpq.push(i*i);
    }
    cout<<"Min_heap"<<endl;
    while(!minpq.empty()){
        cout<<minpq.top()<<" ";
        minpq.pop();
    }
    cout<<endl;
    */

    priority_queue<Fruit,vector<Fruit>,mycompare> pq;
    for(int i=0;i<5;i++){
        int j;
        string s;
        cin>>j;
        cin>>s;
        Fruit f(j,s);
        pq.push(f);
    }
    while(!pq.empty()){
        cout<<pq.top().price<<" "<<pq.top().name<<endl;
        pq.pop();
    }
    return 0;
}
