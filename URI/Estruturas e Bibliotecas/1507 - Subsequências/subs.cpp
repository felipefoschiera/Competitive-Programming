// Felipe G. Foschiera
// URI 1507 - Subsequências
#include <bits/stdc++.h>
using namespace std;

bool subs(string ped, string seq){
    int ind = 0;
    for(int i = 0; i < seq.length(); i++){
        if(seq[i] == ped[ind]){
            ind++;
            if(ind == ped.length()){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    while(n--){
        string seq;
        int q;
        cin >> seq >> q;
        while(q--){
            string ped;
            cin >> ped;
            if(subs(ped, seq)){
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }
        }
    }
    return 0;
}