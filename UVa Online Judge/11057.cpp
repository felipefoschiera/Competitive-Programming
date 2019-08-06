#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int v[n];
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v, v+n);
        int m; cin >> m;
        int a1, a2, diff = 1e9;
        for(int i = 0; i < n; i++){
            int other = abs(m-v[i]);
            int d = abs(other-v[i]);
            if(binary_search(v, v+n, other) && d < diff){
                diff = d;
                a1 = v[i];
                a2 = other;
            } 
        }
        cout << "Peter should buy books whose prices are " << a1 << " and " << a2 << ".\n\n";
    }
    return 0;
}