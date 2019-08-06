// URI 2915 / Maratona SBC 2018 - Mounth Marathon
// Felipe G. Foschiera
#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int cnt = 1;
	int v[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	for(int i = 1; i < n; i++){
		cnt += (v[i] > v[i-1]);
	}
	printf("%d\n", cnt);
	return 0;
}