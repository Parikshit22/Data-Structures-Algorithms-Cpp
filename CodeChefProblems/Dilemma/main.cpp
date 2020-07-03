#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0){
        string s;
        cin>>s;
        int l = s.length();
        int arr[l] = {0};
        for(int i=0;i<l;i++){
            arr[i] = s[i]-48;
        }
        int change=1;
        while(change>0){
            change=0;
            for(int i=0;i<l;i++){
                if(arr[i]==1){
                    change++;
                    arr[i] = -1;
                    if(i==0){
                        if(arr[i+1]!=-1){
                            if(arr[i+1]==0){arr[i+1]=1;}
                            else {arr[i+1]=0;}
                        }
                    }
                    else if(i==l-1){
                        if(arr[i-1]!=-1){
                            if(arr[i-1]==0){arr[i-1]=1;}
                            else {arr[i-1]=0;}
                        }
                    }
                    else{
                        if(arr[i-1]!=-1){
                            if(arr[i-1]==0){arr[i-1]=1;}
                            else {arr[i-1]=0;}
                        }
                        if(arr[i+1]!=-1){
                            if(arr[i+1]==0){arr[i+1]=1;}
                            else {arr[i+1]=0;}
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<l;i++){
            if(arr[i]!=-1){
                ans=1;
            }
        }
        if(ans==1){
            cout<<"LOSE"<<endl;
        }
        else{
            cout<<"WIN"<<endl;
        }
        t--;
    }
    return 0;
}
