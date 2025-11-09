#include <stdio.h>
#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

void insert(char x) {
    if ((rear + 1) % MAX == front) {
        printf("Overflow: Circular Queue is full.\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = x;
    printf("Inserted: %c\n", x);
}

void delete() {
    if (front == -1) {
        printf("Underflow: Circular Queue is empty.\n");
        return;
    }
    printf("Deleted: %c\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        printf("Circular Queue is empty.\n");
        return;
    }
    printf("Circular Queue: ");
    int i = front;
    while (1) {
        printf("%c ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;
    char c;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &c);
                insert(c);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice.\n");
        }
    }
}
