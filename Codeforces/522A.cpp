// Codeforces 522A - Reposts
// Felipe G. Foschiera
#include <iostream>
#include <map>
#include <queue>
using namespace std;

map<string, vector<string> > adj;
map<string, int> dist;

int bfs(string start){
    queue<string> fila;
    fila.push(start);
    int best = 0;
    while(!fila.empty()){
        string u = fila.front(); fila.pop();
        for(auto v : adj[u]){
            if(dist[v] < dist[u] + 1){
                dist[v] = dist[u] + 1;
                best = max(best, dist[v]);
                fila.push(v);
            }
        }
    }
    return best;
}

int main(){
    int n;
    cin >> n;
    string a, b, x;
    while(n--){
        cin >> a >> x >> b;
        string novoA = "", novoB = "";
        for(int i = 0; a[i]; i++) novoA.push_back(tolower(a[i]));
        for(int i = 0; b[i]; i++) novoB.push_back(tolower(b[i]));
        adj[novoB].push_back(novoA);
        dist[novoA] = 0, dist[novoB] = 0;
    }
    int res = bfs("polycarp");
    cout << ++res << '\n';
    return 0;
}