/**
 *  Seletiva UFFS 2018 - URI Online Judge
 *  Felipe G. Foschiera
 */
#include <iostream>
using namespace std;

int LCS(string a, string b){
    int n = a.length(), m = b.length();
    int dp[n+1][m+1];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
        else if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
        else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    }
    return dp[n][m];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    cout << LCS(a, b) << endl;
    return 0;
}