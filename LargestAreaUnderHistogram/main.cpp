#include <iostream>
#include <stack>

using namespace std;

int main()
{   int a[]={6,2,5,4,5,1,6};
    int n = sizeof(a)/sizeof(a[0]);
    stack<int>s;
    int curr=0;
    int maxm=0;
    int top;
    int i=0;
    while(i<n){
        if(s.empty()||a[i]>=a[s.top()]){
            s.push(i++);
        }
        else {

                top = a[s.top()];
                s.pop();
                curr = top*(s.empty()?(i):(i-s.top()-1));
                maxm = max(maxm,curr);
        } }

            while(s.empty()==false){
                top = s.top();
                s.pop();
                curr = a[top]*(s.empty()?(i):(i-s.top()-1));
                maxm = max(maxm,curr);
            }


        cout<<maxm;
    return 0;
}
