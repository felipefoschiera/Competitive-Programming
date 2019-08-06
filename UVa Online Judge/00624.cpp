#include <iostream>
using namespace std;

int s, n;
int v[25];
int best, maskres;

void solve(int sum, int mask, int idx){
    if(sum > best){
        best = sum;
        maskres = mask;
    }
    if(idx >= n) return;
    solve(sum, mask, idx+1);
    if(sum+v[idx] <= s)
        solve(sum+v[idx], mask | (1 << idx), idx+1);
}

int main(){
    while(cin >> s >> n){
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        best = -1;
        maskres = 0;
        solve(0, 0, 0);
        for(int i = 0; i < n; i++){
            if(maskres & (1 << i)){
                cout << v[i] << " ";
            }
        }
        cout << "sum:" << best << "\n";
    }
    return 0;
}