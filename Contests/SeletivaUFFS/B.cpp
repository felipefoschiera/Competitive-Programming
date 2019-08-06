#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int cnt[1010101];

int main(){
    int n, v;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v;
        cnt[v]++;
    }
    int maior = 0, segundo = 0;
    for(int i = 1; i <= n; i++){
        if(cnt[i] > cnt[maior]) maior = i;
    }
    for(int i = 1; i <= n; i++){
        if(i != maior && cnt[i] > cnt[segundo]){
            segundo = i;
        }
    }
    if(segundo == 0){
        if(maior == n) segundo = n-1;
        if(n-1 == 0) segundo = 1;
        else segundo = n;
    }
    cout << maior << ' ' << segundo << '\n';

    return 0;
}