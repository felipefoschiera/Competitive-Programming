/**
 *  URI 2724 - Ajude Patatatitu
 *  Felipe G. Foschiera - UPF
 */
#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    while(N--){
        int T;
        cin >> T;
        string perigosos[T];
        for(int i = 0; i < T; i++) cin >> perigosos[i];
        int U;
        cin >> U;
        for(int i = 0; i < U; i++){
            string el;
            cin >> el;
            bool ok = true;
            int ind = 0;
            for(auto p : perigosos){
                for(int j = 0; j < el.length(); j++){
                    if(ind > 0 && el[j] != p[ind]) ind = 0;
                    if(el[j] == p[ind]) ind++;
                    if(ind == p.length()) {
                        if(ind == el.length() || ((!islower(el[j+1])) && (!isdigit(el[j+1]))))
                            ok = false;
                        break;
                    }
                }
                if(!ok) break;
            }
            printf(ok ? "Prossiga\n" : "Abortar\n");
        }
        if(N != 0) printf("\n");
    }
    return 0;
}