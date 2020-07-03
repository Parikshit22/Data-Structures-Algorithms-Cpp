#include <iostream>

using namespace std;
bool IsValid(int *a,int mid,int n ,int k){
    int p=1;
    int sum =0;
    for(int i=0;i<n;i++){
        if((sum+a[i])>mid){
            sum =a[i];
            p++;}
            if(p>k){
                return false;
            }

            sum += a[i];

        }
        return true;
    }

int PaintersPartision(int *a,int n,int k){
    int s=0;int e=0;
    int totallength=0;
    for(int i=0;i<n;i++){
        totallength += a[i];
        s = max(s,a[i]);
    }
    e = totallength;
    int ans=s;
while(s<=e){
    int mid = (s+e)/2;
    if(IsValid(a,mid,n,k)){
        e = mid-1;
        ans = mid;
    }
    else{
        s = mid+1;
    }
}
return ans;
}

int main()
{   int n;int k;
    cin>>n>>k;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<PaintersPartision(arr,n,k);

    return 0;
}
