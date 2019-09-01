#include <bits/stdc++.h>
using namespace std;

int main(){
    int cur, boi, boto, mapin, iara;
    cin >> cur >> boi >> boto >> mapin >> iara;
    int res = 225 + 300*cur + 1500*boi + 600*boto + 1000*mapin + iara*150;
    cout << res << '\n';
    return 0;
}