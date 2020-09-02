#include <iostream>
#include <list>
using namespace std;

template<class ForwardIterator,class T>

ForwardIterator search(ForwardIterator start,ForwardIterator end,T num){
    while(start!=end){
        if(*(start)==num){
            return start;
        }
        start++;
    }
    return end;
}


int main()
{
    list<int> l;
    l.push_back(23);
    l.push_back(2);
    l.push_back(3);
    l.push_back(5);
    l.push_back(44);
    l.push_back(34);

    auto a = search(l.begin(),l.end(), 5);
    if(a!=l.end()){
        cout<<*(a)<<" element found";
    }
    else{
        cout<<"element not found"<<endl;
    }

    return 0;
}
