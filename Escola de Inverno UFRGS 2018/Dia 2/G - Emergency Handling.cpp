#include <stdio.h>
#include <vector>
#define INF ((int)1e9)
using namespace std;


struct paciente {
    int tempo_chegada;
    int severity_chegada;
    int ratio;
};

int severityAtTime(paciente p, int tempo){
    return p.severity_chegada + p.ratio * (tempo - p.tempo_chegada);
}

int main(){
    int T;
    scanf("%d ", &T);
    for(int tc = 1; tc <= T; tc++){
        printf("Case #%d:\n", tc);
        int N;
        scanf("%d ", &N);
        vector<paciente> pacientes;
        while(N--){
            char c;
            scanf(" %c", &c);
            if(c == 'P'){
                paciente x;
                scanf("%d %d %d ", &x.tempo_chegada, 
                &x.severity_chegada, &x.ratio);
                pacientes.push_back(x);
            }else if(c == 'A'){
                int tempo;
                scanf("%d ", &tempo);
                int best_severity = -INF, best_ind, best_ratio;
                for(int i = 0; i < (int)pacientes.size(); i++){
                    int sevI = severityAtTime(pacientes[i], tempo);
                    if(sevI > best_severity){
                        best_severity = sevI;
                        best_ind = i;
                        best_ratio = pacientes[i].ratio;
                    }else if(sevI == best_severity){
                        if(pacientes[i].ratio > best_ratio){
                            best_ind = i;
                            best_ratio = pacientes[i].ratio;
                        }
                    }
                }
                printf("%d %d\n", best_severity, best_ratio);        
                pacientes.erase(pacientes.begin() + best_ind);            
                
            }
        }
        
    }

    return 0;
}