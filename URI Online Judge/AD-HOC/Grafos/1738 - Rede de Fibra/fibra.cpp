#include <iostream>
#include <cstring>
#define MAX 212
using namespace std;


int mat[MAX][MAX];

void floydWarshall(int N){
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                mat[i][j] |= mat[i][k] & mat[k][j];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while(cin >> N, N){
        memset(mat, 0, sizeof mat);
        int a, b;
        string s;
        while(cin >> a >> b, a+b){
            cin >> s;
            for(auto c : s){
                mat[a][b] |= (1 << (c - 'a'));
            }
        }
        floydWarshall(N+1);
        while(cin >> a >> b, a+b){
            bool ok = false;
            for(int i = 0; i < 26; i++){
                if(mat[a][b] & (1 << i)){
                    cout << (char)(i + 'a');
                    ok = true;
                }
            }
            if(!ok) cout << "-";
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}