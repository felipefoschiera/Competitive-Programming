// URI 2646 - Secret Chamber at Mount Rushmore
// Felipe G. Foschiera
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 55;
char adj[26][26];
bool visited[26];

bool encontra(char origem, char dest){
    memset(visited, false, sizeof visited);
    queue<int> fila;
    fila.push(origem - 'a'); 
    while(!fila.empty()){
        int u = fila.front();
        fila.pop();
        if(visited[u]) continue;
        visited[u] = true; 
        if(u == dest - 'a') return true;
        for(int i = 0; i < 26; i++){
            if(i != u && adj[u][i])
                fila.push(i);
        }
    }
    return false;
}

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    char a, b;
    while(m--){
        scanf(" %c %c", &a, &b);
        adj[a-'a'][b-'a'] = 1;
    }
    char fst[MAX], scd[MAX];
    while(n--){
        bool ok = true;
        scanf(" %s %s", fst, scd);
        if(strlen(fst) == strlen(scd)){
            for(int i = 0; fst[i]; i++)
                if(!encontra(fst[i], scd[i])) { ok = false; break; }
        }else ok = false;
        printf("%s\n", ok ? "yes" : "no");
    }
    return 0;
}