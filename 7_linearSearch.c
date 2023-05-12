#include <stdio.h>

int linear_search(int arr[], int n, int key) {
    // Iterate over each element of the array
    for (int i = 0; i < n; i++) {
        // If the current element matches the key, return its index
        if (arr[i] == key) {
            return i;
        }
    }
    // If the key was not found, return -1
    return -1;
}

int main() {
    int arr[] = {3, 9, 4, 7, 2, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 2;

    // Call the linear search function to find the index of the key
    int result = linear_search(arr, n, key);

    // Print the result of the search
    if (result == -1) {
        printf("The key was not found in the array.\n");
    } else {
        printf("The key was found at index %d.\n", result);
    }

    return 0;
}
