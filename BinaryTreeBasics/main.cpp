#include <iostream>
#include <queue>
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
node *buildtree(){
    int n;
    cin>>n;
    if(n==-1){
        return NULL;
    }
    node *root = new node(n);
    root->left = buildtree();
    root->right = buildtree();
    return root;
}
node* builttreeiterratively(){
    int temp;
    cin>>temp;
    node *root = new node(temp);
    queue <node *> s;
    int tempL,tempR;
    s.push(root);
    while(!s.empty()){

        cin>>tempL>>tempR;
        node * parent = s.front();
        s.pop();
        if(tempL != -1){
            parent->left = new node(tempL);
            s.push(parent->left);
        }
        if(tempR != -1){
            parent->right = new node(tempR);
            s.push(parent->right);
        }
    }
    return root;
}
void printpreorder(node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}
void printinorder(node *root){
    if(root == NULL){
        return;
    }
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);
}
void printpostorder(node *root){
    if(root == NULL){
    return;}
    printpostorder(root->left);
    printpostorder(root->right);
    cout<<root->data<<" ";
}
int HeightOfTree(node *root){
    if(root == NULL){
        return 0;
    }
    int height = max(HeightOfTree(root->left),HeightOfTree(root->right))+1;
    return height;

}
void PrintKthRow(node *root,int k){
    if(root == NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    PrintKthRow(root->left,k-1);
    PrintKthRow(root->right,k-1);

}
void printlevelorder(node *root){
    for(int i=1;i<=HeightOfTree(root);i++){
        PrintKthRow(root,i);
        cout<<endl;
    }
}
void levelorderusingqueue(node *root){
    queue<node* >s;

    s.push(root);
    s.push(NULL);
    while(!s.empty()){
        node * f = s.front();
        if(s.front()==NULL){
            cout<<endl;
            s.pop();
            if(!s.empty()){
                s.push(NULL);
            }
        }
        else{
            cout<<f->data<<" ";
            s.pop();
            if(f->left!=NULL){
                s.push(f->left);
            }
            if(f->right!=NULL){
                s.push(f->right);
            }
        }

    }
}
int noofnodes(node *root){
    if(root == NULL){
        return 0;
    }
    int n = (noofnodes(root->left))+(noofnodes(root->right))+1;
    return n;
}
int diameteroftree(node *root){
    if(root == NULL){
        return 0;
    }
    int d = HeightOfTree(root->left)+HeightOfTree(root->right);
    int maxm = max(d,max(diameteroftree(root->left),diameteroftree(root->right)));
    return maxm;
}
pair<int ,int > diameteroftreeoptimised(node *root){
    if(root == NULL){
        pair<int ,int>mypair(0,0);
        return mypair;
    }
    int d = max(diameteroftreeoptimised(root->left).second + diameteroftreeoptimised(root->right).second,max(diameteroftreeoptimised(root->left).first,diameteroftreeoptimised(root->right).first));
    int h = max(diameteroftreeoptimised(root->left).second,diameteroftreeoptimised(root->right).second)+1;
    pair<int ,int>mypair(d,h);
    return mypair;

}
int sumofnodesanddata(node *&root){
    if(root == NULL){
        return 0  ;
    }
    if(root->left == NULL&&root->right == NULL){
        return root->data;
    }
    int left =sumofnodesanddata(root->left);
    int right =sumofnodesanddata(root->right);
    int temp = root->data;
    root->data = left+right;
    return root->data+temp;
}
class mypair{
public:
    int inc;
    int exc;
};
mypair Maxsumproblem(node * root){
    mypair a ;
    if(root==NULL){
        a.inc =0;
        a.exc =0;
        return a;
    }
    a.inc = root->data+Maxsumproblem(root->left).exc+Maxsumproblem(root->right).exc;
    a.exc = max(Maxsumproblem(root->left).exc,Maxsumproblem(root->left).inc)+ max(Maxsumproblem(root->right).exc,Maxsumproblem(root->right).inc);
    return a;

}
void Imageoftree(node *&root){
    if(root==NULL){
        return;
    }
    swap(root->left,root->right);
    Imageoftree(root->left);
    Imageoftree(root->right);
}
node * Balancedtreeusingarr(int *arr,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    node *p = new node(arr[mid]);
    p->left = Balancedtreeusingarr(arr,s,mid-1);
    p->right = Balancedtreeusingarr(arr,mid+1,e);
    return p;
}
int i=0;
node *Treeformationusingpreandin(int *ino,int *pre,int s,int e){
    if(s>e){
        return NULL;
    }
    int index;
    for(int j=s;j<=e;j++){
        if(ino[j]==pre[i]){
            index = j;
            break;
        }
    }
    node *root = new node(pre[i]);
    i++;
    root->left=Treeformationusingpreandin(ino,pre,s,index-1);
    root->right=Treeformationusingpreandin(ino,pre,index+1,e);
    return root;
}

int main()
{

    /*
    node *root = buildtree();
    printpreorder(root);
    cout<<endl;
    printinorder(root);
    cout<<endl;
    printpostorder(root);
    cout<<endl;
    cout<<HeightOfTree(root)<<endl;
    printlevelorder(root);
    cout<<noofnodes(root);
    cout<<diameteroftree(root);
    sumofnodesanddata(root);
    printlevelorder(root);
    levelorderusingqueue(root);
    node * roottemp = builttreeiterratively();
    printpreorder(roottemp);
    pair<int , int> p = diameteroftreeoptimised(root);
    cout<<p.first;
    mypair p = Maxsumproblem(root);
    cout<<max(p.exc,p.inc);
    printlevelorder(root);
    cout<<endl;
    Imageoftree(root);
    printlevelorder(root);
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    node *root = Balancedtreeusingarr(arr,0,n-1);
    printlevelorder(root);
    */
    int pre[] = {1,2,3,4,8,5,6,7};
    int ino[] = {3,2,8,4,1,6,7,5};
    int n = sizeof(ino)/sizeof(ino[0]);
    node *root = Treeformationusingpreandin(ino,pre,0,n-1);
    printlevelorder(root);




    return 0;
}
