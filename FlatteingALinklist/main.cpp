#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *Down;
    node *Right;
    node(int data){
    this->data = data;
    Down = NULL;
    Right = NULL;
    }
};
void MergeSort(list<list<int> > m,int n){

}

int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    node *Node = new node(k);
    node *head = Node;
    int num;
    cin>>num;
    for(int i=0;i<n;i++){
        node *No = Node;
        while(num!=-1){
            node *N = new node(num);
            Node->Down = N;
            Node = N;
            cin>>num;
        }
        cin>>num;
        node *N = new node(num);
        No->Right = N;
        Node = N;
        cin>>num;
    }

    return 0;
}
