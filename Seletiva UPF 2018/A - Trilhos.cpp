#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

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
					pilha.pop();
					ind++;
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