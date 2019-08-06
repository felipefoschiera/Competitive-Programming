#include <iostream>
#include <unordered_map>
using namespace std;

typedef pair<int, int> ii;

int main(){ 
    int t;
    cin >> t;
    for(int tc = 0; tc < t; tc++){
        if(tc != 0) cout << "\n";
        int n;
        cin >> n;
        unordered_map<string, ii> cars;
        string car; int l, h;
        for(int i = 0; i < n; i++){
            cin >> car >> l >> h;
            cars[car] = {l, h};
        }
        int q, p;
        string res;
        cin >> q;
        while(q--){
            cin >> p;
            int cnt = 0;
            for(auto x : cars){
                if(p >= x.second.first && p <= x.second.second){
                    cnt++;
                    res = x.first;
                }
                if(cnt > 1) break;
            }
            if(cnt == 1){
                cout << res << "\n";
            }
            else cout << "UNDETERMINED\n";

        }
    }
    return 0;
}
