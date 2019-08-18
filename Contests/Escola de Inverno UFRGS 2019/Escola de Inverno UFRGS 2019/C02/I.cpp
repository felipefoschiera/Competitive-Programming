#include <iostream>
using namespace std;

const int MAXN = 1001000;

int pd[MAXN][2];

int main(){
    string s;
    cin >> s;
    pd[0][0] = 10 - (s[0] - '0') + 1;
    pd[0][1] = s[0] - '0';
    int m = s.size();

    for(int i = 1; i < m; i++){
        pd[i][0] = 10 - (s[i] - '0') + min(pd[i-1][0] - 1, pd[i-1][1] + 1);
        pd[i][1] = s[i] - '0' + min(pd[i-1][0], pd[i-1][1]);
    }
    int res = min(pd[m-1][0], pd[m-1][1]);
    cout << res << '\n';
    return 0;
}