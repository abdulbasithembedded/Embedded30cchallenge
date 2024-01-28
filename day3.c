#include <stdio.h>
#include <stdlib.h> // for dynamic memory allocation and deallocation

int main() {
    int n;
    int *arr;

    // Prompting the user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Dynamically allocating memory for the array
    arr = (int *)malloc(n * sizeof(int));
    
    // Checking if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // exit the program with an error code
    }

    // Prompting the user to enter elements of the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Displaying the elements of the array
    printf("Elements of the array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Freeing dynamically allocated memory
    free(arr);

    return 0;
}
