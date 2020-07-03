#include <iostream>
#include <string>
#include <math.h>
using namespace std;
void Prime(int *A,int n){
int a = A[0];
int b = A[n-1];
int si = b-a;
int s[si];
for(int i=1;i<=si;i++){
    s[i-1]=1;
}

int sqr = sqrt(b);
int p[sqr]={0};



p[0]=0;
p[1]=1;
for(int i=2;i<sqr;i+=2){
    p[i] = 1;
}

for(int i=2;i<sqr;i+=2){
    if(p[i]){
        for(int j =i*i;j<sqr;j+=2*i){
            p[j] = 0;
        }
    }
}
for(int i=0;i<sqr;i++){
    cout<<p[i];
}
cout<<endl;
for(int i=1;i<=sqr;i++){
    if(p[i]){
        for(int j=0;j<si;j++){
            if(A[j]%i==0){
                s[j]=0;
            }
        }
    }
}
for(int i=0;i<si;i++){
    if(s[i]==1){
        cout<<A[i]<<endl;
    }
}

}


int main()
{
    int a[]= {25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44};
    int num = sizeof(a)/sizeof(a[0]);
    Prime(a,num);

    return 0;
}
