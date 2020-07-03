#include <iostream>
#include <cstring>
using namespace std;
int dp[100][100];
int LCS(char *in,char *out ){
    int inlen = strlen(in);
    int outlen = strlen(out);

    dp[0][0] = 0;
    for(int i=1;i<=inlen;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=outlen;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=inlen;i++){
        for(int j=1;j<=outlen;j++){
            if(in[i]==out[j]){
                dp[i][j] = 1+ dp[i-1][j-1];
            }
            else{
                int q1 = dp[i-1][j];
                int q2 = dp[i][j-1];
                dp[i][j] = max(q1,q2);
            }
        }
    }
    return dp[inlen][outlen];
}

int main()
{   char in[100],out[100];
    cin>>in>>out;
    cout<<LCS(in,out);
    return 0;
}
