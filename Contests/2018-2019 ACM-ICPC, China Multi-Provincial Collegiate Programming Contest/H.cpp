#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct monster {
    int atk, x;
    bool operator < (const monster other) const {
        return atk*other.x > other.atk*x;
    }
};

typedef long long ll;

int main(){
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        int n, hp;
        cin >> n;
        ll soma = 0;        
        monster v[n];
        for(int i = 0; i < n; i++){
            cin >> hp >> v[i].atk;
            ll d = 1, x = 0;
            while(hp > 0){
                hp -= d; x++; d++;
            }
            soma += v[i].atk;
            v[i].x = x;
        }
        sort(v, v+n);
        ll res = 0LL, ac = 0LL;
        for(int i = 0; i < n; i++){
            res += soma * (v[i].x);
            soma -= v[i].atk;
        }
        cout << "Case #" << tc << ": " << res << '\n';
    }
    return 0;
}