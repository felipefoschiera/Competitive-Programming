#include <stdio.h>
using namespace std;

int main(){
	int L, C;
	scanf("%d", &L);
	scanf("%d", &C);
	printf("%d\n", C*L + ((C-1)*(L-1)));
	printf("%d\n", (C-1)*2 + (L-1)*2);

	return 0;
}