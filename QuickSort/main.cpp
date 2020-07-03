#include <iostream>
#include <string>
using namespace std;
int Partision(int *a,int s,int e){
    int i= s-1;
    for(int j=s;j<e;j++){
        if(a[j]<=a[e]){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
    return (i+1);
}

void QuickSort(int *a,int s, int e){
    if(e>s){
    int p = Partision(a,s,e);
    QuickSort(a,s,p-1);
    QuickSort(a,p+1,e);
}}

int main()
{   int arr[] = {1,3,3,9,123,567,243,8,6,4,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
