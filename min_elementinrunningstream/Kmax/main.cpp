#include <iostream>
#include <queue>
using namespace std;
priority_queue<int ,vector<int>,greater<int> >pq;

int main()
{
    int k;
    cin>>k;
    int data;
    cin>>data;
    int i=0;
    while(data != -1&&i<k){
        pq.push(data);
        cin>>data;
        i++;
    }
    while(data!=-1){
        if(pq.top()<data){

            pq.push(data);
            pq.pop();
        }
        cin>>data;
    }
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
    return 0;
}
