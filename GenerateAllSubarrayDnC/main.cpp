#include <iostream>
#include <string>
#include <string.h>
using namespace std;
void Subarray(char *a,char *b,int i,int j){
    if(a[i]=='\0'){
        b[j]='\0';
        cout<<b<<endl;
        return;
    }
    b[j]=a[i];
    Subarray(a,b,i+1,j+1);
    Subarray(a,b,i+1,j);

}

int main()
{   char a[] = "abcd\0";
    char b[100];

    Subarray(a,b,0,0);

    return 0;
}
