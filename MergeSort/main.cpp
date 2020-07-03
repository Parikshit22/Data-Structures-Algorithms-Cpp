#include <iostream>

using namespace std;
void Merge(int *a, int s,int mid, int e){
    int n1 = mid-s+1;
    int n2 = e-mid;
    int l =0;
    int m =0;
    int i=s;
    int a1[n1],a2[n2];
    for(int k=0;k<n1;k++){
        a1[k]=a[s+k];
    }
    for(int k=0;k<n2;k++){
        a2[k]=a[mid+1+k];
    }
    while(l<n1&&m<n2){
        if(a1[l]>=a2[m]){
            a[i]=a2[m];
            i++;
            m++;
        }
        else{
            a[i]=a1[l];
            i++;
            l++;
        }

    }
    while(l<n1){
        a[i]=a1[l];
        l++;
        i++;
    }
    while(m<n2){
        a[i] = a2[m];
        m++;
        i++;
    }

}
int MergeSort(int *a,int s,int e){
    if(s<e)
    {
    int mid = (s+e)/2;
    MergeSort(a,s,mid);
    MergeSort(a,mid+1,e);
    Merge(a,s,mid,e);
    }
}
int main()
{
    int arr[] = {6,7,8,9,0,1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
