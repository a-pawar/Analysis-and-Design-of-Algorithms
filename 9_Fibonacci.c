#include <stdio.h>

int fibonacci(int n) {
    // Base cases
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        // Divide the problem into two subproblems
        int left = fibonacci(n - 1);
        int right = fibonacci(n - 2);

        // Combine the results from the subproblems
        return left + right;
    }
}

int main() {
    // Test the function by computing the first 10 numbers in the sequence
    for (int i = 0; i < 10; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}
