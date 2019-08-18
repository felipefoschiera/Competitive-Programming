#include <bits/stdc++.h>
using namespace std;
#define MAX 1123
#define LEN 112

int N;
char m[MAX][MAX], t[MAX][MAX];
const char rot[5] = "^>v<";
map<char, int> pos;

void printMat(char mat[MAX][MAX]){
    for(int i = 0; i < N; i++){
        printf("%s\n", mat[i]);
    }
}

char rotate(char c, int r){
    return (c == '.') ? c : rot[(pos[c] + r) % 4];
}

void printUp(){
    printMat(m);
}

void printRight(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            t[j][N-1-i] = rotate(m[i][j], 1);
        }
        t[i][N] = '\0';
    }
    printMat(t);
}

void printDown(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            t[N-1-i][N-1-j] = rotate(m[i][j], 2);
        }
        t[i][N] = '\0';
    }
    printMat(t);
}

void printLeft(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            t[N-1-j][i] = rotate(m[i][j], 3);
        }
        t[i][N] = '\0';
    }
    printMat(t);
}

int main(){
    int i, L, R, D;
    char s[LEN];
    for(i = 0; i < 4; i++){
        pos[rot[i]] = i;
    }
    while(scanf("%d %s", &N, s) != EOF){
        for(i = 0; i < N; i++){
            scanf(" %s", m[i]); 
        }
        L = R = 0;
        for(i = 0; s[i]; i++){
            if(s[i] == 'L') L++;
            if(s[i] == 'R') R++;
        }
        D = R - L;
        D = (D + 100) % 4; // is this right?
        if(D == 0) printUp();
        if(D == 1) printRight();
        if(D == 2) printDown();
        if(D == 3) printLeft();
    }
    return 0;
}
