#include <iostream>
using namespace std;

string desenho[6];

int main(){
    int k;
    cin >> k;
    desenho[0] = "+------------------------+";
    desenho[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
    desenho[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
    desenho[3] = "|#.......................|";
    desenho[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
    desenho[5] = "+------------------------+";
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 6; j++){
            if(desenho[j][i] == '#'){
                desenho[j][i] = 'O';
                k--;
                if(k == 0) break;
            }
        }
        if(k == 0) break;
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < desenho[i].size(); j++){
            cout << desenho[i][j];
        }
        cout << '\n';
    }
    return 0;
}