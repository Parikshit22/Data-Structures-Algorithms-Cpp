#include <iostream>

using namespace std;
class Queue{
public:
    int cs;
    int ms;
    int *arr;
    int Front;
    int Back;
    Queue(int ds = 5){
        ms = ds;
        arr = new int[ds];
        cs = 0;
        Front =0;
        Back = ms -1;
    }
    void push(int data){
        if(!IsFull()){
            Back = (Back+1)%ms;
            arr[Back] = data;
            cs++;
        }
    }
    void pop(){
        if(!IsEmpty()){
            Front = (Front+1)%ms;
            cs--;
        }
    }
    int Top(){
        if(!IsEmpty()){
            return arr[Front];
        }
    }
    bool IsFull(){
        return (cs==ms);
    }
    bool IsEmpty(){
        return cs==0;
    }
    void Reverse(){
        int a;
        int f = Front;
        int b = Back;
        int i;
        if(ms%2!=0){
            i = (ms/2)+1;
        }
        else{
            i = ms/2;
        }
        while(i>0){
            swap(arr[f],arr[b]);
            f = (f+1)%ms;
            b = (b-1);
            if(b<0){
                b = ms-1;
            }
            i--;
        }
    }
};
void print(Queue a){
    while(!a.IsEmpty()){
        cout<<a.Top()<<" ";
        a.pop();
    }
    cout<<endl;
}

int main()
{   Queue a(6);
    for(int i=1;i<10;i++){
        a.push(i);
    }
    cout<<a.Top()<<endl;
    a.push(9);
    a.push(8);
    print(a);
    a.Reverse();
    print(a);
    return 0;
}
