#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Stack{
public:
    queue<int> q1;
    queue<int> q2;
    Stack(){}
    void push(int x){
        q1.push(x);
    }
    void Pop(){
        if(q1.empty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
        int n = q1.size();
        for(int i=0;i<n-1;i++){
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }
        q1.pop();
        swap(q1,q2);
    }
    int top(){
        if(q1.empty()){
            return -1;
        }
        int n = q1.size();
        for(int i=0;i<n-1;i++){
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }
        int y = q1.front();
        q1.pop();
        q2.push(y);
        swap(q1,q2);
        return y;
    }
};

int main()
{   Stack s;
    s.push(100);
    s.push(30);
    s.Pop();
    s.Pop();
    s.Pop();
    cout<<s.top();

    return 0;
}
