#include <iostream>
using namespace std;
typedef long long ll;

int count[3];

int main(){
    string s;
    while(cin >> s){
        int acum = 0;
        ll ans = 0LL;
        count[0] = 1;
        count[1] = count[2] = 0;
        int sz = s.length();
        for(int i = 0; i < sz; i++){
            if(!isdigit(s[i])){
                acum = 0;
                count[0] = 1;
                count[1] = count[2] = 0;
                continue;
            }
            acum += (s[i] - '0');
            acum %= 3;
            ans += (long long) count[acum];
            count[acum]++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}