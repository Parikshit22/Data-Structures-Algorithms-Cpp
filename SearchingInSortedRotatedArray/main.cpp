#include <iostream>

using namespace std;

int search(int * a,int s,int e,int key){
    if(s>e){
        return -1;
    }
    int mid = (s+e)/2;
    if(key == a[mid]){
        return mid;
    }
    if(a[s]<=a[mid]){
        if(a[s]<=key&&key<a[mid]){
            search(a,s,mid-1,key);
        }
        else{
            search(a,mid+1,e,key);
        }
    }
    else{
        if(a[mid]<key&&key<=a[e]){
            search(a,mid+1,e,key);
        }
        else{
            search(a,s,mid-1,key);
        }
    }

}


int main(){
    int arr[] = {6,7,8,9,0,1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key;
    cin>>key;
    int index = search(arr,0,n-1,key);
    cout<<index;
    return 0;
}
