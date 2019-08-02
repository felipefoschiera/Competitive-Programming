#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class PilhaMaximo {
private:
    stack<ll> s;
    vector<ll> maxi;
public:
    void PUSH(ll u){
        s.push(u);
        if(maxi.size() == 0 || u >= maxi.back()) maxi.push_back(u);

    }
    ll maior(){
        if(maxi.size() == 0) return 0;
        return maxi.back();
    }
    void POP(){
        if(s.size() > 0){
            ll u = s.top();
            s.pop();
            if(maxi.size() > 0 && u == maxi.back()) maxi.pop_back();
        }
    }
};

int n, p, q, m;
unsigned int SA, SB, SC;
unsigned int rng61(){
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}

ll gen(){
    scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
    ll res = 0;
    PilhaMaximo pm;
    for(int i = 1; i <= n; i++){
        if(rng61() % (p + q) < p)
            pm.PUSH(rng61() % m + 1);
        else
            pm.POP();

        res ^= i * pm.maior();
    }
    return res;
}

int main(){
    int T, tc, ans;
    scanf("%d", &T);
    for(tc = 1; tc <= T; tc++){

        printf("Case #%d: %lld\n", tc, gen());
    }
    return 0;
}
