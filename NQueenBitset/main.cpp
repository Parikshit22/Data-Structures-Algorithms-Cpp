#include <iostream>
#include <bitset>
using namespace std;
bitset <30> row,r1,r2;
void NQueen(int r,int n, int &ans){
    if(r==n){
        ans++;
        return;
}
    for(int i=0;i<n;i++){
        if(!row[i] && !r1[r-i+n-1] && !r2[r+i]){
            row[i]=r1[r-i+n-1]=r2[r+i]=1;
            NQueen(r+1,n,ans);
            row[i]=r1[r-i+n-1]=r2[r+i]=0;
        }
    }

}
int main()
{   int n;
    cin>>n;
    int ans=0;
    NQueen(0,n,ans);
    cout<<ans;
    return 0;
}
