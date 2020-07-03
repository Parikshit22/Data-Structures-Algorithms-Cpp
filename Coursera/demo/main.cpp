#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *left;
    node *right;
    node(int n){
        data = n;
        left = NULL;
        right = NULL;
    }
};
node *bst(node *root,int n){
    if(root==NULL){
        root = new node(n);
        return root;
    }
    if(root->data>=n){
        root->left = bst(root->left,n);
    }
    else{
        root->right = bst(root->right,n);
    }
    return root;
}
node *tree(int *pre,int *in,int ps,int pe,int is,int ie){
    if(ps>pe){
        return NULL;
    }
    int iri;
    int pri = ps;
    int val = pre[ps];
    for(int i=is;i<ie;i++){
        if(i==val){
            iri = i;
            break;
        }
    }
    int pls = pri+1;
    int ils = is;
    int ile = iri-1;
    int irs = iri+1;
    int ire = ie;
    int ple = ile-ils+pls;
    int prs = ple+1;
    int pre = pe;


}
int main(){
    node *root = NULL;
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        root = bst(root,x);
    }
    int pre[] = {1,2,4,5,3,68,9,7};
    int in[] = {4,2,5,1,8,6,9,3,7};

return 0;
}
