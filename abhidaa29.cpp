#include <stdio.h>

#define INF 999999


int min(int a, int b) {
    return (a < b) ? a : b;
}

int findOptimalCost(int cost[], int n) {
    int dp[n];  
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        dp[i] = INF;
        for (int j = 0; j < i; j++) {
            if (j + cost[j] >= i) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    return dp[n - 1];
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int cost[n];
    printf("Enter the costs for each position in the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &cost[i]);
    }
    int optimalCost = findOptimalCost(cost, n);

    printf("The optimal cost to reach the end is: %d\n", optimalCost);

    return 0;
}

