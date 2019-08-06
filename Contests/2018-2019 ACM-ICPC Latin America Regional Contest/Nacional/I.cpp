#include <cstdio>
#include <vector>
#include <set>
using namespace std;

const int MAX = 101010;

vector<int> adj[MAX];
int parent[MAX], level[MAX], filhos[MAX];

void dfs(int u){
    for(auto v : adj[u]){
        if(v != parent[u]){
            level[v] = level[u] + 1;
            dfs(v);
        }
    }
}

typedef pair<int, int> ii;

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 2; i <= N; i++){
        scanf("%d", &parent[i]);
        adj[i].push_back(parent[i]);
        adj[parent[i]].push_back(i);
        filhos[parent[i]]++;
    }
    level[1] = 0;
    dfs(1);
    set<ii> st;
    for(int i = 2; i <= N; i++){
        st.insert({-level[i], i});
    }
    int root = 1, res = 0;
    while(!st.empty()){
        ii vert = *st.begin();
        // tira o elemento mais abaixo a ser analisado
        st.erase(st.begin());
        int u = vert.second, pai = parent[u];
        ii paist = {-level[pai], pai};
        // se ele é o centro de um stick man, ou seja, tem ao menos 2 filhos e seu pai tem ao menos 3 filhos
        // e seu pai não é a raiz, pois deve ter uma aresta mais acima
        // se seu pai ainda não foi utilizado, remove o pai do set e incrementa a resposta
        // diminui a quantidade de filhos do pai do pai, pois não dá mais para usar esse caminho 
        if(filhos[u] > 1 && filhos[pai] > 2 && pai != root){
            if(st.find(paist) != st.end()){
                st.erase(paist);
                res++;
                filhos[parent[pai]]--;
            }
        }
    }
    printf("%d\n", res);
    return 0;
}