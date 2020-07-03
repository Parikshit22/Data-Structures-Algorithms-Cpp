#include <iostream>
#include <vector>

using namespace std;
class Heap{
public:
    vector <int> v;
    bool minheap;
    bool compare(int a,int b){
        if(minheap){
            return a<b;
        }
        else{
            return a>b;
        }
    }

    Heap(bool type = true){
        minheap = type;
        v.push_back(-1);
    }
    void push(int data){
        v.push_back(data);
        int index = v.size()-1;
        int parent = index/2;

        while(index>1&&compare(v[index],v[parent])){
            swap(v[index],v[parent]);
            index = parent;
            parent = parent/2;
        }
    }
    int top(){
        return v[1];
    }
    bool isempty(){
        if(v.size() == 1){
            return true;
        }
        return false;
    }
    void heapify(int i){
        int minindex = i;
        int left = 2*i;
        int right = 2*i+1;
        if(left<v.size()&&compare(v[left],v[minindex])){
            minindex = left;
        }
        if(right<v.size()&&compare(v[right],v[minindex])){
            minindex = right;
        }
        if(minindex!=i){
            swap(v[minindex],v[i]);
            heapify(minindex);
        }
    }
    void pop(){
        swap(v[1],v[v.size()-1]);
        v.pop_back();
        heapify(1);
    }
};


int main()
{
    Heap h(false);
    h.push(10);
    h.push(23);
    h.push(1);
    h.push(34);
    h.pop();
    cout<<h.top()<<endl;
    return 0;
}
