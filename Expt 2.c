// 1. Sum of n numbers
#include <stdio.h>
int sum(int n) {
if (n == 0)
return 0;
 else
 return n + sum(n - 1);
 }
int main() {
	int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Sum from %d to 0 is: %d\n", number, sum(number));
	return 0;
}

// 2.Generate Fibonacci sequence
#include <stdio.h>
int fibonacci(int n) {
	if (n == 0)
    	return 0;
	else if (n == 1)
    	return 1;
	else
    	return fibonacci(n - 1) + fibonacci(n - 2);
}
 
int main() {
	int n;
    printf("Enter the position (n): ");
    scanf("%d", &n);
    printf("Fibonacci number at position %d is: %d\n", n, fibonacci(n));
	return 0;
}

// CODE 3RD  Solve Towers of Hanoi Problem
 
#include <stdio.h>
 
// Function to calculate the sum of first n natural numbers recursively
int sum(int n) {
	if (n == 0)
    	return 0;
	else
    	return n + sum(n - 1);
}
 
// Function to calculate the nth Fibonacci number recursively
int fibonacci(int n) {
	if (n == 0)
    	return 0;
	else if (n == 1)
    	return 1;
	else
    	return fibonacci(n - 1) + fibonacci(n - 2);
}
 
// Towers of Hanoi recursive function
void towersOfHanoi(int n, char source, char auxiliary, char destination) {
	if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
    	return;
	}
    towersOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towersOfHanoi(n - 1, auxiliary, source, destination);
}
 
int main() {
	int choice, n;
 
	while (1) {
        printf("\n--- Recursive Program Menu ---\n");
        printf("1. Sum of First n Natural Numbers\n");
        printf("2. Fibonacci Sequence\n");
        printf("3. Towers of Hanoi\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
 
    	switch (choice) {
        	case 1:
                printf("Enter a positive integer: ");
                scanf("%d", &n);
                if (n < 0)
                    printf("Invalid input. Please enter a non-negative integer.\n");
                else
                    printf("Sum of first %d natural numbers is: %d\n", n, sum(n));
                break;
 
        	case 2:
                printf("Enter the number of terms: ");
                scanf("%d", &n);
                if (n <= 0)
                    printf("Please enter a positive integer.\n");
                else {
                    printf("Fibonacci Sequence: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", fibonacci(i));
                    }
                    printf("\n");
                }
                break;
 
        	case 3:
                printf("Enter the number of disks: ");
                scanf("%d", &n);
                if (n <= 0)
                    printf("Please enter a positive number of disks.\n");
                else {
                    printf("Sequence of moves:\n");
                    towersOfHanoi(n, 'A', 'B', 'C');
                }
                break;
 
        	case 4:
                printf("Exiting program.\n");
                return 0;
 
            default:
                printf("Invalid choice. Please select between 1 and 4.\n");
    	}
	}
 
	return 0;
}
