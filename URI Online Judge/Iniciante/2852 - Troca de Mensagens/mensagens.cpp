#include <iostream>
#include <vector>
using namespace std;

bool ehVogal(char c){
    string vogais = "aeiou";
    for(auto x : vogais) if(c == x) return true;
    return false;
}

string alfabeto = "abcdefghijklmnopqrstuvwxyz";



int main(){
    string K;
    while(cin >> K){
        int n; cin >> n;
        cin.ignore();
        while(n--){
            string line, word = "";
            getline(cin, line);
            vector<string> palavras;
            int sz = line.length();
            for(int i = 0; i < sz; i++){
                if(line[i] == ' '){ if(word != "") palavras.push_back(word); word = ""; }
                else { word += line[i]; if(i == sz - 1) if(word != "") palavras.push_back(word); }
            }
            vector<string> rel = palavras;
            int idx = 0, pal_sz = palavras.size();
            for(int p = 0; p < pal_sz; p++){
                if(ehVogal(palavras[p][0])) continue;
                for(int c = 0; c < (int)palavras[p].length(); c++){
                    rel[p][c] = K[idx++];
                    if(idx >= (int)K.length()) idx = 0;
                }
            }
            for(int p = 0; p < pal_sz; p++){
                if(ehVogal(palavras[p][0])){
                    cout << palavras[p] << (p == pal_sz -1 ? "\n" : " ");
                    continue;
                }
                for(int c = 0; c < (int)palavras[p].length(); c++){
                    cout << alfabeto[((rel[p][c] - 'a') + (palavras[p][c] - 'a')) % 26];
                }
                cout << (p == pal_sz-1 ? "\n" : " ");
            }
        }
    }
    return 0;
}