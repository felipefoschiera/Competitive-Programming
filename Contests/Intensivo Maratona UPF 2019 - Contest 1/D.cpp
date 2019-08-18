#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int n, m;
set<string> strs;

void solve(int idx1, int idx2, string s){
    if(idx1 > n || idx2 > m) return;
    if(idx1 == n && idx2 == m){
        strs.insert(s);
        return;
    }
    solve(idx1+1, idx2, s + s1[idx1]);
    solve(idx1, idx2+1, s + s2[idx2]);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> s1 >> s2;
        n = s1.size(); m = s2.size();
        strs.clear();
        solve(0, 0, "");
        for(auto x : strs){
            cout << x << '\n';
        }
        cout << '\n';

    }
    return 0;
}