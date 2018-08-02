/**
 *  URI 2017 - Seis Strings
 *  Felipe G. Foschiera
 */
#include <iostream>
using namespace std;

int hamming(string a, string b){
    int count = 0;
    for(int i = 0; i < a.length(); i++){
        if(a[i] != b[i]) count++;
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    int k; cin >> k;
    string v;
    int best_dist = 11234567;
    int best_ind;
    for(int i = 0 ; i < 5; i++){
        cin >> v;
        int dist = hamming(s, v);
        if(dist < best_dist){
            best_dist = dist;
            best_ind = i+1;
        }
    }
    if(best_dist > k){
        printf("-1\n");
    }else{
        printf("%d\n%d\n", best_ind, best_dist);
    }
    return 0;
}