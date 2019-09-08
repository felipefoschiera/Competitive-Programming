#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        if(n % 2 == 1) cout << "0\n";
        else cout << n/2 << '\n';
    }
    return 0;
}