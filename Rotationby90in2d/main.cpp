#include <iostream>

using namespace std;

int main()
{
    int a[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int n=4;
    for(int j=0;j<n;j++){
        for(int i=j;i<n;i++){
            swap(a[j][i],a[i][j]);
        }
    }
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n;j++){
            swap(a[i][j],a[n-i-1][j]);
        }
    }

     for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            cout<<a[i][k];
        }cout<<endl;}
    return 0;
}
