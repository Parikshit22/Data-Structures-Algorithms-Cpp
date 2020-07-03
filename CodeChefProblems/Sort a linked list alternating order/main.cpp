#include <bits/stdc++.h>

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
node *BuildLL(int n){
    int num;
    cin>>num;
    node *head = new node(num);
    node *root = head;
    for(int i=1;i<n;i++){
        int num;
        cin>>num;
        node *ptr = new node(num);
        head->next = ptr;
        head = ptr;
    }
    head->next = NULL;
    return root;
}
void printll(node *root){
    node *ptr = root;
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}
node *sortll(node *head){
    node *h1 = head;
    node *h2 = head->next;
    node *ptr = head->next;
    while(head!=NULL){
        if(head->next!=NULL){
            node *temp = ptr->next;
            if(temp!=NULL){
                head->next = temp;
                head = temp;
            }
            else{
                head->next = NULL;
                break;
            }
            if(ptr->next->next!=NULL&&temp!=NULL){
                ptr->next = ptr->next->next;
                ptr = ptr->next;
            }
            else{
                ptr->next = NULL;
            }

        }
        else{
            head = head->next;
        }
    }
    node* current = h2;
    node *prev = NULL, *next = NULL;

    while (current != NULL) {
        // Store next
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    h2 = prev;
    node *temp = new node(0);
    node *start = temp;
    while(1){
        if(h1==NULL){
            temp->next = h2;
            break;
        }
        else if(h2==NULL){
            temp->next = h1;
            break;
        }
        if(h1->data>=h2->data){
            temp->next = new node(h2->data);
            temp = temp->next;
            h2 = h2->next;
        }
        else{
            temp->next = new node(h1->data);
            temp = temp->next;
            h1 = h1->next;
        }

    }
    return (start->next);
}

int main(){
    int n;
    cin>>n;
    node *root = BuildLL(n);
    node *temp = sortll(root);
    printll(temp);
    return 0;
}
