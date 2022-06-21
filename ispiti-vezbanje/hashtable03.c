/*Napisati program u jeziku C kojim se u hes tabelu duzine 20 upisuje 10 studenata pri cemu
je podatak broj indeksa.Za upis koristiti podprogram.Za resavanje koalizije
koristiti linearno hesiranje

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define SIZE 20

struct Studenti{
    char *ime;
    int kljuc;
};

struct Studenti *hashArray[SIZE];
struct Studenti *item;
struct Studenti *fakeitem;

int hashCode(int key){
    return key % SIZE;
}

void insert(char *ime, int key){
    struct Studenti *item = (struct Studenti *)malloc(sizeof(struct Studenti));
    item->ime = ime;
    item->kljuc = key;

    int hashIndex = hashCode(key);

    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->kljuc != -1){

        ++hashIndex;
        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = item;
}

void display(){
    printf("Pocetak\n");
    for(int i = 0; i < SIZE; i++){
        if(hashArray[i] != NULL){
            printf("%d -> %s\n",hashArray[i]->kljuc,hashArray[i]->ime);
        }
        else{
            printf("---");
        }
        printf("\n");
    }
    printf("\nKraj");
}

int main(){
    
}
