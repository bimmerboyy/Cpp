#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *first = NULL,*last = NULL,*temp;

bool isEmpty(){
    if(first == NULL){
        return true;
    }
    else return false;
}

void ubaci(int elem){
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = elem;
    temp->next = NULL;
    if(isEmpty()){
        first = temp;
        last = temp;
    }
    last->next = temp;
    last = temp;

   
}
void dipslay(){
    if(isEmpty()){
        printf("Lista je prazna");
        return;
    }
    if(first == last & temp == last){
        printf("Lista ima samo 1 elem i to je: %d",temp->data);

    }
    temp = first;
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }

}
void invertThreeElement(struct node *first){
    temp = first->next;
    first->next = NULL;
    struct node *temp2 = temp->next;
    temp->next = first;
    temp2->next = temp;
}
struct node invertMoreThanThreeElements(struct node *first){
    while(first != NULL){
    temp = NULL;
    struct node *temp2 = first->next;
    first->next = temp;
    temp = first;
    first = temp2;
    }
    first = temp;
    return *first;
    
}

int main(){
    ubaci(4);
    ubaci(2);
    ubaci(6);
    ubaci(16);
    printf("Ispis pre invertovanja:");   
    dipslay();

    *first = invertMoreThanThreeElements(first);
    printf("Ispis posle invertovnja:");
    dipslay();

    return 0;
}