#include <iostream>
#include <stack>
using namespace std;
void InsertAtBottom(stack<int>&s,int data){
    if(s.empty()){
        s.push(data);
        return;
    }
    int a = s.top();
    s.pop();
    InsertAtBottom(s,data);
    s.push(a);
}
void ReverseOfStack(stack<int>&s){
    if(s.empty()){
    return;
    }
    int c = s.top();
    s.pop();
    ReverseOfStack(s);
    InsertAtBottom(s,c);

}
void print(stack <int> a){
    while(!a.empty()){
        cout<<a.top()<<" ";
        a.pop();
    }
}
int main()
{
    stack <int> s;
    for(int i=0;i<5;i++){
        s.push(i);
    }
    print(s);
    cout<<endl;
    ReverseOfStack(s);
    print(s);


    return 0;
}
