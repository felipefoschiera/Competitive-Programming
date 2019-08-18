#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<string, string> ss;
typedef pair<int, ss> iss;
typedef vector<ss> vss;
typedef map<string, int> msi;

map<string, vss> LG;
msi dist;

int dijkstra(const string &s, const string &t){
    for(auto vtx : LG)
        dist[vtx.first] = INF;
    dist[s] = 0;
    priority_queue<iss, vector<iss>, greater<iss> > Q;
    Q.push({0, {s, ""}});
    while(!Q.empty()){
        string u = Q.top().second.first, x = Q.top().second.second;
        Q.pop();
        for(auto vtx : LG[u]){
            string v = vtx.first, y = vtx.second;
            int w = (int) y.size();
            if(x[0] == y[0]) continue;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                Q.push({dist[v], {v, y}});
            }
        }
    }
    return dist[t];
}

int main(){
    int M;
    string O, D, i1, i2, P;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> M, M != 0){
        cin >> O >> D;
        LG.clear();
        dist.clear();
        dist[O] = dist[D] = INF;
        for(int i = 0; i < M; i++){
            cin >> i1 >> i2 >> P;
            LG[i1].push_back({i2, P});
            LG[i2].push_back({i1, P});
        }
        int ans = dijkstra(D, O);
        if(ans != INF)
            cout << ans << endl;
        else
            cout << "impossivel" << endl; 
    }
    return 0;
}
