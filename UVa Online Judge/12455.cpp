#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int p; cin >> p;
        int v[p];
        for(int i = 0; i < p; i++) cin >> v[i];
        bool ok = false;
        for(int mask = 0; mask < (1 << p); mask++){
            int s = 0;
            for(int j = 0; j < p; j++){
                if(mask & (1 << j)) s += v[j];
            }
            if(s == n){
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}