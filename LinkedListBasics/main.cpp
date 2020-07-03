#include <iostream>

using namespace std;
class node{
public:
    int data;
    node* next;
    node(int n){
        data = n;
        next = NULL;
    }
};
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
int length(node *head){
    int len =1;
    while(head->next!=NULL){
        head = head->next;
        len += 1;
    }
    return len;
}
void InsertionInBetween(node *head, int data, int pos){
    node *q = head;
    if(head == NULL||pos == 0){
        InsertionAtHead(q,data);
    }
    else if(pos>length(q)){
        InsertionAtTail(q,data);
    }
    else{
        for(int i=0;i<pos-1;i++){
            q = q->next;
        }
        node*a = new node(data);
        a->next = q->next;
        q->next = a;
    }
}
void DeletionInHead(node *&head){
    node *q = head;
    head = head->next;
    delete q;
}
void DeletionAtTail(node *head){
    node *q = head;
    node *prev = NULL;
    while(q->next!=NULL){
        prev = q;
        q = q->next;
    }
    prev->next = NULL;
    delete q;

}
void DeletionInMiddle(node *head, int pos){
    node *prev = head;
    for(int i=1;i<pos;i++){
        prev = head;
        head = head->next;
    }
    prev->next = head->next;
    delete head;
}

void print(node *head){
    node *q = head;
    for(int i=0;q!=NULL;i++){
        cout<<q->data<<endl;
        q = q->next;
    }
}
void IterrativeSearching(node *head, int num){
    int i =1;
    while(head!=NULL){
        if(head->data==num){
            cout<<"number found at pos "<<i<<endl;
            return;
        }
        head = head->next;
        i++;
    }
    cout<<"Number not found"<<endl;

}
void RecurrsiveSearching(node *head,int num,int i){
    if(head == NULL){
      cout<<"Number not found"<<endl;
    }
    if(head->data == num){
        cout<<"number found at pos "<<i<<endl;
        return;
    }
    RecurrsiveSearching(head->next,num,i+1);
}
void Reverse(node *&head){
    node *q = head;
    node *prev = NULL;
    node *fwd;
    while(q!=NULL){
        fwd = q->next;
        q->next = prev;
        prev = q;
        q = fwd;
    }
    head = prev;
    delete prev;
    delete fwd;
    delete q;
}
node* RecurrsiveReverse(node *q,node *prev,node *fwd){
    if(q->next==NULL){
        q->next = prev;
        return q;
    }
    q->next = prev;
    RecurrsiveReverse(fwd,q,fwd->next);

}
void InputFromUser(node *&head){
    int data;
    cin>>data;
    while(data!=-1){
        InsertionAtTail(head,data);
        cin>>data;
    }
}
int MidPoint(node *head){
    node *Fast = head->next;
    node *Slow = head;
    int i=1;
    while(Fast->next != NULL && Fast != NULL){
        Fast = Fast->next->next;
        Slow = Slow->next;
        i++;
        }
    return i;

}
node *ReturnMidPoint(node *head){
    int mid = MidPoint(head);
    for(int i=1;i<mid;i++){
        head = head->next;
    }
    return head;
}
istream& operator>>(istream &io,node *head){
    int data;
    cin>>data;
    InsertionAtTail(head,data);
    return io;
}
ostream& operator<<(ostream &io, node *head){
    print(head);
    return io;
}
node *Merge(node *head,node *midnode){
    node *q=NULL;
    if(head == NULL){
        return midnode;
    }
    else if(midnode == NULL){
        return head;
    }
    if(head->data<=midnode->data){
        q = head;
        q->next = Merge(head->next,midnode);
    }
    else{
         q = midnode;
         q->next = Merge(head,midnode->next);
    }
    return q;
}
node *MergeSort(node *head){
    if(head == NULL || head->next==NULL){
        return head;
    }
    node *midnode = ReturnMidPoint(head);
    node *a = head;
    node *b = midnode->next;
    midnode->next = NULL;
    a = MergeSort(a);
    b = MergeSort(b);
    node *c = Merge(a,b);
    return c;
}
bool DetectCycle(node *head){
    node *Fast = head;
    node *Slow = head;
    while(Fast!=NULL && Fast->next !=NULL){
        Slow = Slow->next;
        Fast = Fast->next->next;
        if(Fast == Slow){
            return false;
        }
    }
    return true;
}
int main()
{   node *head= NULL;
    InsertionAtHead(head,5);
    InsertionAtHead(head,7);
    InsertionAtTail(head,10);
    InsertionAtHead(head,8);
    InsertionAtHead(head,2);
    InsertionAtTail(head,9);
    InsertionInBetween(head,34,2);
    DeletionInHead(head);
    DeletionAtTail(head);
    DeletionInMiddle(head,2);
    IterrativeSearching(head,10);
    RecurrsiveSearching(head,10,1);
    Reverse(head);
    head = MergeSort(head);
    print(head);
    if(DetectCycle(head)){
        cout<<"Cycle is not there"<<endl;
    }
    else{
        cout<<"cycle is there"<<endl;
    }
    return 0;
}
