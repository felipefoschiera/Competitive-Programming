#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int q;
    cin >> q;
    while(q--){
        ll k;
        cin >> k;
        ll res = (k * (k*2)) / 2;
        cout << res << '\n';
    }
    return 0;
}