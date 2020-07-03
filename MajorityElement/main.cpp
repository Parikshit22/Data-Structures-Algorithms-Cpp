#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Result{
    Result():output1(){};
    int output1[100];
    };
int main()
{

    int input1 = 2;
    int input2[] = {2,7};
    for(int i=0;i<input1;i++){
    int temp = i+1;
    for(int j= i+temp;j<input1;j+=temp){
        input2[j] = input2[j]-input2[i];
    }}
    Result a(10);

    a.output1= input2[0];

    return a;


    return 0;
}

