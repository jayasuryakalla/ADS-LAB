#include <stdio.h>
#define MAX_VERTICES 100
void enqueue(int queue[], int *rear, int value) {
    queue[++(*rear)] = value;
}
int dequeue(int queue[], int *front) {
    return queue[(*front)++];
}
int isQueueEmpty(int front, int rear) {
    return front > rear;
}
void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int vertices, int start) {
    int queue[MAX_VERTICES];
    int front = 0, rear = -1;
    int i;
    visited[start] = 1;
    enqueue(queue, &rear, start);
    while (!isQueueEmpty(front, rear)) {
        int currentVertex = dequeue(queue, &front);
        printf("%d ", currentVertex);
        for (i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, &rear, i);
            }
        }
    }
}
int main() {
    int vertices, edges, i;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    if (vertices <= 0 || vertices > MAX_VERTICES) {
        printf("Invalid number of vertices. Exiting...\n");
        return 1;
    }
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int visited[MAX_VERTICES] = {0};
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    if (edges < 0 || edges > vertices * (vertices - 1)) {
        printf("Invalid number of edges. Exiting...\n");
        return 1;
    }
    for (i = 0; i < edges; i++) {
        int start, end;
        printf("Enter edge %d (start end): ", i + 1);
        scanf("%d %d", &start, &end);
        if (start < 0 || start >= vertices || end < 0 || end >= vertices) {
            printf("Invalid vertices. Try again.\n");
            i--;
            continue;
        }
        graph[start][end] = 1;
        graph[end][start] = 1;
    }
    int startVertex;
    printf("Enter the starting vertex for BFS traversal: ");
    scanf("%d", &startVertex);
    if (startVertex < 0 || startVertex >= vertices) {
        printf("Invalid starting vertex. Exiting...\n");
        return 1;
    }
    printf("BFS Traversal Order: ");
    BFS(graph, visited, vertices, startVertex);
    return 0;
}
