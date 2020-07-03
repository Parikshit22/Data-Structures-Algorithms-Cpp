#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int k;
        cin>>k;
        int x = k/n;
        int y = k%n;
        int ans;
        if(y<n/2){
            ans = y*2;
        }
        else if(y>n/2){
            ans = (n-y)*2;
        }
        else{
            ans = n-1;
        }
        cout<<ans<<endl;
        t--;
    }
    return 0;
}
