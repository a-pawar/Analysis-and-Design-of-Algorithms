#include <stdio.h>

int factorial(int n) {
    // base case: if n is 0 or 1, return 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // divide the problem into smaller subproblems
    int half_n = n / 2;
    // solve each subproblem recursively
    int fact_half_n = factorial(half_n);
    int fact_n_minus_half_n = factorial(n - half_n);
    // combine the solutions to the subproblems
    return fact_half_n * fact_n_minus_half_n;
}

int main() {
    // get user input for n
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    // compute the factorial of n using the recursive algorithm
    int fact = factorial(n);
    // print the result
    printf("%d! = %d\n", n, fact);
    return 0;
}
