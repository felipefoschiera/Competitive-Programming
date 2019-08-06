#include <iostream>
#include <string.h>
using namespace std;


const int INF = 1e9;
int x;
int wind[10][1010];
int dp[10][1010];

int solve(int alt, int pos){
    if(pos == x){
        if(alt == 0) return 0;
        return INF;
    }
    if(dp[alt][pos] != -1)
        return dp[alt][pos];
    int k = wind[alt][pos];
    int opt1 = 30 - k + solve(alt, pos+1);
    int opt2 = INF, opt3 = INF;
    if(alt-1 >= 0)
        opt2 = 20 - k + solve(alt-1, pos+1);
    if(alt+1 <= 9)
        opt3 = 60 - k + solve(alt+1, pos+1);
    return dp[alt][pos] = min(opt1, min(opt2, opt3)); 
}

int main(){
    int n;
    cin >> n;
    while(n--){
        cin >> x;
        x /= 100;
        for(int i = 9; i >= 0; i--)
            for(int j = 0; j < x; j++)
                cin >> wind[i][j];

        memset(dp, -1, sizeof dp);
        cout << solve(0, 0) << '\n';
        cout << '\n';

    }
    return 0;
}