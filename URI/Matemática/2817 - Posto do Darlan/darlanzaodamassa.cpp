#include <stdio.h>
#include <vector>
#define MAX 1012
using namespace std;

typedef pair<int, pair<int, int>> seq;

seq somas[MAX][MAX];

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    short mat[N][M];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            char c; scanf(" %c", &c);
            if(c == 'M') mat[i][j] = 12;
            else if(c == 'C') mat[i][j] = 25;
        }

    int L;
    scanf("%d", &L);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < L; j++){
            somas[i][0].first += mat[i][j];
            if(mat[i][j] == 12) somas[i][0].second.second++;
            if(mat[i][j] == 25) somas[i][0].second.first++;
        }
        for(int j = 1; j <= M - L; j++) {
            somas[i][j].first = somas[i][j-1].first - mat[i][j-1] + mat[i][j+L-1];
            somas[i][j].second = somas[i][j-1].second;
            if(mat[i][j-1] == 12) somas[i][j].second.second--;
            if(mat[i][j+L-1] == 12) somas[i][j].second.second++;
            if(mat[i][j-1] == 25) somas[i][j].second.first--;
            if(mat[i][j+L-1] == 25) somas[i][j].second.first++;
        }
    }

    int max_sum = -1;
    for(int i = 0; i <= N - L; i++){
        for(int j = 0; j <= M-L; j++){
            int soma = somas[i][j].first;
            int mot = somas[i][j].second.second;
            int cars = somas[i][j].second.first;
            for(int k = 1; k < L; k++){
                soma += somas[i+k][j].first;
                mot += somas[i+k][j].second.second;
                cars += somas[i+k][j].second.first;
            }
            if(soma > max_sum && mot > 0 && cars > 0){
                max_sum = soma;
            }
        }
    }
    printf("%d\n", max_sum);
        
    
    return 0;
}