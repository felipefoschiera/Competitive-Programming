/**
 *  URI 1956 - Acácias
 *  Felipe G. Foschiera
 */
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> aresta;


int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

vector<int> pai, ranking;

int findSet(int x){
    return (pai[x] == x) ? x : pai[x] = findSet(pai[x]);
}

bool isSameSet(int x, int y){
    return findSet(x) == findSet(y);
}

void unionSet(int x, int y){
    if(!isSameSet(x, y)){
        int a = findSet(x), b = findSet(y);
        if(ranking[a] > ranking[b]){
            pai[b] = a;
        }else{
            pai[a] = b;
            if(ranking[a] == ranking[b]) ranking[b]++;
        }
    }
}

void kruskal(vector<aresta> arestas, int n){
    ll cost = 0;
    int count = n;
    for(auto e : arestas){
        if(!isSameSet(e.second.first, e.second.second)){
            unionSet(e.second.first, e.second.second);
            cost += e.first;
            count--;
        }
    }
    printf("%d %lld\n", count, cost);
}

int main(){
    int n = readInt();
    vector<aresta> arestas;
    ranking.assign(n+1, 0);
    pai.assign(n+1, 0);
    for(int i = 0; i < n; i++) pai[i] = i;
    for(int i = 1; i < n; i++){
        int k = readInt();
        int a, b;
        for(int j = 0; j < k; j++){
            a = readInt();
            b = readInt();
            arestas.push_back(aresta(b, ii(a, i)));
        }
    }
    sort(arestas.begin(), arestas.end());
    kruskal(arestas, n);

    return 0;
}