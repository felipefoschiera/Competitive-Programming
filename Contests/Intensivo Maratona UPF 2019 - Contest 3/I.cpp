#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        bool ok = true;
        int m = s.size();
        if(m < 6 || m > 32){
            ok = false;
        }
        bool maiscula = false, minuscula = false, numero = false;
        for(char c : s){
            if(!isalnum(c)) ok = false;
            if(isupper(c)) maiscula = true;
            if(islower(c)) minuscula = true;
            if(isdigit(c)) numero = true;
        }
        if(!maiscula || !minuscula || !numero) ok = false;
        cout << (ok ? "Senha valida." : "Senha invalida.") << '\n';
    }
    return 0;
}