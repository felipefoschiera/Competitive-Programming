#include <cstdio>

int main(){
	int n;
	bool ok = true;
	while(scanf("%d", &n) != EOF){
		if(n == 42) ok = false;
		if(ok) printf("%d\n", n);
	}
	return 0;
}