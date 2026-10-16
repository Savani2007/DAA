#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack01(int n, int values[], int weights[], int capacity) {
    int dp[capacity + 1];
    int i, w;

    for (w = 0; w <= capacity; w++)
        dp[w] = 0;

    for (i = 0; i < n; i++) {
        for (w = capacity; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    return dp[capacity];
}

int main() {
    int n, i, capacity;

    scanf("%d", &n);

    int values[n];
    int weights[n];

    for (i = 0; i < n; i++)
        scanf("%d", &values[i]);

    for (i = 0; i < n; i++)
        scanf("%d", &weights[i]);

    scanf("%d", &capacity);

    int result = knapsack01(n, values, weights, capacity);

    printf("%d\n", result);

    return 0;
}
