#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        float arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        float mean=0;
        for(int i=0;i<n;i++){
            mean += arr[i];
        }
        mean = mean/n;
        int i;
        for(i=0;i<n;i++){
            if(arr[i]==mean){
                break;
            }
        }
        if(i==n){
            cout<<"Impossible"<<endl;
        }
        else{
            cout<<i+1<<endl;
        }
        t--;
    }
    return 0;
}
