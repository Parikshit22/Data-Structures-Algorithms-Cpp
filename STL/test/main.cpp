#include <bits/stdc++.h>

using namespace std;


class node{
public:
    int data;
    node *next;
    node(int num){
        data = num;
        next = NULL;
    }
};
//
//class listt{
//public:
//    node *head;
//    listt(){
//        head = NULL;
//    }
//
//    void insertion(int num){
//        node *ptr = head;
//        while(ptr->next!=NULL){
//            ptr = ptr->next;
//        }
//        node *temp = new node(num);
//        cout<<temp->data<<endl;
//        ptr->next = temp;
//    }
//
//    void print(){
//        node *ptr = head;
//        while(ptr!=NULL){
//            cout<<ptr->data<<" ";
//            ptr = ptr->next;
//        }
//    }
//};

void InsertionAtTail(node *head,int data){
    node *q = head;
    while(q->next!=NULL){
        q = q->next;
    }
    node*a = new node(data);
    q->next=a;
}
void InsertionAtHead(node*&head,int data){
    node*a = new node(data);
    a->next = head;
    head = a;
}
void nodeprint(node *head){
    node *ptr = head;
    while(ptr!=NULL&&ptr->next!=NULL){
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    }
}

int main(){
    node *head= NULL;
    InsertionAtTail(head,7);
    InsertionAtTail(head,10);
    nodeprint(head);



//    listt ll;
//    ll.insertion(3);
//    ll.insertion(32);
//    ll.insertion(5);
//    ll.print();

}
