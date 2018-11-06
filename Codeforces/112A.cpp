#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    while(cin >> a >> b){
        for(int i = 0; i < a.length(); i++){
            a[i] = tolower(a[i]);
            b[i] = tolower(b[i]);
        }
        cout << (a < b ? -1 : a == b ? 0 : 1) << '\n';
    }
    return 0;
} 