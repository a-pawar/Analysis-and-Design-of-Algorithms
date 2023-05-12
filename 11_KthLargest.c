#include <stdio.h>

int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] >= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;
    return i+1;
}

int kthLargest(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int pivot = partition(arr, l, r);
        if (pivot-l == k-1) {
            return arr[pivot];
        }
        if (pivot-l > k-1) {
            return kthLargest(arr, l, pivot-1, k);
        }
        return kthLargest(arr, pivot+1, r, k-pivot+l-1);
    }
    return -1;
}

int main() {
    int arr[] = {10, 5, 20, 8, 15, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int kth = kthLargest(arr, 0, n-1, k);
    if (kth != -1) {
        printf("The %dth largest element in the array is %d", k, kth);
    } else {
        printf("Invalid input");
    }
    return 0;
}
