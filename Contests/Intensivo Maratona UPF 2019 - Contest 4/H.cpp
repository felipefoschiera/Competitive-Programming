#include <bits/stdc++.h>
using namespace std;

int a[512][512];
int b[512][512];

void solve(int mat[512][512], int n){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(mat[i][j] == 1) mat[i][j] = 0;
			else {
				mat[i][j] = 1 + min(mat[i-1][j], min(mat[i][j-1], mat[i-1][j-1]));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, p;
	cin >> n >> p;
	int x, y;
	for(int i = 0; i < p; i++){
		cin >> x >> y;
		a[x][y]++; 
	}
	for(int i = 0; i < p; i++){
		cin >> x >> y;
		b[x][y]++; 
	}
	solve(a, n);
	solve(b, n);
	int r1 = 0, r2 = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			r1 += max(0, b[i][j] - a[i][j]);
			r2 += max(0, a[i][j] - b[i][j]);
		}
	}
	cout << r1 << ' ' << r2 << '\n';
	return 0;
}