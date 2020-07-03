#include <iostream>

using namespace std;
bool ispossible(int *arr,int n,int s,int mid){
    int pages = 0;
    int student=1;
    for(int i=0;i<n;i++){
        if(pages+arr[i]<=mid){
            pages+=arr[i];
        }
        else{
            pages = arr[i];
            student++;
            if(student>s){
                return false;
            }

        }
    }
    return true;
}
int BookAllocation(int *arr,int n,int s){
    int start = arr[n-1];
    int e=0;
    for(int i=0;i<n;i++){
        e+=arr[i];
    }
    int ans;
    while(start<=e){
        int mid= (start+e)/2;
        if(ispossible(arr,n,s,mid)){
            ans = mid;
            e= mid-1;
        }
        else{

            start= mid+1;
        }
    }
    return ans;
}

int main()
{   int n;
    cin>>n;
    int s;
    cin>>s;
    int bp[n];
    for(int i=0;i<n;i++){
        cin>>bp[i];
    }
    int ans = BookAllocation(bp,n,s);
    cout<<ans;

    return 0;
}
