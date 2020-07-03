#include <iostream>

using namespace std;
void TowerOfHanoi(int n,char src,char des, char helper){
    if(n==0)
        return;
    TowerOfHanoi(n-1,src,helper,des);
    cout<<"move "<<n<<" disc from "<<src<<" to "<<des<<endl;
    TowerOfHanoi(n-1,helper,des,src);
}

int main()
{   int n;
    cin>>n;
    TowerOfHanoi(n,'A','C','B');
    return 0;
}
