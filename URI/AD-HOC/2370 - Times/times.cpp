/**
 *  URI 2370 - Times
 *  Felipe G. Foschiera
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, string> jogador;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, T;
    cin >> N >> T;
    vector<jogador> jog;
    jog.assign(N, jogador());
    for(int i = 0; i < N; i++){
        cin >> jog[i].second >> jog[i].first;
    }
    sort(jog.begin(), jog.end());
    vector<vector<string>> times;
    times.assign(T, vector<string>());
    int t = 0;
    for(int i = 0; i < N; i++){
        times[t].push_back(jog.back().second);
        jog.pop_back();
        t++;
        if(t == T) t = 0;
    }
    for(int i = 0; i < T; i++){
        sort(times[i].begin(), times[i].end());
        cout << "Time " << i+1 << endl;  
        for(auto s : times[i]){
            cout << s << endl;
        }  
        cout << endl;
    }
    return 0;
}