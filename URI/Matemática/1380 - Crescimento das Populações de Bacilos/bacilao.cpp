/**
 *  URI 1380 - Crescimento das Populações de Bacilos
 *  Felipe G. Foschiera
 */
#include <iostream>
#include <iomanip>
#define MAX 1512
using namespace std;


int f[MAX];

int fib(int n){
    if(n == 0) return 0;
    if(n <= 2){
        f[n] = 1;
        return 1;
    }
    if(f[n]) return f[n];
    return f[n] = (fib(n-1) + fib(n-2)) % 1000;
}

int mod(string num, int a){
    int res = 0;
    for(int i = 0; i < num.length(); i++){
        res = (res*10 + (int)num[i] - '0') % a;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    string n;
    while(T--){
        cin >> n;
        int num = mod(n, 1500);
        cout << setfill('0') << setw(3) << fib(num) % 1000 << endl;
    }
    return 0;
}