#include <iostream>

using namespace std;

int main()
{
    int a[100];
    int n;
    int k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){

            cout<<endl;
        for(int j =i;j<n;j++){
             k =i;
            while(k<=j){
                cout<<a[k]<<",";
                k++;
            }

        }
    }


    return 0;
}
