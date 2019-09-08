#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mat[1010][1010];
ll somaD[2050];
map<int, int> freq[2050];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    int tipo, cont = 1;
    int k, s, x, y;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            mat[i][j] = cont;
            int d = i+j-1;
            somaD[d] += cont;
            freq[d][cont]++;
            cont++;
        }
    }
    while(q--){
        cin >> tipo;
        if(tipo == 1){
            cin >> k;
            cout << somaD[k] << '\n';
        }else if(tipo == 2){
            cin >> k;
            cout << freq[k].size() << '\n';
        }else {
            cin >> s >> x >> y;
            int d = x+y-1;  
            somaD[d] -= mat[x][y];
            auto it = freq[d].find(mat[x][y]);
            if(it != freq[d].end()){
                freq[d][mat[x][y]]--;
                if(freq[d][mat[x][y]] == 0){
                    freq[d].erase(it);
                }
            }
            mat[x][y] += s;
            somaD[d] += mat[x][y];
            freq[d][mat[x][y]]++;
        }
    }
    return 0;
}