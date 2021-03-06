//Zadatak 8. Napisati rekurzivnu funkciju kojom se izračunava zbir elemenata na n-tom nivou stabla, pri čemu se koren stabla tretira kao nulti nivo.


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct tree{
    int data;
    struct tree *left;
    struct tree *right;
}TREE;

TREE *root = NULL,*temp;

struct tree *createNode(int elem){
    temp = (struct tree*)malloc(sizeof(struct tree));
    temp->data = elem;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct tree *addBTS(struct tree *tree, int elem){
    if(tree == NULL){
        tree = createNode(elem);
    }
    if(elem < tree->data){
        tree->left = addBTS(tree->left, elem);
    }
    if(elem > tree->data){
        tree->right = addBTS(tree->right, elem);
    }
    return tree;
}

void inorder(struct tree *tree){
    if(tree){
        inorder(tree->left);
        printf("%d",tree->data);
        inorder(tree->right);    
    }
}
void postorder(struct tree *tree){
    if(tree){
        postorder(tree->left);
        postorder(tree->right); 
        printf("%d",tree->data);   
    }
}
void preorder(struct tree *tree){
    if(tree){
        printf("%d",tree->data);
        preorder(tree->left);
        preorder(tree->right);    
    }
}

int zbirElemenataNaNtomNivou(struct tree *tree,int n){
    int s = 0;
    if(tree){
       if(n != 0){
           s+=zbirElemenataNaNtomNivou(tree->left,n-1);
           s+=zbirElemenataNaNtomNivou(tree->right,n-1);
        }
        else{
           s+=tree->data;
        }
    }
  
    return s;
} 



int main(){
    root = createNode(1);
    addBTS(root,2);
    addBTS(root,3);
    addBTS(root,4);
    addBTS(root,5);
    addBTS(root,6);
    addBTS(root,7);
    addBTS(root,8);
    addBTS(root,9);
    printf("Zbir elemenata u nivou:%d",zbirElemenataNaNtomNivou(root,8));
    return 0;
}



