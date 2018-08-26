/**
 *  URI 1200 - Operações em ABP I
 *  Felipe G. Foschiera
 */
#include <iostream>
using namespace std;

struct node {
    node *esquerda;
    node *direita;
    string info;
    node(string data):
        info(data),
        esquerda(0),
        direita(0) {}
};

struct node *insere(node *tree, string info){
    if(tree == NULL){
        tree = new node(info);
    }else if(info < tree->info){
        tree->esquerda = insere(tree->esquerda, info);
    }else if(info > tree->info){
        tree->direita = insere(tree->direita, info);
    }
    return tree;
}

bool busca(node *tree, string s){
    if(tree == NULL){
        return false;
    }else if(tree->info == s){
        return true;
    }
    if(tree->info > s){
        return busca(tree->esquerda, s);
    }else{
        return busca(tree->direita, s);
    }
}

string ans = "";

void infixa(node *tree){
    if(tree != NULL){
        infixa(tree->esquerda);
        ans += " " + tree->info;
        infixa(tree->direita);
    }
}

void posfixa(node *tree){
    if(tree != NULL){
        posfixa(tree->esquerda);
        posfixa(tree->direita);
        ans += " " + tree->info;
    }
}

void prefixa(node *tree){
    if(tree != NULL){
        ans += " " + tree->info;
        prefixa(tree->esquerda);
        prefixa(tree->direita);
    }
}


int main(){
    string linha;
    node *tree = 0;
    while(cin >> linha){
        if(linha == "POSFIXA"){
            posfixa(tree);
            cout << ans.substr(1) << endl;
        }else if(linha == "INFIXA"){
            infixa(tree);
            cout << ans.substr(1) << endl;
        }else if(linha == "PREFIXA"){
            prefixa(tree);
            cout << ans.substr(1) << endl;
        }else{
            string s;
            cin >> s;
            if(linha == "I"){
                tree = insere(tree, s);
            }else if(linha == "P"){
                cout << s << (busca(tree, s) ? " existe" : " nao existe") << endl;
            }
        }
        ans = "";        
    }
    return 0;
}