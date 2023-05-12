#include <stdio.h>

// Function to find the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, int wt[], int val[], int n)
{
    int i, j;
    int K[n + 1][W + 1];

    // Build K[][] in bottom-up fashion
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (wt[i - 1] <= j)
                K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]);
            else
                K[i][j] = K[i - 1][j];
        }
    }

    return K[n][W];
}

// Driver program to test above function
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum value that can be put in a knapsack of capacity %d is %d", W, knapsack(W, wt, val, n));

    return 0;
}
