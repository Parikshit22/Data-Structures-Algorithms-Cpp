#include <stdio.h>
#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    int n;
    cin>>n;
    int m = int(n/2);
    for(int i=0;i<n;i++){
        if(i==0){
            for(int j=0;j<n;j++){
                if(j==0){
                    cout<<"*";
                }
                else if(j>0&&j<m){
                    cout<<" ";
                }
                else{
                    cout<<"*";
                }
            }
        }
        else if(i>0&&i<n-1){
            if(i<m){
                for(int j=0;j<n;j++){
                    if(j==0){
                        cout<<"*";
                    }
                    else if(j==m){
                        cout<<"*";
                    }
                    else{
                        cout<<" ";
                    }
                }
            }
            else if(i==m){
                for(int j=0;j<n;j++){
                    cout<<"*";
                }
            }
            else{
                for(int j=0;j<n;j++){
                    if(j==n-1){
                        cout<<"*";
                    }
                    else if(j==m){
                        cout<<"*";
                    }
                    else{
                        cout<<" ";
                    }
                }

            }
        }
        else{
            for(int j=0;j<n;j++){
                if(j<=m){
                    cout<<"*";
                }
                else if(j==n-1){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
