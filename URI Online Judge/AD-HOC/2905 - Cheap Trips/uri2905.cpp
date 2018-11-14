// URI 2905 / Maratona SBC 2018 - Cheap Trips
// Felipe G. Foschiera
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10101;
const int MAXT = 131;
const int MAXA = 7;

double pd[MAXN][MAXA];

struct trip {
	int time;
	int cost;
};

int N;
trip trips[MAXN];

double solve(int trip, int curtime, int acum){
	if(pd[trip][acum] != -1.0)
		return pd[trip][acum];
	if(trip == N) return 0.0;
	double res = 0.0;
	if(acum == 0) res += trips[trip].cost;
	else if(acum == 1) res += trips[trip].cost * 0.50;
	else res += trips[trip].cost * 0.25;
	if(curtime < 120 && acum+1 <= 5){
		res += min(solve(trip+1, min(curtime+trips[trip+1].time, 120), acum+1),
				   solve(trip+1, min(trips[trip+1].time, 120), 0));
	}else res += solve(trip+1, min(trips[trip+1].time, 120), 0);
	return pd[trip][acum] = res;
}

int main(){
	while(scanf("%d", &N) != EOF){
		for(int i = 0; i < N; i++){
			scanf("%d %d", &trips[i].time, &trips[i].cost);			
		}
		for(int i = 0; i < MAXN; i++)
				for(int a = 0; a < 7; a++)
						pd[i][a] = -1.0;
		printf("%.2lf\n", solve(0, min(trips[0].time, 120), 0));
	}
	return 0;
}