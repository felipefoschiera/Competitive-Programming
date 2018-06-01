/**
 *  URI 1466 - Percurso em Árvore por Nível
 *  Felipe G. Foschiera
 */
#include <iostream>
#include <queue>
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


string searchLevel(node *root){
    string ans = "";    
    queue<node *> q;
    q.push(root);
    while(1){
        int nodeCount = q.size();
        if(nodeCount == 0) break;
        
        while(nodeCount > 0){
            node *node = q.front();
            ans += " " + to_string(node->info);
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            nodeCount--;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int C; cin >> C;
    for(int c = 1; c <= C; c++){
        node *tree = 0;
        int N, v;
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> v;
            tree = insert(tree, v);
        }
        cout << "Case " << c << ":" << endl;
        cout << searchLevel(tree).substr(1) << endl << endl;
    }
    return 0;
}