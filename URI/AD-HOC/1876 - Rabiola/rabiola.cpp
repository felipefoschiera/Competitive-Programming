/**
 *  URI 1876 - Rabiola
 *  Felipe G. Foschiera - UPF
 */
#include <iostream>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while(cin >> s){
        int best = 0, sep = 0, count = 0;
        int sz = s.length();
        for(int i = 0; i < sz; i++)
            if(s[i] == 'x') sep++;
        int sep_atual = 0;
        for(int i = 0; i < sz; i++){
            if(s[i] == 'o'){
                count++; 
                if(i == sz - 1){
                    best = max(best, count);
                }
            }else if(s[i] == 'x'){
                if(sep_atual == 0 || sep_atual == sep){
                    best = max(best, count);
                }else{ best = max(best, count/2); }
                count = 0;
                sep_atual++;
            }
        }
        cout << best << endl;
    }
    // oxooooxo
    return 0;
}