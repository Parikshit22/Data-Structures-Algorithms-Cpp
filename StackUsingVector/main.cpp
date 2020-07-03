#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Stack{
public:
    vector <T> v;
    void Push(T data){
        v.push_back(data);
    }
    void Pop(){
        v.pop_back();
    }
    T Top(){
        return v[v.size()-1];
    }
    bool empty(){
        if(v.size()==0){
            return true;
        }
    }

};
void Print(Stack <int> v){
        while(!v.empty()){
            cout<<v.Top()<<" ";
            v.Pop();
        }
    }

int main()
{   Stack <int> s;
    s.Push(10);
    s.Push(11);
    s.Push(45);
    Print(s);
    return 0;
}
