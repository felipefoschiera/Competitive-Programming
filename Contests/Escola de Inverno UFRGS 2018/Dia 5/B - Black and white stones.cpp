#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll A, B;
    while(cin >> A >> B){
        B = A - B;
        string s;
        cin >> s;
        int sz = s.length();   
        int cnt = 0;
        for(int i = 0; i < sz; i++) cnt += s[i] == 'B';
        int left = cnt-1, right = cnt;
        ll ans = 0;
        while(s[left]){
            while(left >= 0 && s[left] == 'B') left--;
            while(s[right] && s[right] == 'W') right++;
            if(left < 0 || (!s[right])) break;
            ans += min(A, (right-left)*B);
            swap(s[left], s[right]);
        } 
        cout << ans << '\n';
    }
    return 0;
}
