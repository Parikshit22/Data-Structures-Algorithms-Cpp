#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;
template<typename T>
class node{
public:
    string key;
    T value;
    node<T> *next;

    node(string key,T value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~node(){
        if(next!=NULL){
            delete next;
           }
    }
};
bool isprime(int v){
    if(v==2){
        return true;
    }
    for(int i=2;i<v;i++){
        if(v%i==0){
            return false;
        }
    }
    return true;
}
template<typename T>
class hashtable{
public:
    int cs;
    int ts;
    node<T>** buckets;
    hashtable(int ts = 7){
        this->ts = ts;
        cs = 0;
        buckets = new node<T>*[ts];
        for(int i=0;i<ts;i++){
            buckets[i] = NULL;
        }
    }
    int hashfn(string s){
        int sum =0;
            int L = s.length();
            for(int i=0;i<L;i++){
                sum += ((s[L-i-1])*(pow(23,i)));
            }

            return (sum%ts);
    }
    void insert(string s,T value){
            int sum = hashfn(s);
            node<T> * temp = new node<T>(s,value);
            temp->next = buckets[sum];
            buckets[sum] = temp;
            cs++;
            int oldts = ts;
            float loadfactor = (float)cs/ts;
            if(loadfactor>0.7){
                ts = 2*ts;
                while(!isprime(ts)){
                    ts = ts+1;
                }
                node<T> **oldbuckets = new node<T>*[oldts];
                oldbuckets = buckets;
                buckets = new node<T>*[ts];
                for(int i=0;i<ts;i++){
                    buckets[i] = NULL;
                }
                for(int i=0;i<oldts;i++){
                    node<T> *temp = oldbuckets[i];
                    if(temp!=NULL){
                        while(temp!=NULL){
                            insert(temp->key,temp->value);
                            temp = temp->next;
                        }
                        delete oldbuckets[i];
                    }
                }
                delete [] oldbuckets;
            }
    }
    void print(){
        for(int i=0;i<ts;i++){
            node<T> *temp = buckets[i];
            cout<<"Elemenet in "<<i<<" bucket is -> ";
            while(temp!=NULL){
                cout<<temp->key<<","<<temp->value<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
    T* search(string k){
        int index = hashfn(k);
        node<T> *temp = buckets[index];
        while(temp!=NULL){
            if(temp->key==k){
                return(&(temp->value));

            }
            temp = temp->next;
        }
        return NULL;

    }
    T& operator[](string key){
        T* temp = search(key);
        if(temp==NULL){
            T garbage;
            insert(key,garbage);
            T* value = search(key);
            return *value;
        }
        return *temp;
    }
};

int main()
{
    hashtable<int> t(7);
    t.insert("mango",120);
    t.insert("apple",100);
    t.insert("banana",10);
    t.insert("chiku",110);
    t.insert("grapes",170);
    t.insert("papaya",10);
    t.insert("orange",110);
    t.insert("guvava",170);
    t.insert("pomogrante",10);
    t.insert("pear",110);


    string s = "orange";
    t["orange"] = 40;
    int*temp = t.search(s);
    cout<<*temp<<endl;
    t["figs"] = 210;
    t.print();

    return 0;
}
