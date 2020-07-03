#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            bool islow = true;
            for(int j = i-1;j>=i-5&&j>=0;j--){
                if(arr[i]>arr[j]){
                    islow = false;
                    break;
                }
            }
            if(islow){
                cnt++;
            }
        }
        cout<<cnt<<endl;
        t--;
    }
    return 0;
}
