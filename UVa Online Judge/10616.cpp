#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;

ll vals[212];
int n, q, d, m;

ll dp[212][15][25];
bool vis[212][15][25];

ll solve(int pos, int pegos, int sum){
    if(pegos == m) return sum == 0;
    if(pos == n) return 0;
    if(vis[pos][pegos][sum])
        return dp[pos][pegos][sum];
    vis[pos][pegos][sum] = 1;
    ll res = solve(pos+1, pegos+1, (sum+vals[pos])%d) 
               + solve(pos+1, pegos, sum);
    return dp[pos][pegos][sum] = res;
}

int main(){
    int tc = 1;
    while(cin >> n >> q, n+q){
        for(int i = 0; i < n; i++) cin >> vals[i];
        cout << "SET " << tc++ << ":\n";
        for(int qr = 1; qr <= q; qr++){
            cin >> d >> m;
            memset(vis, 0, sizeof vis);
            cout << "QUERY " << qr << ": " << solve(0, 0, 0) << '\n';
        }
    }
    return 0;
}