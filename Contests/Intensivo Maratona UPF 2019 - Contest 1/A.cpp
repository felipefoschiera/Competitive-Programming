#include <bits/stdc++.h>
using namespace std;

int v[201010];

int main(){
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> v[i];
    int g = v[0];
    for(int i = 1; i < n; i++) g = __gcd(g, v[i]);
    if(!x || x % g == 0){
        cout << "YES\n";
    }else cout << "NO\n";
    return 0;   
}