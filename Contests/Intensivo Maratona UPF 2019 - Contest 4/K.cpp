#include <bits/stdc++.h>
using namespace std;

int v[100100];
int soma[100100];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> v[i];
	soma[0] = v[0];
	for(int i = 1; i < n; i++) soma[i] = v[i] + soma[i-1];
	for(int i = 0; i < n; i++){
		if(soma[i] == soma[n-1] - soma[i]){
			cout << i+1 << '\n';
			break;
		}
	}
	return 0;
}