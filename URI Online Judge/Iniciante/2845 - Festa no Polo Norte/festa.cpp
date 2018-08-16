#include <cstdio>

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		int maior = 0, v;
		for(int i = 0; i < n; i++){
			scanf("%d", &v);
			if(v > maior) maior = v;
		}
		printf("%d\n", maior+1);
	}
	return 0;
}