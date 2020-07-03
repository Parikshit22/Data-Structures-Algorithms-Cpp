#include <iostream>
#include <queue>
using namespace std;
void reverseofqueue(queue<int>&q){
    if(q.empty()){
        return;
    }
    int x = q.front();
    q.pop();
    reverseofqueue(q);
    q.push(x);
}
void print(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}
int main()
{
    queue <int> q;
    q.push(4);
    q.push(7);
    q.push(5);
    q.push(6);
    q.push(2);
    print(q);
    cout<<endl;
    reverseofqueue(q);
    print(q);
    return 0;
}
