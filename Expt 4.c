#include <stdio.h>
#include <stdlib.h>

int *queue;
int front, size, capacity;

void init(int c) 
{
    queue = (int*)malloc(c * sizeof(int));
    capacity = c;
    size = 0;
    front = 0;
}

int peek() 
{
    if (size == 0)
        return -1;
    return queue[front];
}

int getRear()
 {
    if (size == 0)
        return -1;
    int rear = (front + size - 1) % capacity;
    return queue[rear];
}

void enqueue(int x) {
    if (size == capacity)
 {
        printf("Queue is full!\n");
        return;
    }
    int rear = (front + size) % capacity;
    queue[rear] = x;
    size++;
}

int dequeue() {
    if (size == 0)
 {
        printf("Queue is empty!\n");
        return -1;
    }
    int val = queue[front];
    front = (front + 1) % capacity;
    size--;
    return val;
}

int main() {
    init(4);

    enqueue(10);
    printf("Front: %d, Rear: %d\n", peek(), getRear());

    enqueue(20);
    printf("Front: %d, Rear: %d\n", peek(), getRear());

    enqueue(30);
    printf("Front: %d, Rear: %d\n", peek(), getRear());

    enqueue(40);
    printf("Front: %d, Rear: %d\n", peek(), getRear());

    dequeue();
    printf("Front: %d, Rear: %d\n", peek(), getRear());

    dequeue();
    printf("Front: %d, Rear: %d\n", peek(), getRear());

    enqueue(50);
    printf("Front: %d, Rear: %d\n", peek(), getRear());

    free(queue);
    return 0;
}
