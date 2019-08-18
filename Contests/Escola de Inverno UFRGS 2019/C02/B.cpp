#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        int diff = n-k;
        if(diff > 1){
            cout << "Kilani\n"; 
        }else{
            cout << (n%2==1 ? "Kilani" : "Ayoub") << '\n';
        }
    }
    return 0;
}
