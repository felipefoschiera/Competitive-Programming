#include <iostream>
#define INF ((int)1e9)
using namespace std;

int cnt[8];

int main(){
    string s;
    getline(cin, s);
    for(int i = 0; i < (int)s.length(); i++){
        if(s[i] == 'I') cnt[0]++;
        if(s[i] == 'l') cnt[1]++;
        if(s[i] == 'o') cnt[2]++;
        if(s[i] == 'v') cnt[3]++;
        if(s[i] == 'e') cnt[4]++;
        if(s[i] == 'y') cnt[5]++;
        if(s[i] == 'u') cnt[6]++;
        if(s[i] == '!') cnt[7]++;
    }
    cnt[2] /= 2;
    int low = INF;
    for(int i = 0; i < 8; i++){
        low = min(low, cnt[i]);
    }
    printf("%d\n", low);
    
    return 0;   
}