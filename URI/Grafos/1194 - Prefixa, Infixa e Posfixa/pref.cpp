#include <iostream>
using namespace std;

void posfixa(string pre, string inf){
    char raiz = pre[0];
    int pos_raiz_inf = inf.find(raiz);

    if(pos_raiz_inf != 0){
        string esq1 = pre.substr(1, pos_raiz_inf);
        string esq2 = inf.substr(0, pos_raiz_inf);
        posfixa(esq1, esq2);
    }
    if(pos_raiz_inf+1 != pre.size()){
        string dir1 = pre.substr(pos_raiz_inf+1);
        string dir2 = inf.substr(pos_raiz_inf+1);
        posfixa(dir1, dir2);
    }
    cout << raiz;
}


int main(){
    string pre, inf;
    while(cin >> pre >> inf){
        posfixa(pre, inf);
        cout << endl;
    }
    return 0;
}