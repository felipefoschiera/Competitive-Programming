#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int v[n];
    for(int i = 0; i < n;  i++)
        cin >> v[i];
    sort(v, v+n);
    int c = 0;
    for(int i = n-1; i >= 0; i--){
        c++;
        if(c == k){
            for(int j = i-1; j >= 0; j--){
                if(v[i] == v[j]){
                    c++;
                }else break;
            }
            break;
        }
    }
    cout << c << '\n';
    return 0;
}