#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll v[212];
int n, q, d, m;

ll pd[212][25][12];

ll solve(int pos, ll sum, int pegos){
    if(pegos == m) return sum == 0;
    if(pos == n) return 0;
    if(pd[pos][sum][pegos] != -1)
        return pd[pos][sum][pegos];
    ll adsum = (sum + v[pos]) % d;
    if(adsum < 0) adsum += d;
    
    ll res = solve(pos+1, adsum%d, pegos+1) 
                + solve(pos+1, sum%d, pegos);
    return pd[pos][sum][pegos] = res;
}

int main(){
    int st = 1;
    while(cin >> n >> q, n+q){
        for(int i = 0; i < n; i++) cin >> v[i];
        cout << "SET " << st++ << ":\n";
        for(int qr = 1; qr <= q; qr++){
            cin >> d >> m;
            memset(pd, -1, sizeof pd);
            cout << "QUERY " << qr << ": " << solve(0, 0, 0) << '\n';
            
        }
    }
    
    return 0;
}
