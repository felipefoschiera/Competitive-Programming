#include <stdio.h>
#include <stack>
#define MAX 112345
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        char a[MAX];
        scanf("%s", a);
        stack<char> pilha;
        bool valid = true;   
        for(int i = 0; a[i] != '\0'; i++){     
            char c = a[i];
            if (c == '(' || c == '[' || c == '{'){
                pilha.push(c);
            }
            else{
                if (pilha.empty()){
                    valid = false;
                }else{
                    char topo = pilha.top();
                    pilha.pop();
                    if((c == ')' && topo != '(') || 
                    (c == ']' && topo != '[') ||
                    (c == '}' && topo != '{')){
                        valid = false;
                    }
                }
            }
            if(!valid) break;
        }
        printf((valid && pilha.empty()) ? "S\n" : "N\n");
    }
}
