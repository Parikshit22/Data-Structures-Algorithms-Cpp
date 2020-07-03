#include <iostream>

using namespace std;
int fun(){
    cout<<"hello"<<endl;
    return 0;
}
int fun(int a){
    return a;
}
/*
void fun(){
}
This function will give error
*/
void fun(float a){
    cout<<a;
    cout<<"empty"<<endl;
}

int main()
{
    cout<<fun(10);
    fun();
    fun(2.87890f);
    return 0;
}
