#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

/**
 * 	Para saber se podemos retirar os vagões como desejado, vamos empilhando os vagões
 * 	na ordem de chegada, a partir de 1, e quando o vagão que chegou é o próximo a sair
 * 	segundo a ordem da entrada, retiramos ele e avançamos para o próximo que se deseja retirar,
 * 	retirando-o enquanto ele for o do topo da pilha.
 */	
int main(){
	int N;
	while(scanf("%d", &N), N){
		bool end = false;
		while(1){
			int v[N];
			int x;
			for(int i = 0; i < N; i++){
				scanf("%d", &x);
				if(x == 0) { end = true; break; }
				v[i] = x;
			}
			if(end) break;
			stack<int> pilha;
			int ind = 0;
			for(int i = 1; i <= N; i++){
				pilha.push(i);
				if(v[ind] == pilha.top()){
					while(!pilha.empty() && pilha.top() == v[ind]){
						pilha.pop();
						ind++;
					}
				}
			}

			printf("%s\n", pilha.empty() ? "Yes" : "No");
	
		}
		printf("\n");
	}

	return 0;
}