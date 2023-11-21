#include <stdio.h>
#include <limits.h>

#define N 4

int minCost; 
int calculateCost(int assignmentMatrix[N][N], int assignment[N]) {
    int cost = 0;
    for (int i = 0; i < N; i++) {
        cost += assignmentMatrix[i][assignment[i]];
    }
    return cost;
}
int isAssigned(int assignment[N], int task) {
    for (int i = 0; i < N; i++) {
        if (assignment[i] == task) {
            return 1;
        }
    }
    return 0;
}

void branchAndBoundUtil(int assignmentMatrix[N][N], int level, int assignment[N]) {
    if (level == N) {
        int currentCost = calculateCost(assignmentMatrix, assignment);
        if (currentCost < minCost) {
            minCost = currentCost;
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!isAssigned(assignment, i)) {
            assignment[level] = i;
            branchAndBoundUtil(assignmentMatrix, level + 1, assignment);
            assignment[level] = -1; 
        }
    }
}

void branchAndBound(int assignmentMatrix[N][N]) {
    int assignment[N];
    for (int i = 0; i < N; i++) {
        assignment[i] = -1; 
    }
    minCost = INT_MAX;

    branchAndBoundUtil(assignmentMatrix, 0, assignment);

    printf("Minimum cost of assignment: %d\n", minCost);
}

int main() {
    int assignmentMatrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    branchAndBound(assignmentMatrix);

    return 0;
}

