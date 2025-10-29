#include <stdio.h>
#include <string.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int item);
void pop();
void display();
void palindrome();
void overflow_underflow();

int main() {
    int choice, item;
    while (1) {
        printf("\n---- STACK OPERATIONS MENU ----\n");
        printf("1. Push Element\n");
        printf("2. Pop Element\n");
        printf("3. Check Palindrome\n");
        printf("4. Overflow and Underflow Demo\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                palindrome();
                break;
            case 4:
                overflow_underflow();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Program ended.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

void push(int item) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", item);
    } else {
        top++;
        stack[top] = item;
        printf("%d pushed to stack.\n", item);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! Nothing to pop.\n");
    } else {
        printf("Element popped: %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1)
        printf("Stack is empty!\n");
    else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

void palindrome() {
    char str[50], rev[50];
    int i, len, tempTop = -1;
    char tempStack[50];
    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);

    for (i = 0; i < len; i++)
        tempStack[++tempTop] = str[i];

    for (i = 0; i < len; i++)
        rev[i] = tempStack[tempTop--];
    rev[len] = '\0';

    if (strcmp(str, rev) == 0)
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);
}

void overflow_underflow() {
    int i;
    top = -1;
    printf("Demonstrating Overflow:\n");
    for (i = 1; i <= MAX + 1; i++)
        push(i);

    printf("\nDemonstrating Underflow:\n");
    for (i = 1; i <= MAX + 1; i++)
        pop();
}
