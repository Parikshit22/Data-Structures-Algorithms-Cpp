#include <iostream>
#include <string.h>
#include<algorithm>
using namespace std;

int main()
{
    int a[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12,},{13,14,15,16}};
    int sr=0,sc =0,ec =3,er =3;
    while((ec>sc)&&(er>sr)){
        for(int i=sc;i<=ec;i++){
            cout<<a[sr][i];
        }sr++;
        for(int i=sr;i<=er;i++){
            cout<<a[i][ec];
        }ec--;
        for(int i=ec;i>=sc;i--){
            cout<<a[er][i];
        }er--;
        for(int i=er;i>=sr;i--){
            cout<<a[i][sc];
        }sc++;
    }





    return 0;
}
