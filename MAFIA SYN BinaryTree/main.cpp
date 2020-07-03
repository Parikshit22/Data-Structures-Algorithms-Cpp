#include <iostream>
#include <queue>
using namespace std;
class node{
public:
    int name;
    int cap;
    int data;
    node *left;
    node *right;
    node(int n,int c,int name){
        name = name;
        cap = c;
        data = n;
        left == NULL;
        right == NULL;
    }
    node(int n,int name){
        name = name;
        data = n;
        left == NULL;
        right == NULL;
    }

};
void Formation(node *&root,queue<int> s,int i,int *have,int *cap){
    if(root==NULL){
        return;
    }
    if(root->name!=s.front()){
        Formation(root->left,s,i,have,cap);
        Formation(root->right,s,i,have,cap);
    }
    else{
        if(root->left==NULL){
            node *p = new node(have[i],cap[i],i);
            root->left = p;
            return;
        }
        else{
           node *p = new node(have[i],cap[i],i);
            root->right = p;
            return;
        }
    }

}
void sumofnodesanddata(node *&root){
    if(root == NULL){
        return   ;
    }
    else if(root->left == NULL&&root->right == NULL){

        root->data=0;
        return;
    }
    else if(root->left != NULL&&root->right == NULL){
        root->data = root->left->data;
        root->left->data=0;
        sumofnodesanddata(root->left);
    }
    else if(root->left == NULL&&root->right != NULL){
        root->data = root->right->data;
        root->right->data=0;
        sumofnodesanddata(root->right);
    }
    else{
        root->data = root->right->data+root->left->data;
        root->right->data=root->left->data=0;
        sumofnodesanddata(root->left);
        sumofnodesanddata(root->right);
    }
}

void furthersumofnodesanddata(node *&root){
    if(root == NULL){
        return   ;
    }
    else if(root->left == NULL&&root->right == NULL){

        root->data=0;
        return;
    }
    else if(root->left != NULL&&root->right == NULL){
        if(root->left->data<=root->left->cap){
            root->data = root->left->data;
            root->left->data=0;
            furthersumofnodesanddata(root->left);
        }
    }
    else if(root->left == NULL&&root->right != NULL){
        if(root->right->data<=root->right->cap){
            root->data = root->right->data;
            root->right->data=0;
            furthersumofnodesanddata(root->right);
        }
    }
    else{

        if(root->right->data>root->right->cap){
            root->data = root->left->data;
            root->left->data=0;
            sumofnodesanddata(root->left);

        }
        else if(root->left->data>root->left->cap){
            root->data = root->right->data;
            root->right->data=0;
            sumofnodesanddata(root->right);

        }
        else{
            root->data = root->right->data+root->left->data;
            root->right->data=root->left->data=0;
            sumofnodesanddata(root->left);
            sumofnodesanddata(root->right);
        }
    }
}


int main()
{   int n;
    cin>>n;
    int have[n+1],cap[n+1];
    have[1] = 0;
    for(int i=2;i<=n;i++){
        cin>>have[i]>>cap[i];
    }
    queue<int>s;
    for(int i=0;i<n-1;i++){
        int temp;
        cin>>temp;
        s.push(temp);
    }
    node *root = new node(have[1],1);
    int i=2;
    while(!s.empty()){
        Formation(root,s,i,have,cap);
        i++;
        s.pop();
    }
    sumofnodesanddata(root);
    furthersumofnodesanddata(root);
    cout<<root->data;


    return 0;
}
