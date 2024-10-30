#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
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

NODE insert_beg(int item, NODE first) {
    NODE new = getnode();
    if (new == NULL) return first;

    new->value = item;
    new->next = first;
    return new;
}

NODE insert_last(int item, NODE first) {
    NODE new = getnode();
    if (new == NULL) return first;

    new->value = item;
    new->next = NULL;

    if (first == NULL) {
        return new;
    }

    NODE current = first;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new;
    return first;
}

NODE insert_pos(NODE first, int item, int pos) {
    NODE new = getnode();
    if (new == NULL) return first;

    new->value = item;
    new->next = NULL;

    if (pos == 1) {
        new->next = first;
        return new;
    }

    NODE current = first;
    for (int count = 1; current != NULL && count < pos - 1; count++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position, element can't be inserted\n");
        free(new);
        return first;
    }

    new->next = current->next;
    current->next = new;
    return first;
}

void display(NODE first) {
    if (first == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    NODE temp = first;
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    NODE head = NULL;
    int choice, item, position;

    do {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &item);
                head = insert_beg(item, head);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &item);
                head = insert_last(item, head);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &item);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insert_pos(head, item, position);
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

