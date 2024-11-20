#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
    struct node *prev;
};
typedef struct node *NODE;

NODE getnode() {
    NODE ptr;
    ptr = (NODE)malloc(sizeof(struct node));

    if (ptr == NULL) {
        printf("Memory not allocated\n");
        return NULL;
    }
    return ptr;
}

NODE insert_last(int item, NODE first) {
    NODE new = getnode();
    if (new == NULL) return first;

    new->value = item;
    new->next = NULL;
    new->prev = NULL;

    if (first == NULL) {
        return new;
    }

    NODE current = first;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new;
    new->prev = current;  // Set the previous pointer for the new node
    return first;
}

NODE insert_left(NODE first, int item, int key) {
    NODE new, current;
    new = getnode();
    new->value = item;
    new->next = NULL;
    new->prev = NULL;

    if (first == NULL) {
        printf("List is empty\n");
        return first;
    }

    current = first;
    while (current != NULL && current->value != key) {
        current = current->next;
    }

    if (current != NULL && current->value == key) {
        new->next = current;
        new->prev = current->prev;

        if (current->prev != NULL) {
            current->prev->next = new;
        } else {
            first = new;  // New node becomes the first if current is the first node
        }

        current->prev = new;
        return first;
    } else {
        printf("Value not found\n");
        return first;
    }
}

NODE delete_value(NODE first, int key) {
    NODE current = first;

    if (first == NULL) {
        printf("Doubly Linked List is empty\n");
        return NULL;
    }

    while (current != NULL && current->value != key) {
        current = current->next;
    }

    if (current != NULL && current->value == key) {
        if (current->prev != NULL) {
            current->prev->next = current->next;
        } else {
            first = current->next;  // Update first if we are deleting the first node
        }

        if (current->next != NULL) {
            current->next->prev = current->prev;
        }

        free(current);
        return first;
    } else {
        printf("Value not found\n");
        return first;
    }
}

void display(NODE first) {
    if (first == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    NODE temp = first;
    while (temp != NULL) {
        printf("%d <-> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    NODE head = NULL;
    int choice, item, key;

    do {
        printf("1. Insert Last ");
        printf("2. Insert at left ");
        printf("3. Delete Value ");
        printf("4. Display list ");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at end: ");
                scanf("%d", &item);
                head = insert_last(item, head);
                break;
            case 2:
                printf("Enter value to insert at left: ");
                scanf("%d", &item);
                printf("Enter key to insert before: ");
                scanf("%d", &key);
                head = insert_left(head, item, key);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                head = delete_value(head, key);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
