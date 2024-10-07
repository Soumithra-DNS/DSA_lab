#include <stdio.h>
#include <stdlib.h>


struct Node {
    int dest;
    struct Node* next;
};


struct AdjList {
    struct Node* head;
};


struct Graph {
    int V;
    struct AdjList* array;
};


struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    
  
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }
    
    return graph;
}


void addEdge(struct Graph* graph, int src, int dest) {
   
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = src;
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        printf("Adjacency list of vertex %d\nhead", v);
        struct Node* current = graph->array[v].head;
        while (current) {
            printf(" -> %d", current->dest);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    printf("Enter number of vertices ");
    int V;
    scanf("%d",&V);

    struct Graph* graph = createGraph(V);
    printf("Enter source and destinition of nodes\n");
    printf("Or press -1 -1 to quit\n");
    while(1){

        int x, y;
        scanf("%d %d",&x, &y);
        if(x == -1){
            break;
        }
        addEdge(graph,x,y);
    }

    printGraph(graph);
    
    return 0;
}
