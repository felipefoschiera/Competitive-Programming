// URI 2872 - Protocolo TCP/IP
// Felipe G. Foschiera
#include <cstdio>
#define MAX 1000
using namespace std;

int main(){
    while(scanf("%*d") != EOF){
        char s[MAX], num[MAX];
        int cnt[MAX];
        for(int i = 0; i < MAX; i++) cnt[i] = 0;
        while(scanf(" %s", s), s[0] != '0'){
            int numero = 0;
            scanf("%s", num);
            for(int i = 0; num[i]; i++)
                numero *= 10, numero += num[i] - '0';
            cnt[numero]++;
        }
        for(int i = 0; i < MAX; i++)
            if(cnt[i])
                for(int j = 0; j < cnt[i]; j++)
                    printf("Package %03d\n", i);
        printf("\n");
        
    }
    return 0;
}