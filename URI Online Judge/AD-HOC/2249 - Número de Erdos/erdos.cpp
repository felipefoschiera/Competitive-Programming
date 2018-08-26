// URI 2249 - Número de Erdos
// Felipe G. Foschiera
#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#define INF ((int)1e9)
using namespace std;

string paul = "P. Erdos";
map<string, vector<string> > adj;
map<string, int> dist;

bool cmp(string a, string b){
    string sob1 = string(a.begin()+3, a.end());
    string sob2 = string(b.begin()+3, b.end());
    if(sob1 != sob2) return sob1 < sob2;
    return a[0] < b[0];
}

void bfs(){
    dist[paul] = 0;
    queue<string> fila;
    fila.push(paul);
    while(!fila.empty()){
        string u = fila.front();
        fila.pop();
        for(auto v : adj[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                fila.push(v);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, tc = 1;
    while(cin >> N, N){
        cin.ignore();
        string line;
        vector<string> todos;
        for(int i = 0; i < N; i++){
            getline(cin, line);
            vector<string> autores;
            string nome = "";
            int sz = line.length();
            for(int i = 0; i < sz; i++){
                if(line[i] == ',') { if(nome != "") autores.push_back(nome); nome = ""; continue; }
                if(line[i] == ' ' && line[i-1] == ',') continue;
                nome.push_back(line[i]);
                if(i == sz-2) if(nome != "") autores.push_back(nome);
            }
            for(auto a : autores)
                for(auto b : autores){
                    if(a != b) adj[a].push_back(b);
                    dist[b] = INF;
                    todos.push_back(b);
                }   
        }
        bfs();
        cout << "Teste " << tc++ << '\n';
        sort(todos.begin(), todos.end(), cmp);
        todos.erase(unique(todos.begin(), todos.end()), todos.end());
        for(auto autor : todos){
            if(autor == paul) continue;
            cout << autor << ": ";
            if(dist[autor] != INF) cout << dist[autor];
            else cout << "infinito";
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}