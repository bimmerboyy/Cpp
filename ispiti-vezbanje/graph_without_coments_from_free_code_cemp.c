#include <stdio.h>
#include <stdlib.h>
#define N 6
struct Graph{
    struct Node* head[N];
};
struct Node{
    int dest;
    struct Node* next;
};
struct Edge {
    int src, dest;
};
struct Graph* createGraph(struct Edge edges[], int n){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    for (int i = 0; i <= N; i++) {
        graph->head[i] = NULL;
    }
    for (int i = 0; i < n; i++){
        int src = edges[i].src;
        int dest = edges[i].dest;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->dest = dest;
        newNode->next = graph->head[src];
        graph->head[src] = newNode;
    }
    return graph;
}
void printGraph(struct Graph* graph){
    for (int i = 0; i <= N; i++){
        // print current vertex and all its neighbors
        struct Node* ptr = graph->head[i];
        while (ptr != NULL)
        {
            printf("(%d —> %d)\t", i, ptr->dest);
            ptr = ptr->next;
        }
 
        printf("\n");
    }
}
int main(){
    struct Edge edges[] ={
        {1, 3}, {1, 2}, {3, 5}, {5, 2}, {2, 4}, {6, 4}
    };
    int n = sizeof(edges)/sizeof(edges[0]);
    struct Graph *graph = createGraph(edges, n);
    printGraph(graph);
    return 0;
}