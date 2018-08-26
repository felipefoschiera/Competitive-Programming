// URI 1880 - Renzo e a Decoração Capicuânica
// Felipe G. Foschiera
#include <iostream>
using namespace std;

char valor(int n){
    return (n < 10) ? n + '0' : n + 'A';
}

bool ehCapicua(int N, int base){
    string res;
    while(N > 0){
        res.push_back(valor(N % base));
        N /= base;
    }
    string rev = string(res.rbegin(), res.rend());
    return res == rev;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        bool ok = false;
        for(int i = 2; i <= 16; i++){
            if(ehCapicua(N, i)){
                if(ok) cout << " ";
                cout << i;
                ok = true;
            }
        }
        if(!ok) cout << "-1";
        cout << '\n';
    }
    return 0;
}