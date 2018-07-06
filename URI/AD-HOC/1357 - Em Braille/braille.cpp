#include <iostream>
#include <map>
using namespace std;

struct cb {
    string valor[2];
    bool operator == (const cb &o){
        return valor[0] == o.valor[0] && valor[1] == o.valor[1];
    }
};

map<int, cb> toBraile;
cb braile[10];

void start(){
    braile[0] = {".*", "**"};
    braile[1] = {"*.", ".."};
    braile[2] = {"*.", "*."};
    braile[3] = {"**", ".."};
    braile[4] = {"**", ".*"};
    braile[5] = {"*.", ".*"};
    braile[6] = {"**", "*."};
    braile[7] = {"**", "**"};
    braile[8] = {"*.", "**"};
    braile[9] = {".*", "*."};
    for(int i = 0; i < 10; i++) toBraile[i] = braile[i];
    
}

int equiv(cb br){
    for(int i = 0; i < 10; i++)
        if(braile[i] == br) return i;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    start();
    int N;
    while(cin >> N && (N)){
        char c;
        cin >> c;
        if(c == 'S'){
            string num;
            cin >> num;
            for(int i = 0; i < N; i++) cout << toBraile[num[i] - '0'].valor[0] << (i == N-1 ? "\n" : " ");
            for(int i = 0; i < N; i++) cout << toBraile[num[i] - '0'].valor[1] << (i == N-1 ? "\n" : " ");
            for(int i = 0; i < N; i++) cout << ".." << (i == N-1 ? "\n" : " ");
        }else if(c == 'B'){
            cb brailes[N];
            string blank;
            for(int i = 0; i < N; i++) cin >> brailes[i].valor[0];
            for(int i = 0; i < N; i++) cin >> brailes[i].valor[1];
            for(int i = 0; i < N; i++) cin >> blank;
            for(int i = 0; i < N; i++) cout << equiv(brailes[i]);
            cout << endl;
        }
    }
    return 0;
}