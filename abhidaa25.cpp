#include <stdio.h>
#include <limits.h>

#define MAX_N 10

int n; // Number of cities
int dist[MAX_N][MAX_N]; // Distance matrix
int memo[MAX_N][1 << MAX_N]; // Memoization table

int tsp(int current, int mask) {
    if (mask == (1 << n) - 1)
        return dist[current][0];

    if (memo[current][mask] != -1)
        return memo[current][mask];

    int minDistance = INT_MAX;

    for (int next = 0; next < n; next++) {
        if ((mask & (1 << next)) == 0) {
            int newDistance = dist[current][next] + tsp(next, mask | (1 << next));
            minDistance = (newDistance < minDistance) ? newDistance : minDistance;
        }
    }

    return memo[current][mask] = minDistance;
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);

    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < (1 << MAX_N); j++)
            memo[i][j] = -1;

    int minDistance = tsp(0, 1);
    printf("Minimum distance: %d\n", minDistance);

    return 0;
}

