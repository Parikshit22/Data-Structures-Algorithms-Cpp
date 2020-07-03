#include <iostream>
#include <string>
#include <string.h>

using namespace std;
char arr[][10] = {{"\0"},{"\0"},{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}};

void Number(char *a,char *b,int i,int j){
    if(a[i]=='\0'){
        b[j]='\0';
        cout<<b<<endl;
        return;
    }
    int digit = a[i]-'0';
    if(digit==0||digit==1){
        Number(a,b,i+1,j);
    }
    for(int l=0;arr[digit][l]!='\0';l++){

        b[j] = arr[digit][l];
        Number(a,b,i+1,j+1);
    }

}



int main(){
    char b[100];
    char a[] = "6513";

    Number(a,b,0,0);
    return 0;
}
