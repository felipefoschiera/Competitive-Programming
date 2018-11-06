#include <cstdio>

const int MAX = 101010;

int main(){
    int n;
    scanf("%d", &n);
    char s[MAX];
    scanf(" %s", s);
    int anton = 0;
    for(int i = 0; i < n; i++){
        anton += (s[i] == 'A');
    }
    int danim = n - anton;
    if(anton == danim){
        printf("Friendship\n");
    }else if(anton > danim){
        printf("Anton\n");
    }else printf("Danik\n");
    return 0; 
}