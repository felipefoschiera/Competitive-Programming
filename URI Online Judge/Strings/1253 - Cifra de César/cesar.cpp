#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int shift;
        cin >> shift;
        string ans = "";
        int sz = s.length();
        for(int i = 0; i < sz; i++){
            char nova = s[i] - shift;
            if(nova < 'A'){
                int diff = 'A' - nova;
                nova = 'Z' + 1 - diff;
            }
                ans += nova;
        }
        cout << ans << '\n';
    }
    return 0;
}