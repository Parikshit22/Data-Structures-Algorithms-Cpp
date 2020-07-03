#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define hashmap unordered_map<char,node *>
class node{
public:
    char a;
    hashmap h;
    bool IsTerminal;
    node(char data){
        data = a;
        IsTerminal = false;
    }
};
class Trie{
public:
    node* root;
    Trie(){
        root = new node('\0');
    }
    void insertion(char *word){
        node *temp = root;
        for(int i=0;word[i]!='\0';i++){
            char ch = word[i];
            if(temp->h.count(ch)==0){
                node *child = new node(ch);
                temp->h[ch] = child;
                temp = child;
            }
            else{
                temp = temp->h[ch];
            }
        }
        temp->IsTerminal = true;
    }
    bool IsPresent(char *word){
        node *temp = root;
        for(int i=0;word[i]!='\0';i++){
            char ch = word[i];
            if(temp->h[ch]==0){
                return false;
            }
            temp = temp->h[ch];
        }
        if(temp->IsTerminal==false){
            return false;
        }
        return true;
    }
};

int main()
{
    Trie t;
    t.insertion("jaipur");
    t.insertion("Mumbai");
    t.insertion("jabalpur");
    t.insertion("Assam");
    t.insertion("bangalore");
    if(t.IsPresent("jaipur")){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
