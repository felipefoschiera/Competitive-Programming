#include <iostream>
#include <string.h>
#define MAX 1123
using namespace std;

string s, ans;
int n, size;

int dp[MAX][MAX];

int solve(int ind, int val){
    if(ind == size) return val == 0;
    if(dp[ind][val] != -1) return dp[ind][val];
    if(s[ind] != '?'){
        return solve(ind+1, (val*10 + (s[ind] - '0')) % n);
    }else{
        int i = 0;
        if(ind == 0) i = 1;
        for(; i < 10; i++){
            if(solve(ind+1, (val*10 + i) % n)){
                ans[ind] = i + '0';
                return 1;
            }
        }
    }

    return dp[ind][val] = 0;
}


int main(){
    while(cin >> s >> n){
        memset(dp, -1, sizeof dp);
        ans = s;
        size = s.length();
        if(solve(0, 0)) cout << ans << '\n';
        else cout << "*\n";
    }

    return 0;   
}