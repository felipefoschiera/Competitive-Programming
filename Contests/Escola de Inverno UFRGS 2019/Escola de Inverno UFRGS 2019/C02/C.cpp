#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000100;
typedef long long ll;

ll A[MAX], B[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < k; i++) cin >> B[i];
    ll d = B[0];
    for(int i = 1; i < k; i++)
        d = __gcd(d, B[i]);
    bool ok = true;
    for(int i = 1; i < n; i++){
        if(abs(A[i] - A[0]) % d != 0){
            ok = false; break;
        }
    }
    cout << (ok ? "Yes" : "No") << '\n';
    return 0;
}