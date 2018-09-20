#include <cstdio>

int main(){
	int n, cnt;
	while(scanf("%d", &n) != EOF){
		cnt = 0;
		while(n--){
			int v;
			scanf("%d", &v);
			cnt += v != 1;
		}
		printf("%d\n", cnt);
	}
	return 0;
}