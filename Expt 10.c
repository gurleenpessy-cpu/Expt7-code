#include <stdio.h>

#define MAX 20

int graph[MAX][MAX], visited[MAX];
int queue[MAX], front = -1, rear = -1;

void createGraph(int n) {
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

void DFS(int start, int n) {
    printf("%d ", start);
    visited[start] = 1;

    for (int j = 0; j < n; j++) {
        if (graph[start][j] == 1 && !visited[j]) {
            DFS(j, n);
        }
    }
}

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void BFS(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (front != -1 && front <= rear) {
        int node = dequeue();
        printf("%d ", node);

        for (int j = 0; j < n; j++) {
            if (graph[node][j] == 1 && !visited[j]) {
                enqueue(j);
                visited[j] = 1;
            }
        }
    }
}

int main() {
    int n, start, choice;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    createGraph(n);

    while (1) {
        printf("\n--- Graph Menu ---\n");
        printf("1. DFS Traversal\n2. BFS Traversal\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < n; i++) visited[i] = 0;
                printf("Enter starting node: ");
                scanf("%d", &start);
                printf("Reachable nodes (DFS): ");
                DFS(start, n);
                printf("\n");
                break;

            case 2:
                front = rear = -1;
                printf("Enter starting node: ");
                scanf("%d", &start);
                printf("Reachable nodes (BFS): ");
                BFS(start, n);
                printf("\n");
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
