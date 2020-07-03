#include <iostream>

using namespace std;

int ReturnMax(int *a,int s,int e){
    if(s>e){
        return -1;
    }
    if(s==e){
        return a[e];
    }
    int mid = (s+e)/2;
    int maxm = max( ReturnMax(a,s,mid),ReturnMax(a,mid+1,e));
    return maxm;

}
int main()
{
    int arr[] = {6,7,8,9,10,1,29,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int num = ReturnMax(arr,0,n-1);
    cout<<num;
    return 0;
}
