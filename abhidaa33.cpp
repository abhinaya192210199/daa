#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};


struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}
void printList(struct Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int number;
    printf("Enter a number to insert into the list: ");
    scanf("%d", &number);
    head = insertAtBeginning(head, number);
    printList(head);

    return 0;
}

