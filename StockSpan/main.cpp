#include <iostream>
#include <stack>
using namespace std;
void Stock(int *arr, int n){
    stack<int> s;
    int ans[n];
    for(int i=0;i<n;i++){
        int currprice = arr[i];
        while(s.empty()==false&&arr[s.top()]<currprice){
            s.pop();
        }
        int betterday = s.empty()?0:s.top();
        ans[i] = i-betterday;
        s.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}

int main()
{
    int n =7;
    int arr[n] = {100,80,60,70,60,75,85};
    Stock(arr,n);
    return 0;
}
