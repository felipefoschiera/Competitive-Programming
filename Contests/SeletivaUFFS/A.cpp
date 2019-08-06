#include <iostream>
using namespace std;

int main(){
    int v;
    int cnt[7];
    for(int i = 0; i < 4; i++) cnt[i] = 0;
    for(int i = 0; i < 6; i++){
        cin >> v;
        cnt[v]++;
    }
    int opcao1 = 0;
    if(cnt[1] >= 3){
        opcao1++;
    }
    cnt[1] -= 3;
    if(cnt[1] > 0) opcao1 += cnt[1];
    int opcao2 = 0;
    if(cnt[2] >= 3){
        opcao2 += 2;
    }
    cnt[2] -= 3;
    if(cnt[2] > 0){
        opcao2 += cnt[2];
    }
    int opcao3 = 0;
    if(cnt[3] >= 3){
        opcao3 += 3;
    }
    cnt[3] -= 3;
    if(cnt[3] > 0){
        opcao3 += cnt[3];
    }
    cout << (max(opcao1, max(opcao2, opcao3))) << '\n';
    return 0;
}