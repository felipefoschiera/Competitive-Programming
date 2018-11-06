#include <cstdio>

const int MAX = 112;

int main(){
    char s[MAX];
    scanf(" %s", s);
    bool exists[26];
    int cnt = 0;
    for(int i = 0; s[i]; i++){
        if(exists[s[i] - 'a'] == false) cnt++;
        exists[s[i] - 'a'] = true;
    }
    printf("%s\n", cnt % 2 == 1 ? "IGNORE HIM!" : "CHAT WITH HER!");
    return 0;
}