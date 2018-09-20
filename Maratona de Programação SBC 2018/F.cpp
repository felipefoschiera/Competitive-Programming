#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define fs first
#define sc second
#define MAX 11
#define MAXM 1123
#define INF ((int)1e9)
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> show;

int N, cont;
vector<show> shows;
int pd[MAXM][1 << MAX];
vector<int> to;

int solve(int show, int bitmask){
	if(show == cont){
		if(__builtin_popcount(bitmask) == N) return 0;
		return -INF;
	}
	if(pd[show][bitmask] != -1) return pd[show][bitmask];
	int res = max(solve(show+1, bitmask), shows[show].sc.fs + solve(to[show], bitmask | (1 << shows[show].sc.sc)));
	return pd[show][bitmask] = res;
}

int main(){
	while(scanf("%d", &N) != EOF){
		cont = 0;
		shows.clear();
		for(int i = 0; i < N; i++){
			int m, in, fim, val;
			scanf("%d", &m);
			for(int j = 0; j < m; j++){
				scanf("%d %d %d", &in, &fim, &val);
				shows.push_back({{in, fim}, {val, i}});
				cont++;
			}
		}
		to.assign(cont, cont);
		sort(shows.begin(), shows.end());
		for(int i = 0; i < cont; i++){
			for(int j = i; j < cont; j++){
				if(shows[i].first.second <= shows[j].first.first){
					to[i] = j;
					break;
				}
			}
		}
		memset(pd, -1, sizeof pd);
		int res = solve(0, 0);
		printf("%d\n", res >= 0 ? res : -1);
	}
	return 0;
}