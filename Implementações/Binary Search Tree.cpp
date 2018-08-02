/**
 *  URI 1201 - Operações em ABP II
 *  Felipe G. Foschiera
 */
#include <iostream>
using namespace std;

struct node {
    node *left;
    node *right;
    int data;
    node(int info):
        data(info),
        left(0),
        right(0) {}
};

struct node *insert(node *tree, int v){
    if(tree == NULL){
        tree = new node(v);
    }else{
        if(v < tree->data){
            tree->left = insert(tree->left, v);
        }else if(v > tree->data){
            tree->right = insert(tree->right, v);
        }
    }
    return tree;
}

struct node *maxValueNode(node *tree){
    struct node* current = tree;
    while(current->right != NULL){
        current = current->right;
    }
    return current;
}

struct node *deleteNode(node *root, int v){
    if(root == NULL) return root;
    if(v < root->data) root->left = deleteNode(root->left, v);
    else if(v > root->data) root->right = deleteNode(root->right, v);
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }else if(!(root->left && root->right)){
            node *temp = root;
            if(root->left != NULL){
                root = root->left;
            }else{
                root = root->right;
            }
            free(temp);
        }else{
            node *temp = maxValueNode(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
        }
    }
    return root;
}

string ans = "";

void prefixa(node *tree){
    if(tree != NULL){
        ans += " " + to_string(tree->data);
        prefixa(tree->left);
        prefixa(tree->right);

    }
}

void infixa(node *tree){
    if(tree != NULL){
        infixa(tree->left);
        ans += " " + to_string(tree->data);
        infixa(tree->right);
    }
}

void posfixa(node *tree){
    if(tree != NULL){
        posfixa(tree->left);
        posfixa(tree->right);
        ans += " " + to_string(tree->data);
    }
}

bool search(node *tree, int v){
    if(tree == NULL) return false;
    if(tree->data == v) return true;

    if(v < tree->data) return search(tree->left, v);
    else return search(tree->right, v);
}