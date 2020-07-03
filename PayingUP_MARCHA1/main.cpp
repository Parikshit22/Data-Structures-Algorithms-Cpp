#include <iostream>
#include <string>
using namespace std;
int GenerateFun(int *a, int i){
    int k=0;
    int sum=0;
    while(i>0){

        if(i&1){
            sum +=a[k];
        }

        k++;
        i=i>>1;
    }
    return sum;
}
void subarray(int *a,int len,int money){
    int value;
    int num = (1<<len);
    for(int i=0;i<num;i++){
        value = GenerateFun(a,i);
        if(value == money){
            cout<<"you are robbed"<<endl;
            break;
        }
    }
    if(value!=money){
    cout<<"you are safe"<<endl;}
}

int main()
{
    int a[]={10,20,30,50};
    int len = 4;
    subarray(a,len,10);
    return 0;
}
