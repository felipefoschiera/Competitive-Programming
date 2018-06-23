/**
 *  Distancia de edição para transformar uma string em outra
 *  Operacoes de inserção, remoção e substituição
 */
#include <iostream>
using namespace std;


int editDistance(string str1, string str2, int m, int n){
    int dp[m+1][n+1];
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++){
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(str1[i-1] == str2[j-1]) 
                dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
        }
 
    return dp[m][n];
}