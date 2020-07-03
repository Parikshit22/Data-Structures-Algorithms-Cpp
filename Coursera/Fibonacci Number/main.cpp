#include <iostream>
#include <vector>
using namespace std;
int n;
vector<long long> arr(n+1);
long long Fibonacci(int num){
    if(arr[num]!=-1){
        return arr[num];
    }
    if(num==1){

        return 1;
    }
    if(num==0){
        return 0;
    }
    arr[num] = Fibonacci(num-1)+Fibonacci(num-2);
    return Fibonacci(num-1)+Fibonacci(num-2);
    }
int main()
{

    cin>>n;
    for(int i=0;i<=n;i++){
        arr[i] = -1;
    }
    cout<<Fibonacci(n)<<endl;
    return 0;
}
