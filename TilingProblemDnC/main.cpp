#include <iostream>
#include <string>
using namespace std;

int TilingProblem(int n){
if(n<=0){
    return 0;
}
if(n==4){
    n=0;
    return 2;
}
    int ans = TilingProblem(n-1)+TilingProblem(n-4);
    return ans;
}

int main()
{   int n;
    cin>>n;
    cout<<TilingProblem(n);
    return 0;
}
