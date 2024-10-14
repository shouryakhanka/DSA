#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX] = {0};

void DFS(int mat[][MAX], int n, int v) {
    int i;
    printf("%d ", v);
    visited[v] = 1;
    for (i = 0; i < n; i++) {
        if (mat[v][i] == 1 && visited[i] == 0) {
            DFS(mat, n, i);
        }
    }
}

void BFS(int mat[][MAX], int n, int v) {
    int i, front = 0, rear = 0, queue[MAX];
    printf("%d ", v);
    visited[v] = 1;
    queue[rear++] = v;
    while (front < rear) {
        v = queue[front++];
        for (i = 0; i < n; i++) {
            if (mat[v][i] == 1 && visited[i] == 0) {
                printf("%d ", i);
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int mat[MAX][MAX], n, i, j, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &v);
    printf("DFS traversal: ");
    DFS(mat, n, v);
    printf("\n");
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    printf("BFS traversal: ");
    BFS(mat, n, v);
    printf("\n");
    return 0;
}