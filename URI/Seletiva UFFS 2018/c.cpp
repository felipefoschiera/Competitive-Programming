/**
 *  Seletiva UFFS 2018 - URI Online Judge
 *  Felipe G. Foschiera
 */
#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int editDistance(string a, string b, int n, int m){
    int dp[n+1][m+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        }
    }
    return dp[n][m];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    vector<string> strs;
    string s;
    for(int i = 0; i < q; i++){
        cin >> s;
        strs.push_back(s);
    }
    int c;
    cin >> c;
    while(c--){
        cin >> s;
        string best;
        int best_diff = INF;
        for(int i = 0; i < q; i++){
                int calc = editDistance(s, strs[i],  s.length(), strs[i].length());
                if(calc < best_diff){
                    best_diff = calc;
                    best = strs[i];
                }
        }
        cout << best;
        cout << (c == 0 ? "\n" : " ");
    }
    return 0;   
}