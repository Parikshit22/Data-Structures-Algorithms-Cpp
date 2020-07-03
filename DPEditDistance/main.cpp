#include <iostream>
#include <cstring>

using namespace std;
int dp[100][100] = {};
int editdistance(char *in, char *out){
    int inlen = strlen(in);
    int outlen = strlen(out);
    dp[0][0] = 0;
    for(int i=1;i<=inlen;i++){
        dp[i][0] = 1+dp[i-1][0];
    }
    for(int i=1;i<=outlen;i++){
        dp[0][i] = 1+dp[0][i-1];
    }
    for(int i=0;i<=inlen;i++){
        for(int j=0;j<=outlen;j++){
            int q1 = dp[i-1][j-1];
            int q2 = dp[i-1][j];
            int q3 = dp[i][j-1];
            dp[i][j] = min(q1,min(q2,q3))+(in[i]!=out[j]);
        }
    }
    return dp[inlen][outlen];
}

int main()
{   char in[100],out[100];
    cin>>in>>out;
    cout<<editdistance(in,out);

    return 0;
}
