#include <iostream>
#include <sstream>
#include <queue>
#define MAXN 100
using namespace std;

int N;
vector<int> adjList[MAXN];

bool ehBipartido(int s){
    queue<int> q;
    q.push(s);
    vector<int> color(N, -1);
    color[s] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : adjList[u]){
            if(color[v] == -1){
                color[v] = 1 - color[u];
                q.push(v);
            }else if(color[v] == color[u]) return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> N, N){
        for(int i = 0; i < N; i++) adjList[i].clear();
        int id;
        string lista;
        stringstream ss;
        for(int i = 0; i < N; i++){
            cin >> id;
            id--;
            cin.ignore();
            getline(cin, lista);
            ss << lista;
            int adj;
            while(ss >> adj)
                adjList[id].push_back(--adj);
            ss.clear();
        }
        cout << (ehBipartido(0) ? "SIM\n" : "NAO\n");

    }
    return 0;
}