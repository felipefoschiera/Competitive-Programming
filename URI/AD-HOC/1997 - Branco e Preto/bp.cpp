/**
 *  URI 1997 - Branco e Preto
 *  Felipe G. Foschiera - UPF
 */
#include <iostream>
using namespace std;

int main(){
    string a, b;
    while(cin >> a >> b){
        if(a == "*" && b == "*") break;
        int count = 0;
        if(a != b){
            int curr = 0;        
            for(int i = 0; i < a.length(); i++){
                if(a[i] != b[i])
                    count += (i == a.length()-1 ? 1 : 0), curr++;
                else count += (curr > 0 ? 1 : 0), curr = 0;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
