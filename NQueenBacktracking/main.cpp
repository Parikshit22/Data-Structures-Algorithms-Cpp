#include <iostream>

using namespace std;
bool IsPossible(int a[][100],int j,int i,int n){
    int row = i;
    while(row>=0){
        if(a[row][j]==1){
            return false;
        }
        row--;

    }
    int x = i;
    int y = j;
    while(x>=0&&y>=0){
        if(a[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
     x = i;
     y = j;
    while(x>=0&&y<n){
        if(a[x][y]==1){
            return false;
        }
        x--;
        y++;
    }
    return true;
}
bool NQueen(int a[][100],int n,int i){
    if(i==n){
        for(int l=0;l<n;l++){
            for(int m =0;m<n;m++){
                if(a[l][m]==1){
                    cout<<'Q'<<" ";
                }
                else{
                    cout<<"_"<<" ";
                }
            }cout<<endl;
        }
        return true;
    }
    for(int j=0;j<n;j++){
        if(IsPossible(a,j,i,n)){
            a[i][j]=1;
            bool AgliQueenRakhPaaRaheHai = NQueen(a,n,i+1);
            if(AgliQueenRakhPaaRaheHai){
                return true;
            }
            a[i][j] = 0;
        }
    }
    return false;
}
int main()
{   int n;
    cin>>n;
    int arr[100][100] = {0};
    NQueen(arr,n,0);


    return 0;
}
