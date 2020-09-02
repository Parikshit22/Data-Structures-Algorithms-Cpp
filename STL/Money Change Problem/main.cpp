#include <iostream>

using namespace std;

void minnotes(int *coins,int money,int n,int &notes){
    if(n<0 || money==0){
       return;
    }
    while(true){
        if(coins[n]>money){
            n--;
        }
        else{
            break;
        }
    }
    int new_money = money-coins[n];
    notes++;
    minnotes(coins,new_money,n,notes);

}

int main()
{
    int coins[] = {1,2,5,10,20,50,100,200,500,2000};
    int money;
    cin>>money;
    int notes = 0;
    int n = sizeof(coins)/sizeof(coins[0]);
    minnotes(coins,money,n-1,notes);
    cout<<notes;
    return 0;
}
