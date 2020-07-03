#include <iostream>

using namespace std;

int main()
{
    int c1,c2,c3,c4;
    int RN,CN;
    cin>>c1>>c2>>c3>>c4>>RN>>CN;
    int R[RN],C[CN];
    for(int i=0;i<RN;i++){
        cin>>R[i];
    }
    for(int i =0;i<CN;i++){
        cin>>C[i];
    }
    int Rsum=0;
    for(int i=0;i<RN;i++){
        Rsum += min((R[i]*c1),c2);
    }
    if(Rsum>c3){
        Rsum = c3;
    }
    int Csum;
    for(int i =0;i<CN;i++){
        Csum += min((C[i]*c1),c2);
    }
    if(Csum>c3){
        Csum = c3;
    }
    int total_sum = min((Csum+Rsum),c4);
    cout<<total_sum;

    return 0;
}
