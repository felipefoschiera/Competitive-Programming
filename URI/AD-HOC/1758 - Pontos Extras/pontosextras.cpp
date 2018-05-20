/**
 *  URI 1758 - Pontos Extras
 *  Felipe G. Foschiera
 */
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int P, N;
        scanf("%d %d", &P, &N);
        for(int i = 0; i < N; i++){
            double notas[P];            
            double media = 0.0, nota = 0.0;
            for(int j = 0; j < P; j++){
                scanf("%lf", &nota);
                notas[j] = nota;
                media += nota;
            }
            media /= P;
            if(media >= 7.0){
                for(int j = 0; j < P; j++){
                    if(notas[j] > media)
                        media = notas[j];
                    
                }
            }else if(media >= 4.0){
                for(int j = 0; j < P; j++){
                    if(notas[j] > media && (notas[j] < 7.0))
                        media = notas[j];
                    
                }
            }
            printf("%.2f\n", media);
            
        }
    }

    return 0;
}