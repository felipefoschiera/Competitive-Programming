#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, l;
    int v[3];
    cin >> v[0] >> v[1] >> v[2];
    cin >> h >> l;
    sort(v, v+3);
    if((v[0] <= h && v[1] <= l) || (v[0] <= l && v[1] <= h)){
        cout << "S\n";
    }else cout << "N\n";


    return 0;
}