#include <iostream>

using namespace std;
class Queue{
private:
    class node{
    public:
        int data;
        node *next;
        node(int n){
            data = n;
            next = NULL;
        }
    };
public:
    node *head = NULL;
    node *tail = NULL;
    void Insert(int data){
        node *a = new node(data);
        if(head == NULL){
            head = a;
            tail = a;
        }
        else{
            tail->next = a;
            tail = a;
        }
    }
    void Remove(){
        node *q = head;
        head = head->next;
        delete q;
    }
    int Front(){
        return head->data;
    }
    bool empty(){
        if(head==NULL){
            return true;
        }
        return false;
    }
};

int main()
{
    Queue a;
    a.Insert(10);
    a.Insert(6);
    a.Insert(5);
    a.Remove();
    a.Remove();
    if(a.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
    return 0;
}
