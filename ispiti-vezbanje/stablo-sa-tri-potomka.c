//Napraviti stablo koje ima max tri potomka i napraviti funkciju da li je stablo kompletno


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct tree{
    int info;
    struct tree *left;
    struct tree *right;
    struct tree *middle;
}TREE;

TREE *root = NULL, *temp;


struct tree *createTree(int info){
    temp = (struct tree *) malloc(sizeof(struct tree));
    temp->info = info;
    temp->left = NULL;
    temp->right = NULL;
    temp->middle = NULL;
    return temp;
}

void printInorder(struct tree *tree){
    if(tree){
        printInorder(tree->left);
        printf("%d",tree->info);
        printInorder(tree->middle);
        printInorder(tree->right);
    }
}
void printPreorder(struct tree *tree){
    if(tree){
        printf("%d",tree->info);
        printInorder(tree->left);
        printInorder(tree->middle);
        printInorder(tree->right);
    }
}
void printPostorder(struct tree *tree){
    if(tree){
        printInorder(tree->left);
        printInorder(tree->middle);
        printInorder(tree->right);
        printf("%d",tree->info);
    }
}

struct tree* addTree(struct tree *tree, int elem,char side){
    if(root == NULL){
        root = createTree(elem);
        return root;
    }
    if(side == 'L'){
        tree->left = addTree(tree->left,elem,'L');
        return tree->left;
    }
    if(side == 'R'){
        tree->right = addTree(tree->right,elem,'R');
        return tree->right;
    }
}

int main(){

    return 0;
}