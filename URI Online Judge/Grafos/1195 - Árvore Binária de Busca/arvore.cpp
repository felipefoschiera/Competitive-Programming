/**
 *  URI 1195 - Árvore Binária de Busca
 *  Felipe G. Foschiera
 */
#include <iostream>
using namespace std;

struct node {
    node *left;
    node *right;
    int info;
    node(int data):
        info(data),
        left(0),
        right(0) {}
};

struct node *insert(node *tree, int info){
    if(tree == NULL){
        tree = new node(info);
    }else if(info < tree->info){
        tree->left = insert(tree->left, info);
    }else if(info > tree->info){
        tree->right = insert(tree->right, info);
    }
    return tree;
}

string ans = "";

void prefixa(node *tree){
    if(tree != NULL){
        ans += " " + to_string(tree->info);
        prefixa(tree->left);
        prefixa(tree->right);
    }
}

void infixa(node *tree){
    if(tree != NULL){
        infixa(tree->left);
        ans += " " + to_string(tree->info);
        infixa(tree->right);
    }
}

void posfixa(node *tree){
    if(tree != NULL){
        posfixa(tree->left);
        posfixa(tree->right);
        ans += " " + to_string(tree->info);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int C; cin >> C;
    for(int c = 1; c <= C; c++){
        node *tree = 0;
        ans = "";
        int N, v;
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> v;
            tree = insert(tree, v);
        }
        cout << "Case " << c << ":" << endl;
        cout << "Pre.:";
        prefixa(tree);
        cout << ans << endl;
        ans = "";        
        cout << "In..:";
        infixa(tree);
        cout << ans << endl;
        ans = "";        
        cout << "Post:";
        posfixa(tree);
        cout << ans << endl;
        cout << endl;
    }
    return 0;
}