#include <iostream>
#include <string>
using namespace std;
void GenerateFun(string a, int i, int len){
    int k=0;
    int l =i;
    int sum =0;
    while(i>0){
        (i&1)?sum +=(a[k]-'0'):sum+=0;

        k++;
        i=i>>1;
    }

    i=l;
    k=0;
    if(sum%len==0){
       while(i>0){
        (i&1)?cout<<a[k]:cout<<"";
        k++;
        i=i>>1;
    }cout<<endl;
       }
}

void subarray(string a,int len){

    int num = (1<<len);
    for(int i=1;i<num;i++){
        GenerateFun(a,i,len);
    }
}

int main()
{
    string a;
    getline(cin,a);
    int len = a.length();
    subarray(a,len);
    return 0;
}
