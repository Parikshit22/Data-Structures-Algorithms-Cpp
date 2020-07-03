#include <iostream>

using namespace std;
class Account{
    int number;
    static int amount;

public:
    static setamount(int a){
        amount = a;
    }
    void getamount(){
        cout<<amount<<endl;
    }
};
int Account:: amount = 9;
int main()
{
    Account a,b;
    Account :: setamount(100);
    a.setamount(10);
    a.getamount();
    return 0;
}
