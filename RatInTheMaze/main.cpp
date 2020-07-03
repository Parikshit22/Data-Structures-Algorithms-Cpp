#include <iostream>

using namespace std;
void RatInTheMaze(int a[][5],int n,int row,int col){

if(row==n&&col==n){
    return;
}
if(row<n||col<n){
a[row][col]=2;
if(a[row][col+1]!=1){
    RatInTheMaze(a,n,row,col+1);
}

else if(a[row+1][col]!=1){
    RatInTheMaze(a,n,row+1,col);
}
else{
    a[row][col]=1;
    if(a[row-1][col]!=1){
        RatInTheMaze(a,n,row-1,col);
    }
    if(a[row][col-1]!=0){
        RatInTheMaze(a,n,row,col-1);
    }
    }

}
}
int main()
{   int a[5][5] = {{0,0,0,0,0},{1,0,0,0,0},{1,1,0,0,1},{1,1,1,0,1},{1,1,1,0,0}};
    RatInTheMaze(a,5,0,0);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
