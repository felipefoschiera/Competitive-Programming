#include <cstdio>
#define MAX 112

int N, M, S;
char mat[MAX][MAX];

bool ehValido(int i, int j){
	return i >= 0 && i < N && j >= 0 && j < M && (mat[i][j] == '.' || mat[i][j] == '*');
}

int main(){
	while(scanf("%d%d%d", &N, &M, &S), N+M+S){
		char inst, direcao, y, x;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++){
				scanf(" %c", &mat[i][j]);
				if(mat[i][j] == 'N' || mat[i][j] == 'S' || mat[i][j] == 'L' || mat[i][j] == 'O'){
					direcao = mat[i][j];
					y = i, x = j;
				}
			}
		int count = 0;
		mat[y][x] = '.';
		while(S--){
			scanf(" %c", &inst);
			if(inst == 'D'){
				if(direcao == 'N') direcao = 'L';
				else if(direcao == 'O') direcao = 'N';
				else if(direcao == 'S') direcao = 'O';
				else if(direcao == 'L') direcao = 'S';
			}else if(inst == 'E'){
				if(direcao == 'N') direcao = 'O';
				else if(direcao == 'L') direcao = 'N';
				else if(direcao == 'S') direcao = 'L';
				else if(direcao == 'O') direcao = 'S';
			}else if(inst == 'F'){
				if(direcao == 'N' && ehValido(y-1, x)) y--; 
				if(direcao == 'L' && ehValido(y, x+1)) x++;
				if(direcao == 'O' && ehValido(y, x-1)) x--;
				if(direcao == 'S' && ehValido(y+1, x)) y++;
				if(mat[y][x] == '*') { mat[y][x] = '.'; count++; }
			}
		}
		printf("%d\n", count);
	}
	return 0;
}