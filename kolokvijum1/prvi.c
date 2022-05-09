/*
1. dvostruko ulančana lista:
a) lenght
b) remove nth
3) palindrom
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}NODE;

NODE *first, *temp;

struct node* napravi_node(int x){
    struct node *novi = (struct node*)malloc(sizeof(struct node));
    novi -> data = x;
    novi -> next = NULL;
    novi -> prev = NULL;
    return novi;
}

void insert_at_head(int x){
    temp = napravi_node(x);
    if(first == NULL){
        first = temp;
        return; 
    }
    first -> prev = temp;
    temp -> next = first;
    first = temp;
}

void insert_at_tail(int x){
    temp = first;
    struct node* novi = napravi_node(x);
    if(first == NULL){
        first = novi;
        return;
    }
    while(temp -> next != NULL){
        temp = temp -> next;
    } 
    temp -> next = novi;
    novi -> prev = temp;
}

void display(){
    temp = first;
    while(temp != NULL){
        printf("%d \n", temp->data);
        temp = temp->next;
    }
}

void delete_actual(struct node *pom){
    if(first == pom){
        first = pom -> next;
        first -> prev = NULL;
        free(pom);
        return;
    }
    struct node *prev = pom -> prev;
    if(pom -> next == NULL){
        prev -> next = NULL;
        pom -> prev = NULL;
        free(pom);
        return;
    }
    struct node *next = pom -> next;
    pom -> prev = NULL;
    pom -> next = NULL;
    free(pom);
    prev -> next = next;
    next -> prev = prev;
}

//prva funkcija:  merenje dužine:

int lenght(){
    if(first == NULL){
        return 0;
    }
    int l = 0;
    struct node *temp = first;
    while(temp != NULL){
        l++;
        temp = temp -> next;
    } 
    
    return l;
}

//Druga funkcija : brisanje na poziciji:

void remove_nth(int n){
    if(first == NULL){
        printf("Underflow \n");
        return ;
    }
    int i = 1;
    struct node *temp = first;
    while(temp != NULL){
        if(i == n){
            delete_actual(temp);
            return;
        }
        i++;
        temp = temp -> next;
    }
    printf("Ne postoji u listi  \n");
    return;
}

//treća funkcija : da li je palindrom:

bool palindrom(){
    if(first == NULL){
        return  false;
    }
    if(first -> next == NULL){
        return true;
    }
    temp = first;
    struct node *last = first;
    while(temp != NULL){
        last =  temp;
        temp = temp -> next;
    }
    printf("Zadnji je : %d  \n", last -> data);
    temp = first;
    while(temp  != last){
        if(temp -> data != last -> data){
            return false;
        }
        temp = temp -> next;
        last = last -> prev;
    }
    return true;
}

int main(){
    display();
    //isprobavanje funkcija:
    printf("The list has %d elements \n", lenght());
    display();
    remove_nth(1);
    printf("The list has %d elements \n", lenght());
    display();
    (palindrom()) ? printf("Lista je palindrom \n") : printf("Lista nije palindrom \n");
    insert_at_tail(1);
    insert_at_tail(2);
    insert_at_tail(4);
    printf("The list has %d elements \n", lenght());
    insert_at_tail(3);
    insert_at_tail(2);
    insert_at_tail(2);
    insert_at_tail(1);
    printf("The list has %d elements \n", lenght());
    (palindrom()) ? printf("Lista je palindrom \n") : printf("Lista nije palindrom \n");
    return 0;
}