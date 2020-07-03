#include <iostream>

using namespace std;
int MergeCount(int *a,int s,int mid,int e){
    int len1 = mid-s+1;
    int len2 = e-mid;
    int L[len1];
    int R[len2];
    for(int p=0;p<len1;p++){
        L[p] = a[s+p];
    }
    for(int p=0;p<len2;p++){
        R[p] = a[mid+p+1];
    }
    int l=0;
    int n=0;
    int i=s;
    int c=0;
    while(l<len1&&n<len2){
        if(L[l]>R[n]){
            a[i]=R[n];
            n++;
            i++;
            c++;
        }
        else{
            a[i]=L[l];
            l++;
            i++;
        }
    }
    while(l<len1){
        a[i]=L[l];
        l++;
        i++;
        c++;
    }
    while(n<len2){
        a[i]=R[n];
        n++;
        i++;
    }
    return c;
}
int MergeInversion(int *a,int s,int e,int c){
    if(s>e){
            return -1;}
    if(s==e){
        return 0;
    }

        int mid = (s+e)/2;

        MergeInversion(a,s,mid,c);
        MergeInversion(a,mid+1,e,c);
        c+= MergeCount(a,s,mid,e);
return c;

}

int main()
{
    int arr[] = {1,9,6,4,5};
    int num = sizeof(arr)/sizeof(arr[0]);
    cout<<MergeInversion(arr,0,num-1,0);

    return 0;
}
