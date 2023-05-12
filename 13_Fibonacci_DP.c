#include <stdio.h>

// Function to find the nth Fibonacci number
int fibonacci(int n)
{
    int f[n + 1];
    int i;

    // Base cases
    f[0] = 0;
    f[1] = 1;

    // Build the Fibonacci sequence in bottom-up fashion
    for (i = 2; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];

    return f[n];
}

// Driver program to test above function
int main()
{
    int n = 9;

    printf("The %dth Fibonacci number is %d", n, fibonacci(n));

    return 0;
}
