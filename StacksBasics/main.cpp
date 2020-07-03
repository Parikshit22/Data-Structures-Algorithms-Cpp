#include <iostream>

using namespace std;
class node{
public:
    int data;
    node *next;
    node(int n){
        data = n;
        next = NULL;
    }
};
class Stack{
public:
    node *head=NULL;

    void Push(int data){
        node *a = new node(data);
        a->next = head;
        head = a;
    }
    void Pop(){
        if(head->next == NULL || head == NULL){
            cout<<"Stack is empty"<<endl;
        }
        node *a = head;
        head = head->next;
        delete a;
    }
    int top(){
        return head->data;
    }
    bool empty(){
       if(head->next == NULL || head == NULL){
            return true;
        }
        return false;
    }
    int size(){
        int i =1;
        while(head->next!=NULL){
            head = head->next;
            i++;
        }
        return i;
    }
};

int main()
{
    Stack a;
    a.Push(5);
    a.Push(6);
    cout<<a.size();
    return 0;
}
