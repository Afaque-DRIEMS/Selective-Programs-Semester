#include<stdio.h>

// Function to sort the array
void sortArray(int arr[], int n) {
    int i, j, min, temp;

    
    for (i = 0; i < n - 1; i++) {
        min = i; // Assume the minimum is the current element
        // 2nd for loop matches every element with 'min' to find the very minimum number among all
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;  // Update the index of the minimum element
            }
        }
        
       // If the 2nd for loop finds the minimum number than i, then i is swapped by that number and stored in 'min'
        if (min != i) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main() {
    int n, i;

    // Ask for the number of elements
    printf("Enter the total number of elements: ");
    scanf("%d", &n);

    // Declare the array of n element
    int arr[n];

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Print array before sorting
    printf("Before Sorting: \n");
    for (i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    //function call
    sortArray(arr, n);

    // Print array after sorting
    printf("After Sorting: \n");
    for (i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    return 0;
}
