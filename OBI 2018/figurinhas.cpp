#include <stdio.h>
#include <string.h>
#define MAX 112

int main(){
	int N, C, M;
	scanf("%d %d %d", &N, &C, &M);

	int carimbadas[MAX];
	memset(carimbadas, 0, sizeof(carimbadas));
	int s;
	for(int i = 0; i < C; i++){
		scanf("%d", &s);
		carimbadas[s] = 1;
	}
	int faltam = C;
	int v;
	for(int i = 0; i < M; i++){
		scanf("%d", &v);
		if(carimbadas[v] == 1){
			faltam--;
			carimbadas[v] = 0;
		}
	}
	printf("%d\n", faltam);	
	return 0;
}
