#include <iostream>
using namespace std;

void posfixa(string s1, string s2){
    char raiz = s1[0];
    int pos_raiz_infixa = s2.find(raiz);

    if(pos_raiz_infixa != 0){
        string esq1 = s1.substr(1, pos_raiz_infixa);
        string esq2 = s2.substr(0, pos_raiz_infixa);
        posfixa(esq1, esq2);
    }
    if(pos_raiz_infixa + 1 != s1.size()){
        string dir1 = s1.substr(pos_raiz_infixa+1);
        string dir2 = s2.substr(pos_raiz_infixa+1);
        posfixa(dir1, dir2);
    }
    cout << raiz;
}

int main(){
    int C;
    cin >> C;
    while(C--){
        int len;
        string s1, s2;
        cin >> len >> s1 >> s2;
        posfixa(s1, s2);
        cout << endl;
    }
    return 0;
}