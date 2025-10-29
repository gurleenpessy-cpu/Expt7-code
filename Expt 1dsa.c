// code 1 Bubble sort
#include <stdio.h>
 
void ascending(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
    	for (int j = 0; j < size - i - 1; j++) {
        	if (arr[j] > arr[j + 1]) {
            	int temp = arr[j];
            	arr[j] = arr[j + 1];
            	arr[j + 1] = temp;
        	}
    	}
	}
}
 
int main() {
	int data[100], n;
 
	
	printf("Enter number of elements: ");
	scanf("%d", &n);
 
	printf("Enter %d elements:\n", n);
	for (int i = 0; i < n; i++) {
    	scanf("%d", &data[i]);
	}
 
  
	ascending(data, n);
 
	
	printf("Sorted Array in Ascending Order:\n");
	for (int i = 0; i < n; i++) {
    	printf("%d ", data[i]);
	}
 
	return 0;
}
// code 2 selection sort
#include <stdio.h>
void descending(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
    	int max_idx = i;
    	for (int j = i + 1; j < size; j++) {
        	if (arr[j] > arr[max_idx]) {
            	max_idx = j;
        	}
    	}
    	int temp = arr[i];
    	arr[i] = arr[max_idx];
    	arr[max_idx] = temp;
	}
}
int main() {
	int data[100], n;
	printf("Enter number of elements: ");
	scanf("%d", &n);
 
	printf("Enter %d elements:\n", n);
	for (int i = 0; i < n; i++) {
    	scanf("%d", &data[i]);
	}
	descending(data, n);
	printf("Sorted Array in Descending Order:\n");
	for (int i = 0; i < n; i++) {
    	printf("%d ", data[i]);
	}
 
	return 0;
}
