#include<stdio.h>
#define MAX_VERTICES 100
void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int vertices, int start){
    int i;
    printf("%d",start);
    visited[start]=1;
    for(i=0;i<vertices;i++){
        if(graph[start][i]==1 && !visited[i]){
            DFS(graph ,visited ,vertices ,i);
        }
    }
}

int main(){
    int vertices,i,edges;
    printf("Enter the number of vertices: ");
    scanf("%d",&vertices);
    if(vertices <= 0 || vertices > MAX_VERTICES){
        printf("Invalid number of vertices. EXITING...\n");
        return 1;
    }
    int graph[MAX_VERTICES][MAX_VERTICES]={0};
    int visited[MAX_VERTICES]={0};
    printf("Enter the number of edges: ");
    scanf("%d",&edges);
    if(edges < 0 || edges > vertices*(vertices-1)){
        printf("Invalid number of edges. EXITING...\n");
        return 1;
    }
    for(i=0;i<i<edges;i++){
        int start,end;
        printf("Enter edge %d(start end): ",i+1);
        scanf("%d%d",&start,&end);
        if(start < 0 || start >= vertices || end < 0 || end >=vertices){
            printf("Invalid vertices.Try again.\n");
            i--;
            continue;
        }
        graph[start][end]=1;
    }
    int startvertex;
    printf("Enter the starting vertex for DFS traversal: ");
    scanf("%d",&startvertex);
    if(startvertex < 0 || startvertex >= vertices){
        printf("Invalid starting vertex.Exiting...\n");
        return 1;
    }
    printf("DFS traversal order : ");
    DFS(graph,visited,vertices,startvertex);
    return 0;
}
