#include <stdio.h>

#define MAX_CONTAINERS 100
#define MAX_ITEMS 100
void containerLoading(int containers[], int items[], int numContainers, int numItems) {
    int containerIndex = 0;

    for (int i = 0; i < numItems; i++) {
        if (containers[containerIndex] >= items[i]) {
            containers[containerIndex] -= items[i];
            printf("Item %d fits into Container %d\n", i + 1, containerIndex + 1);
        } else {
            containerIndex++;
            if (containerIndex >= numContainers) {
                printf("Not enough containers for all items\n");
                return;
            }
            containers[containerIndex] -= items[i];
            printf("Item %d fits into Container %d\n", i + 1, containerIndex + 1);
        }
    }
}

int main() {
    int numContainers, numItems;
    printf("Enter the number of containers: ");
    scanf("%d", &numContainers);
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    
    int containers[MAX_CONTAINERS];
    printf("Enter the capacities of %d containers:\n", numContainers);
    for (int i = 0; i < numContainers; i++) {
        scanf("%d", &containers[i]);
    }


    int items[MAX_ITEMS];
    printf("Enter the weights/volumes of %d items:\n", numItems);
    for (int i = 0; i < numItems; i++) {
        scanf("%d", &items[i]);
    }
    containerLoading(containers, items, numContainers, numItems);

    return 0;
}

