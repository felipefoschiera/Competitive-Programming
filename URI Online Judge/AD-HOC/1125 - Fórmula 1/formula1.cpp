#include <cstdio>

int main(){
	int G, P;
	while(scanf("%d%d", &G, &P), G+P){
		int posicoes[P][G];
		for(int i = 0; i < G; i++){
			for(int j = 0; j < P; j++){
				scanf("%d", &posicoes[j][i]);
			}
		}
		int S;
		scanf("%d", &S);
		while(S--){
			int K;
			scanf("%d", &K);
			int pontos[K], pontuacao[P];
			for(int i = 0; i < P; i++) pontuacao[i] = 0;
			for(int i = 0; i < K; i++) scanf("%d", &pontos[i]);
			int maxi = 0, count = 0;
			for(int i = 0; i < P; i++){
				for(int j = 0; j < G; j++){
					int colocacao = posicoes[i][j];
					if(colocacao <= K) pontuacao[i] += pontos[--colocacao];
					if(pontuacao[i] > maxi) maxi = pontuacao[i];
				}
			}
			for(int i = 0; i < P; i++) if(pontuacao[i] == maxi) count++;
			for(int i = 0; i < P; i++){
				if(pontuacao[i] == maxi) printf("%d%c", i+1, (--count == 0) ? '\n' : ' ');
			}
		}
	}
	return 0;
}