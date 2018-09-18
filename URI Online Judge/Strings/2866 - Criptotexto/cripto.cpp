#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string res = "";
        for(auto c : s)
            if(islower(c)) res += c;
        reverse(res.begin(), res.end());
        cout << res << '\n';
    }
    return 0;
}