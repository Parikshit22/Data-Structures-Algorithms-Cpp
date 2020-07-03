#include <iostream>
#include <string>
using namespace std;
void GenerateFun(string a, int i){
    int k=0;
    while(i>0){
        (i&1)?cout<<a[k]:cout<<"";
        k++;
        i=i>>1;
    }
    cout<<endl;
}
void subarray(string a,int len){

    int num = (1<<len);
    for(int i=1;i<num;i++){
        GenerateFun(a,i);
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
