#include <iostream>
#include <math.h>
using namespace std;
bool IsPossible(int a[][9],int n,int i,int j,int num){
int r = sqrt(n);
int sx = (i/r)*3;
int sy = (j/r)*3;
for(int l=0;l<n;l++){
    if(a[l][j]==num){
        return false;
    }
}
for(int f=0;f<n;f++){
    if(a[i][f]==num){
        return false;
    }
}
for(int p=sx;p<sx+3;p++){
    for(int q=sy;q<sy+3;q++){
        if(a[p][q]==num){
            return false;
        }
    }
}
return true;
}
bool SudokuSolver(int a[][9],int n,int i,int j){
    if(i==n){
        for(int A=0;A<n;A++){
            for(int B=0;B<n;B++){
                cout<<a[A][B]<<" ";
            }cout<<endl;
        }
        return true;
    }
    if(j==n){
       return SudokuSolver(a,n,i+1,0);
    }
    if(a[i][j]!=0){
        return SudokuSolver(a,n,i,j+1);
    }
    for(int num=1;num<=n;num++){
        if(IsPossible(a,n,i,j,num)){
            a[i][j]=num;
            bool AgeRakhPaaRaheHai = SudokuSolver(a,n,i,j+1);
            if(AgeRakhPaaRaheHai){
                return true;
            }
        }
    }
    a[i][j]=0;
    return false;
}

int main()
{   int arr[9][9]= {{5,3,0,0,7,0,0,0,0},
                    {6,0,0,1,9,5,0,0,0},
                    {0,9,8,0,0,0,0,6,0},
                    {8,0,0,0,6,0,0,0,3},
                    {4,0,0,8,0,3,0,0,1},
                    {7,0,0,0,2,0,0,0,6},
                    {0,6,0,0,0,0,2,8,0},
                    {0,0,0,4,1,9,0,0,5},
                    {0,0,0,0,8,0,0,7,9}};

    int n=9;
    SudokuSolver(arr,n,0,0);

    return 0;
}
