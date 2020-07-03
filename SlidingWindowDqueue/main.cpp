#include <iostream>
#include <deque>
using namespace std;

int main()
{   int n;
    cin>>n;
    int a[n];
    for(int j=0;j<n;j++){
        cin>>a[j];
    }
    int k;
    cin>>k;
    deque<int>s(k);
    int i;
    for(i=0;i<k;i++){
        while(!s.empty()&&s.back()<=a[i]){
            s.pop_back();
        }
        s.push_back(i);
    }
    cout<<a[s.front()]<<" ";
    for(;i<n;i++){
        while(!s.empty()&&s.front()<=i-k){
            s.pop_front();
        }
        while(!s.empty()&&a[i]>=a[s.back()]){
            s.pop_back();
        }
        s.push_back(i);
        cout<<a[s.front()]<<" ";
    }
    return 0;
}
