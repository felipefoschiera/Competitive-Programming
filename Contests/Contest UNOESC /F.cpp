#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        if(n == 1) cout << 2 << '\n';
        else if(n == 2) cout << 3 << '\n';
        else {
            int l = log2(n);
            l++;
            cout << (1 << l) - 1 << '\n';
        }
    }
    return 0;
}