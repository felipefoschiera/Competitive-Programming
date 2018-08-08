#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    while(N--){
        string a, b;
        cin >> a >> b;
        string res = "";
        int i = 0, j = 0;
        int asz = a.length(), bsz = b.length();
        while(i < asz || j < bsz){
            if(i < asz) res += a[i];
            if(j < bsz) res += b[j];
            i++, j++;
        }
        cout << res << '\n';
    }
    return 0;
}