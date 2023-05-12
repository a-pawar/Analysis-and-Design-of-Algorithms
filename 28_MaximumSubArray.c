#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int max_subarray_sum(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }
    int mid = (low + high) / 2;
    int left_sum = -999999, right_sum = -999999, sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }
    int max_left_right_sum = max(max_subarray_sum(arr, low, mid), max_subarray_sum(arr, mid + 1, high));
    return max(max_left_right_sum, left_sum + right_sum);
}

int main() {
    int arr[] = { -2, -5, 6, -2, -3, 1, 5, -6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = max_subarray_sum(arr, 0, n - 1);
    printf("Maximum subarray sum is: %d", max_sum);
    return 0;
}
