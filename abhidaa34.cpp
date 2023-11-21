#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100


void printSubset(int subset[], int size) {
    printf("Subset: { ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}


void subsetSumUtil(int set[], int n, int subset[], int subsetSize, int targetSum, int currentSum, int index) {
    if (currentSum == targetSum) {
        printSubset(subset, subsetSize);
        return;
    }

    for (int i = index; i < n; i++) {
        if (currentSum + set[i] <= targetSum) {
            subset[subsetSize] = set[i];
            subsetSumUtil(set, n, subset, subsetSize + 1, targetSum, currentSum + set[i], i + 1);
        }
    }
}


void subsetSum(int set[], int n, int targetSum) {
    int subset[MAX_SIZE];
    subsetSumUtil(set, n, subset, 0, targetSum, 0, 0);
}

int main() {
    int n, targetSum;

    
    printf("Enter the size of the set: ");
    scanf("%d", &n);

    int set[MAX_SIZE];


    printf("Enter %d elements of the set:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    
    subsetSum(set, n, targetSum);

    return 0;
}

