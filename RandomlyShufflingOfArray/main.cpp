#include <iostream>
#include <ctime>
#include<cstdlib>
using namespace std;

void RandomShuffleArray(int *a,int s ,int e){
    srand(time(NULL));
    int j,i;
    for( j = e;j>0;j--){
         i = rand()%(j+1);
        swap(a[i],a[j]);
    }

}


int main()
{   int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    RandomShuffleArray(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
