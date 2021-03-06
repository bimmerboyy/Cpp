#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node* next;
}NODE;

NODE *first1 = NULL,*last1 = NULL,*temp;
NODE *first2 = NULL,*last2 = NULL;

bool isEmpty(struct node* first){
    return first == NULL;
}
void unesi(int elem,struct node* first,struct node* last){
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = elem;
    temp->next = NULL;
    if(isEmpty(first)){
        first = temp;
        last = temp;
    }
    last->next = temp;
    last = temp;
}
void display(struct node* first){
    temp = first;
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}
int main(){
    unesi(1,first1,last1);
    unesi(2,first1,last1);
    unesi(3,first1,last1);
    unesi(4,first1,last1);
    unesi(5,first1,last1);
    display(first1);
    return 0;
}