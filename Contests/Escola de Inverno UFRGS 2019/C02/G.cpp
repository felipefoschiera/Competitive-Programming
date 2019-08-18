#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    long long res;
    if(n <= k) res = 10LL;
    else {
        res = 5LL * ceil((double)n / k);
     }
    cout << res << '\n';
    return 0;
}