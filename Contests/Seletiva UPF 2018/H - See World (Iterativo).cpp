#include <cstdio>
#include <queue>
#define MAX 1123
using namespace std;

int N;
int mat[MAX][MAX];
int color[MAX];

bool ehBipartido(){
    for(int i = 0; i < N; i++) color[i] = -1;
    int s = 0;

    queue<int> q;
    q.push(s);
    color[s] = 0;
    while (!q.empty()) {
        int u = q.front(); 
        q.pop();
        for (int v = 0; v < N; v++) {
            if(mat[u][v] == 0){
                if(color[v] == -1){
                    color[v] = 1 - color[u];
                    q.push(v);
                }else if(color[v] == color[u]) return false;
            }
        }
    }
    return true;
}

int main(){ 
    while(scanf("%d", &N) != EOF){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                scanf("%d", &mat[i][j]);
    printf("%s!\n", ehBipartido() ? "Bazinga" : "Fail");
    }

    return 0;
}