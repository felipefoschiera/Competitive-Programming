 #include <iostream>
#include <vector>
using namespace std;


struct prato {
    string nome;
    vector<string> ingred;
    int qt_ingred;
    int qt_tipicos = 0;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<string> tipicos;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        tipicos.push_back(s);
    }
    vector<prato> pratos;
    int M;
    cin >> M;
    pratos.assign(M, prato());
    for(int i = 0; i < M; i++){
        string nome;
        cin >> nome;
        pratos[i].nome = nome;        
        int qt;
        cin >> qt;
        pratos[i].qt_ingred = qt;
        for(int j = 0; j < qt; j++){
            string ing;
            cin >> ing;
            pratos[i].ingred.push_back(ing);
            for(int k = 0; k < N; k++){
                if(ing == tipicos[k]){
                    pratos[i].qt_tipicos++;
                }
            }
        }
    }
    for(int i = 0; i < M; i++){
        if(pratos[i].qt_tipicos > (double)pratos[i].qt_ingred / 2){
            for(int x = 0; x < M; x++){
                if(pratos[x].qt_tipicos <= (double)pratos[x].qt_ingred / 2){
                    for(int k = 0; k < pratos[x].qt_ingred; k++){
                        if(pratos[x].ingred[k] == pratos[i].nome){
                            pratos[x].qt_tipicos++;
                        }
                        
                    }
                }
            }
        }
    }
    for(int i = 0; i < M; i++){
        if(pratos[i].qt_tipicos > (double)pratos[i].qt_ingred / 2){
            cout << "porcao tipica\n";
        }else{
            cout << "porcao comum\n";
        }
    }
    return 0;
}
