#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

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
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

bool isQueueEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(struct Queue* queue) {
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

void BFS(struct Graph* graph, int startVertex) {
    bool* visited = (bool*)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; ++i) {
        visited[i] = false;
    }
    
    struct Queue* queue = createQueue(graph->V);
    visited[startVertex] = true;
    enqueue(queue, startVertex);
    
    while (!isQueueEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);
        
        struct Node* temp = graph->array[currentVertex].head;
        while (temp) {
            int adjacentVertex = temp->dest;
            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = true;
                enqueue(queue, adjacentVertex);
            }
            temp = temp->next;
        }
    }
    
    free(visited);
    free(queue);
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
    printf("Select vertex for traversal in BFS\n");
    int select;
    scanf("%d",&select);

    printf("BFS traversal starting from vertex %d:\n",select);
    BFS(graph, select);

    return 0;
}
