#include <cstdio>
#define MAX 112

int preco[MAX];

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int D, I, B;
		scanf("%d%d%d", &D, &I, &B);
		for(int i = 0; i < I; i++) scanf("%d", &preco[i]);
		int best_quant = 0;

		for(int i = 0; i < B; i++){
			int qt;
			scanf("%d", &qt);
			int preco_bolo = 0;
			while(qt--){
				int ing, quant;
				scanf("%d %d", &ing, &quant);
				preco_bolo += quant * preco[ing];
			}
			int pode = D / preco_bolo;
			if(pode > best_quant) best_quant = pode;
		}
		printf("%d\n", best_quant);
	}
	return 0;
}