#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;
    node(int n){
        data = n;
        left = NULL;
        right = NULL;
    }
};
class llnode{
public:
    int data;
    llnode *next;
    llnode *prev;
    llnode(int n){
        data = n;
        next = NULL;
        prev = NULL;
    }
};
class mypair{
public:
    int height;
    bool balanced;
};
node* BST(node *root,int n){
    if(root == NULL){
        root = new node(n);
        return root;
    }
    if(n<=root->data){
        root->left = BST(root->left,n);
    }
    else{
        root-> right = BST(root->right,n);
    }
    return root;
}
bool searching(node* root,int n){
    if(root==NULL){
        return false;
    }
    if(root->data == n){
        return true;
    }
    if(root->data>=n){
        return searching(root->left,n);
    }
    return searching(root->right,n);

}
int Heightoftree(node *root){
    if(root == NULL){
        return 0;
    }
    int h = max(Heightoftree(root->left),Heightoftree(root->right))+1;
    return h;
}
void printkthlevel(node *root,int k){
    if(root == NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printkthlevel(root->left,k-1);
    printkthlevel(root->right,k-1);
}
void printlevelorder(node *root){
    for(int i=1;i<=Heightoftree(root);i++){
        printkthlevel(root,i);
        cout<<endl;
    }
}
mypair IsBalanced(node*root){
    mypair p;
    if(root==NULL){

        p.height = 0;
        p.balanced = true;
        return p;
    }
    mypair pairl = IsBalanced(root->left);
    mypair pairr = IsBalanced(root->right);
    int diff = abs(pairl.height-pairr.height);
    if((pairl.balanced && pairr.balanced)==true&&diff<=1){
        p.balanced = true;
    }
    p.height = max(pairl.height,pairr.height)+1;
    return p;

}
int nooftrees(int n){
    int p1,p2,p=0;
    if(n==0||n==1){
        return 1;
    }

    for(int i =1;i<=n;i++){
        p1 = nooftrees(n-i);
        p2 = nooftrees(i-1);
        p += p1*p2;
    }
    return p;
}
void Deletionofnode(node *&root,int num){
    if(root == NULL){
        return;
    }
    else if(root->data>num){
        Deletionofnode(root->left,num);
    }
    else if(root->data<num){
        Deletionofnode(root->right,num);
    }
    else {
        if(root->left==NULL&&root->right==NULL){
            root = NULL;
        }
        else if(root->left==NULL&&root->right!=NULL){
            root = root->right;
        }
        else if(root->left!=NULL&&root->right==NULL){
            root = root->left;
        }
        else{
            node *temp = root->right;
            while(temp->left!=NULL){
                temp = temp->left;
            }
            root->data = temp->data;
            Deletionofnode(root->right,temp->data);
        }
    }
    return;

}
bool IsBST(node *root,int minval = INT_MIN,int maxval = INT_MAX){
    if(root==NULL){
        return true;
    }
    if( minval<=root->data<=maxval&&IsBST(root->left,minval,root->data)&&IsBST(root->right,root->data,maxval)){
        return true;
    }
    return false;
}
llnode *builtsortedlinklist(node *&root){

    if(root == NULL){
        return NULL;
    }
    llnode *temp = new llnode(root->data);
    if(root->left==NULL&&root->right==NULL){
        temp->next = NULL;
        temp->prev = NULL;
        return temp;
    }
    llnode *l = builtsortedlinklist(root->left);
    l->next = temp;
    temp->prev=l;
    llnode *r = builtsortedlinklist(root->right);
    temp->next = r;
    r->prev=temp;
    return temp;
}

int main()
{
    node *root = NULL;
    int n;
    cin>>n;
    while(n!= -1){
        root = BST(root,n);
        cin>>n;
    }
    /*
    if(searching(root,12)){
        cout<<"element is present"<<endl;
    }
    else{
        cout<<"element is not present"<<endl;
    }
    printlevelorder(root);
    cout<<Heightoftree(root);
    mypair p = IsBalanced(root);
    cout<<p.height<<endl;
    if(p.balanced){
        cout<<"is balanced tree"<<endl;
    }
    else{
        cout<<"is not balanced"<<endl;
    }
    int n;
    cin>>n;
    int p = nooftrees(n);
    cout<<p;
    printlevelorder(root);
    Deletionofnode(root,8);
    printlevelorder(root);
    if(IsBST(root)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    */
    llnode * temp = builtsortedlinklist(root);
    while(temp->prev!=NULL){
        temp = temp->prev;
    }
    cout<<temp->data;
    while(temp->next!=NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }

    return 0;

}
