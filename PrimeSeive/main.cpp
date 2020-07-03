#include <iostream>
#include <string>
using namespace std;
void Prime(int *a,int n){
int s[n] = {0};
s[0]=0;
s[1]=0;
s[2]=1;
for(int i=3;i<n;i+=2){
    s[i] = 1;
}

for(int i=3;i<n;i+=2){
    if(s[i]){
        for(int j =i*i;j<n;j+=2*i){
            s[j] = 0;
        }
    }
}
for(int i=0;i<n;i++){
    if(s[i] == 1){
        cout<<a[i]<<endl;
    }
}
}

int main()
{
    int a[]= {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int num = sizeof(a)/sizeof(a[0]);
    Prime(a,num);

    return 0;
}
