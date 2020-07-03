#include <iostream>
#include <deque>
using namespace std;
char IsPresent(char *a,int i){
    int j=0;
    while(i>j){
        if(a[i]==a[j]){
            return j+1;
        }
        j++;
    }
    return 0;
}
int main()
{   int n,k;
    cin>>n;
    char a[n];
    for(int l=0;l<n;l++){
        cin>>a[l];
    }
    deque <char>s(n);
    int maxm=0;
    int curr=0;
    for(int i=0;i<n;i++){
        if(!s.empty()&&IsPresent(a,i)!=0){
            k = IsPresent(a,i);
            for(int p=0;p<k;p++){
                s.pop_front();
            }
            curr = curr - k;
        }
        s.push_back(a[i]);
        curr++;
        maxm = max(maxm,curr);
    }
    cout<<maxm;
    return 0;
}
