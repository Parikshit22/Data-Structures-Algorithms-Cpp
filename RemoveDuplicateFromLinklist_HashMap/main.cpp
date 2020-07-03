#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class node{
public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};
bool CyclePresent(node *head){
    node *p = head;
    unordered_map<node *,bool> h;
    while(p!=NULL){
        if(h[p]==true){
            return true;
        }
        h[p] = true;
        p= p->next;

    }
    return false;
}

int main()
{
    node *head = new node(5);
    node *p = head;
    for(int i=0;i<5;i++){
        int num;
        cin>>num;
        node* temp = new node(num);
        p->next = temp;
        p = temp;
    }
    p->next = head->next;
    if(CyclePresent(head)){
        cout<<"Yes,Cycle is present"<<endl;
    }
    else{
        cout<<"NO,cycle is not present"<<endl;
    }
    return 0;
}
