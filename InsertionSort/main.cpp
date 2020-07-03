#include <iostream>

using namespace std;

int main(){
    int a[] = {7,3,4,12,8,2,4,19};
    int n = sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++){
        int no = a[i];
        int j = i-1;
        for(;j>=0&&a[j]>no;j--){

                a[j+1]=a[j];


        } a[j+1] = no;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
