#include <iostream>

using namespace std;
int ladder(int k,int n){
    int res[n];
    res[2] = 0;
    res[0] = 1;
    res[1] = 1;
    for(int i=2;i<n;i++){
        res[i] = 0;
        for(int j=1;j<=k&&j<=i;j++){
            res[i] += res[i-j];
        }
    }
    return res[n-1];
}


int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    cout<<ladder(k,n+1);
    return 0;
}
