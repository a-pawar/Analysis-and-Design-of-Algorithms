#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int x) {
    // Repeat until the left index is less than or equal to the right index
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if the element is present at the middle itself
        if (arr[mid] == x) {
            return mid;
        }
        
        // If x is greater, ignore left half
        if (arr[mid] < x) {
            left = mid + 1;
        }
        
        // If x is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }
    
    // If we reach here, then the element was not present in the array
    return -1;
}

// Main function
int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 23;
    
    // Call binary search function
    int result = binarySearch(arr, 0, n - 1, x);
    
    // Print result
    if (result == -1) {
        printf("Element is not present in array\n");
    }
    else {
        printf("Element is present at index %d\n", result);
    }
    
    return 0;
}
