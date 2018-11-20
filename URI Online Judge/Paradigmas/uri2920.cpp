// URI 2920 - Número Pequeno
// Felipe G. Foschiera
#include <iostream>
using namespace std;

int main(){
    string s;
    int K;
    while(cin >> s >> K){
        string ans = "";
        for(int i = 0; i < (int)s.length(); i++){
            while(!ans.empty() && K > 0 && ans.back() > s[i]){
                ans.pop_back();
                K--;
            }
            ans.push_back(s[i]);
        }
        while(!ans.empty() && K > 0){
            ans.pop_back();
            K--;
        }
        cout << ans << '\n';
    }
    return 0;
}