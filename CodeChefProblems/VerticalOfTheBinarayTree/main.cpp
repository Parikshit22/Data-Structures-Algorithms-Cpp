#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* left;
    node *right;
    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
node * builttree(){
    int n;
    cin>>n;
    if(n==-1){
        return NULL;
    }
    node *root = new node(n);
    root->left = builttree();
    root->right = builttree();
    return root;
}
map<int,list<int> > h;
void traverse(node *root,int level){
    if(root==NULL){
        return;
    }
    h[level].push_back(root->data);
    traverse(root->left,level-1);
    traverse(root->right,level+1);
}
void printmap(){
    for(auto i =h.begin();i!= h.end();i++){
            cout<<i->first<<"->";
            for(auto j : h[i->first]){
                cout<<j<<",";
            }
            cout<<endl;
        }
}
int main()
{   node *root = builttree();
    traverse(root,0);
    printmap();
    return 0;
}
