#include <iostream>
#include <set>
using namespace std;

const int MAX_LOG = 20;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        string s;
        cin >> s;
        int sz = s.length(), ans = 1;
        for(int t = 1; t <= MAX_LOG; t++){
            set<string> subs;
            for(int i = 0; i <= sz - t; i++){
                subs.insert(s.substr(i, t));
            }
            int max_sz = 1 << t;
            if((int)subs.size() < max_sz){
                ans = t;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}