#include <iostream>
#include <string.h>
using namespace std;

int dp[1010][1010];

string s;

int solve(int l, int r){
    if(l == r) return 1;
    if(l+1 == r) return (s[l] == s[r] ? 2 : 1);
    if(dp[l][r] != -1)
        return dp[l][r];
    int res = 0;
    if(s[l] == s[r]) res = 2 + solve(l+1, r-1);
    else res = max(solve(l, r-1), solve(l+1, r));
    return dp[l][r] = res;
}

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        getline(cin, s);
        if(s.size() == 0){
            cout << "0\n";
            continue;
        }
        memset(dp, -1, sizeof dp);
        cout << solve(0, s.size()-1) << "\n";
    }
    return 0;
}