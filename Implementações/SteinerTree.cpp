#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

typedef vector<vector<double>> matrix;
int n, k;
matrix g;
vector<int> T;

const double INF = 1e20;
const double eps = 1e-9;

const int MAX = 101;
const int MAXK = 10;

int x[MAX], y[MAX];

double menor(double a, double b){
	return a+eps < b+eps ? a : b;
}

double dist(int i, int j){
	return hypot(x[i]-x[j], y[i]-y[j]);
}

double minimum_steiner_tree(){
	int numT = T.size();
	if(numT <= 1) return 0;
	matrix d(g);
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				d[i][j] = menor(d[i][j], d[i][k] + d[k][j]);

	double OPT[1 << MAXK][MAX];
	
	for(int S = 0; S < (1 << numT); S++)
		for(int x = 0; x < n; x++)
			OPT[S][x] = INF;

	for(int p = 0; p < numT; p++)
		for(int q = 0; q < n; q++)
			OPT[1<<p][q] = d[T[p]][q];	

	for(int S = 1; S < (1 << numT); S++){
		if(!(S & (S-1))) continue;
		for(int p = 0; p < n; p++)
			for(int E = 0; E < S; E++)
				if((E | S) == S)
					OPT[S][p] = menor(OPT[S][p], OPT[E][p] + OPT[S-E][p]);
		for(int p = 0; p < n; p++)
			for(int q = 0; q < n; q++)
				OPT[S][p] = menor(OPT[S][p], OPT[S][q] + d[p][q]);
	}
	double ans = INF;
	for(int S = 0; S < (1 << numT); S++)
		for(int q = 0; q < n; q++)
			ans = menor(ans, OPT[S][q] + OPT[((1 << numT)-1)-S][q]);
	return ans;
	
}

int main(){
	scanf("%d %d", &n, &k);
	g = matrix(n, vector<double>(n, INF));
	for(int i = 0; i < n; i++){
		scanf("%d %d", &x[i], &y[i]);
		if(i < k) T.push_back(i);
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			g[i][j] = dist(i, j);
	}
	for(int i = 0; i < k;  i++)
		for(int j = 0; j < k; j++)
			g[i][j] = INF;

	printf("%.5lf\n", minimum_steiner_tree());

	return 0;
}