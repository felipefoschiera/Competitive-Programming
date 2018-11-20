#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, D;
    while(cin >> N >> D, (N+D)){
        string s; cin >> s;
        string ans = "";
        for(int i = 0; i < (int)s.length(); i++){
            while((!ans.empty()) && D > 0 && ans.back() < s[i]){
                ans.pop_back();
                D--;
            }
            ans.push_back(s[i]);
        }
        while(!ans.empty() && D > 0){
            ans.pop_back();
            D--;
        } 
        cout << ans << endl;

    }
    return 0;
}
