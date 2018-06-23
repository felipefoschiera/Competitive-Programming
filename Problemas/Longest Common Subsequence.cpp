#include <iostream>
using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}

int LCS(string a, string b, int m, int n){
    int L[m+1][n+1];
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0)
                L[i][j] = 0;
            else if(a[i-1] == b[j-1]){
                L[i][j] = L[i-1][j-1] + 1;
            }else L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    return L[m][n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    cout << LCS(a, b, a.length(), b.length()) << endl;
    return 0;
}