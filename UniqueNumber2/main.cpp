#include <iostream>
#include <string>
using namespace std;
void UniqueNumber(int *a,int n){
    int values=0;
    for(int i=0;i<n;i++){
        values = (values^a[i]);
    }
    int temp = values;
    int k=0;
    while(temp>0){
        if(temp&1){
            break;
        }
        k++;
        temp = temp>>1;
    }
    int mask = (1<<k);

    int v1=0;
    for(int j=0;j<n;j++){
        if((a[j]&mask) == mask){

            v1 = (v1^a[j]);
        }
    }
    int v2 = (values^v1);
    cout<<v1<<" "<<v2;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    UniqueNumber(arr,n);
    return 0;
}
