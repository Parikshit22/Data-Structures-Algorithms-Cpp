#include <iostream>
#include <string.h>

using namespace std;
void Permutation(char *a,char *b,int i,int j,int len){
if(a[i]=='\0'){
    b[j]='\0';
    cout<<b<<endl;
}
for(int k=i;k<len;k++){
    swap(a[i],a[k]);
    b[j]= a[i];
    Permutation(a,b,i+1,j+1,len);
    swap(a[i],a[k]);
}
}

int main()
{   char a[100];
    char b[100];
    cin>>a;
    int len = strlen(a);
    Permutation(a,b,0,0,len);

    return 0;
}
