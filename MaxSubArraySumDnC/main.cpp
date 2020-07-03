#include <iostream>

using namespace std;
int MaxCrossingSum(int *a, int s,int mid,int e){
    int left_sum = -10000;
    int sum =0;
    for(int i=mid;i>=s;i--){
        sum = a[i]+sum;
        if(sum >left_sum){
            left_sum = sum;
        }
    }
    int right_sum = -10000;
    int sum1 =0;
    for(int i=mid+1;i<=e;i++){
        sum1 = a[i]+sum1;
    if(sum1>right_sum){
            right_sum=sum1;
        }
    }
    return(left_sum+right_sum);
}
int MaxSum(int *a,int s, int e){
     if(s>e){
        return -1;}
    if(s==e){
        return a[e];
    }
    int mid = (s+e)/2;

    int max_sum_left_side = MaxSum(a,s,mid);
    int max_sum_right_side = MaxSum(a,mid+1,e);
    int max_sum_crossing_eachother = MaxCrossingSum(a,s,mid,e);
    return(max(max_sum_left_side,max(max_sum_crossing_eachother,max_sum_right_side)));
}

int main()
{
    int a[]= {1,3,-8,5,11,7};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<MaxSum(a,0,n-1);
    return 0;
}
