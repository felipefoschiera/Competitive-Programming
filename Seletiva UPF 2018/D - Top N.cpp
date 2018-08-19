#include <cstdio>

int main(){
	int N;
	while(scanf("%d", &N) != EOF){
		int tp = 0;
		if(N == 1) tp = 1;
		else if(N <= 3) tp = 3;
		else if(N <= 5) tp = 5;
		else if(N <= 10) tp = 10;
		else if(N <= 25) tp = 25;
		else if(N <= 50) tp = 50;
		else tp = 100;
		printf("Top %d\n", tp);
	}
	return 0;
}