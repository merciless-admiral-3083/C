#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int next[MAX];
    int head;
    int free;
} SinglyLinkedList;

void initializeList(SinglyLinkedList* list) {
    list->head = -1;
    list->free = 0;
    for (int i = 0; i < MAX - 1; i++) {
        list->next[i] = i + 1;
    }
    list->next[MAX - 1] = -1;
}

int allocateNode(SinglyLinkedList* list) {
    if (list->free == -1) {
        printf("List is full!\n");
        return -1;
    }
    int newNode = list->free;
    list->free = list->next[newNode];
    return newNode;
}

void freeNode(SinglyLinkedList* list, int node) {
    list->next[node] = list->free;
    list->free = node;
}

void insertAtBeginning(SinglyLinkedList* list, int value) {
    int newNode = allocateNode(list);
    if (newNode == -1) return;
    list->data[newNode] = value;
    list->next[newNode] = list->head;
    list->head = newNode;
}

void insertAtEnd(SinglyLinkedList* list, int value) {
    int newNode = allocateNode(list);
    if (newNode == -1) return;
    list->data[newNode] = value;
    list->next[newNode] = -1;
    if (list->head == -1) {
        list->head = newNode;
    } else {
        int temp = list->head;
        while (list->next[temp] != -1) {
            temp = list->next[temp];
        }
        list->next[temp] = newNode;
    }
}

void insertAfterElement(SinglyLinkedList* list, int after, int value) {
    int temp = list->head;
    while (temp != -1 && list->data[temp] != after) {
        temp = list->next[temp];
    }
    if (temp == -1) {
        printf("Element %d not found!\n", after);
        return;
    }
    int newNode = allocateNode(list);
    if (newNode == -1) return;
    list->data[newNode] = value;
    list->next[newNode] = list->next[temp];
    list->next[temp] = newNode;
}

void deleteAtBeginning(SinglyLinkedList* list) {
    if (list->head == -1) {
        printf("List is empty!\n");
        return;
    }
    int temp = list->head;
    list->head = list->next[temp];
    freeNode(list, temp);
}

void deleteAtEnd(SinglyLinkedList* list) {
    if (list->head == -1) {
        printf("List is empty!\n");
        return;
    }
    if (list->next[list->head] == -1) {
        freeNode(list, list->head);
        list->head = -1;
        return;
    }
    int temp = list->head;
    while (list->next[list->next[temp]] != -1) {
        temp = list->next[temp];
    }
    freeNode(list, list->next[temp]);
    list->next[temp] = -1;
}

void deleteAfterElement(SinglyLinkedList* list, int after) {
    int temp = list->head;
    while (temp != -1 && list->data[temp] != after) {
        temp = list->next[temp];
    }
    if (temp == -1 || list->next[temp] == -1) {
        printf("No element to delete after %d!\n", after);
        return;
    }
    int nodeToDelete = list->next[temp];
    list->next[temp] = list->next[nodeToDelete];
    freeNode(list, nodeToDelete);
}

void displayInReverseOrder(SinglyLinkedList* list, int index) {
    if (index == -1) return;
    displayInReverseOrder(list, list->next[index]);
    printf("%d ", list->data[index]);
}

void displayList(SinglyLinkedList* list) {
    printf("List: ");
    int temp = list->head;
    while (temp != -1) {
        printf("%d ", list->data[temp]);
        temp = list->next[temp];
    }
    printf("\n");
}

int main() {
    SinglyLinkedList list;
    initializeList(&list);

    insertAtBeginning(&list, 10);
    insertAtEnd(&list, 20);
    insertAtEnd(&list, 30);
    insertAfterElement(&list, 20, 25);
    displayList(&list);

    deleteAtBeginning(&list);
    displayList(&list);

    deleteAtEnd(&list);
    displayList(&list);

    deleteAfterElement(&list, 20);
    displayList(&list);

    printf("Reverse order: ");
    displayInReverseOrder(&list, list.head);
    printf("\n");

    return 0;
}
