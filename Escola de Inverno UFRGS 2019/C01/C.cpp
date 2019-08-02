#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        int diff = b[0] - a[0];
        string c;
        cin >> c;
        string nova = c;
        for(int i = 0; i < m; i++){
            nova[i] = (((c[i]-'A') - diff + 26) %26) + 'A';
        }

        cout << "Case #" << tc << ": "  <<  nova << '\n';
    }
    return 0;
}
