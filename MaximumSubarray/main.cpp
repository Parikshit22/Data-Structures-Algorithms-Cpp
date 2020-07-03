#include <iostream>

using namespace std;

int main()
{
    int a[10] ;
    for(int i =0;i<10;i++){
        cin>>a[i];
    }
    int curr_sum =0;
    int max_sum =0;
    for(int i=0;i<10;i++){
        curr_sum = a[i] + curr_sum;

        if(curr_sum<0){
            curr_sum = 0;
        }
        max_sum = max(max_sum,curr_sum);
    }
    cout<<max_sum;
    return 0;
}
