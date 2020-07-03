#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0){
        int m,n,q;
        cin>>m>>n>>q;
        int mat[m][n];
        for(int l=0;l<m;l++){
                for(int j=0;j<n;j++){
                    mat[l][j] = 0;
                }
                cout<<endl;
            }
        for(int i=0;i<q;i++){
            int temp1,temp2;
            cin>>temp1>>temp2;
            temp1--;
            temp2--;
            for(int a=0;a<n;a++){
                mat[temp1][a]++;
            }
            for(int b=0;b<m;b++){
                mat[b][temp2]++;
            }
        }

        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]%2 !=0){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;



        t--;
    }
    return 0;
}

