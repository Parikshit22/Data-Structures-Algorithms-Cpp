#include <stdio.h>
#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    int arr[3][10];
    for(int i=0;i<3;i++){
        for(int j=0;j<10;j++){
            arr[i][j] = j;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<10;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
