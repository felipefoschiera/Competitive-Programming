#include <iostream>
using namespace std;

int L[101010], R[101010];


int main(){
    int S, B;
    while(cin >> S >> B, S+B){
        int l, r;
        for(int i = 1; i <= S; i++){
            L[i] = i-1;
            R[i] = i+1;
        }
        L[1] = 0;
        R[S] = 0;
        while(B--){
            cin >> l >> r;
            L[R[r]] = L[l];
            R[L[l]] = R[r];
            if(L[l] != 0) cout << L[l];
            else cout << "*";
            cout << " ";
            if(R[r] != 0) cout << R[r];
            else cout << "*";
            cout << '\n';
        }
        cout << "-\n";
    }
    return 0;
}