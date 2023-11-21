#include <stdio.h>
void findMinMaxSequences(int arr[], int size) {
    if (size <= 0) {
        printf("Empty list\n");
        return;
    }

    int min = arr[0];
    int max = arr[0];
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }

        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }

    
    printf("Minimum value: %d\n", min);
    printf("Sequence for minimum value: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
        if (i == minIndex) {
            printf("(MIN) ");
        }
    }
    printf("\n");

    
    printf("Maximum value: %d\n", max);
    printf("Sequence for maximum value: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
        if (i == maxIndex) {
            printf("(MAX) ");
        }
    }
    printf("\n");
}

int main() {
    int size;


    printf("Enter the size of the array: ");
    scanf("%d", &size);

    
    int arr[size];
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    findMinMaxSequences(arr, size);

    return 0;
}

