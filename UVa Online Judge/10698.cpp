#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;


int main(){
    int t; cin >> t;
    while(t--){
        ll a, b, n, m;
        cin >> a >> b >> n >> m;

        int mod, pisano;
        if(m==1){
            pisano = 60;
            mod = 10;
        }else if(m == 2){
            pisano = 300;
            mod = 100;
        }else if(m == 3){
            pisano = 1500;
            mod = 1000;
        }else {
            pisano = 15000;
            mod = 10000;
        }
        ll seq[pisano+1];
        seq[0] = a%mod;
        seq[1] = b%mod;
        for(int i = 2; i < pisano; i++)
            seq[i] = (seq[i-1] + seq[i-2]) % mod;
        cout << seq[n%pisano] << "\n";
        
    }
    return 0;
}