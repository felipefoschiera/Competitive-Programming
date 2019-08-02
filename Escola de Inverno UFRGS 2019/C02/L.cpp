#include <bits/stdc++.h>
using namespace std;

string destiny(string s){
    map<char, int> cnt;
    for(int i = 0; s[i]; i++){
        cnt[s[i]]++;
    }
    for(char c = 'a'; c < 'z'; c++){
        cnt[c+1] += cnt[c] / 2;
        cnt[c] %= 2;
    }
    string ans;
    for(char c = 'z'; c >= 'a'; c--){
        while(cnt[c]--){
            ans.push_back(c);
        }
    }
    return ans;
}

int main(){
    string s;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> s){
        cout << destiny(s) << '\n';
    }
    return 0;
}
