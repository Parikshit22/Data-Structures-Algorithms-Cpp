#include <iostream>

using namespace std;

int main()
{
    char a[100];
    cin>>a;
    int i=0;
    if(a[0]=='9'){
        i++;
    }
    for( ;a[i]!='\0';i++){
        if((a[i]-'0')>=5){
            a[i] = ('9'-a[i])+'0';
        }
    }
    cout<<a;
    return 0;
}
