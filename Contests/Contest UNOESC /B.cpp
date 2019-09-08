#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        ll res = (ceil(sqrt(8*n + 1)) / 2);
        cout << res << '\n';
    }
    return 0;
}