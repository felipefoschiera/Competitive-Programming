#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int inst = 1;
    while(cin >> n && n){
        string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        cout << "Instancia " << inst++ << endl;
        for(int i = 0; i < n; i++){
            int v;
            cin >> v;
            cout << alfabeto[v-1];
            string novo = "";
            novo += alfabeto[v-1];
            for(int j = 0; j < 26; j++)
                if(alfabeto[j] != alfabeto[v-1]) novo += alfabeto[j];            
            alfabeto = novo, novo = "";
        }
        cout << endl << endl;
    }
    return 0;
}