#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};
typedef struct node *NODE;

NODE getnode() {
    NODE ptr = (NODE)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory not allocated\n");
        return NULL;
    }
    return ptr;
}

NODE insert_beg(int item, NODE first) {
    NODE new = getnode();
    if (new == NULL)
    {
        return first;
    }

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

NODE delete_first(NODE first) {
    if (first == NULL) {
        printf("Linked List is empty\n");
        return NULL;
    }

    NODE temp = first;
    first = first->next;
    free(temp);
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
    NODE stackHead = NULL;
    NODE queueHead = NULL;
    int choice, value;

    do {
        printf("\nChoose operation:\n");
        printf("1. Stack - Push ");
        printf("2. Stack - Pop ");
        printf("3. Queue - Enqueue ");
        printf("4. Queue - Dequeue ");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter value to push onto stack: ");
                scanf("%d", &value);
                stackHead = insert_beg(value, stackHead);
                break;
            }
            case 2: {
                stackHead = delete_first(stackHead);
                break;
            }
            case 3: {
                printf("Enter value to enqueue into queue: ");
                scanf("%d", &value);
                queueHead = insert_last(value, queueHead);
                break;
            }
            case 4: {
                queueHead = delete_first(queueHead);
                break;
            }
            case 5: {
                printf("Stack: ");
                display(stackHead);
                printf("Queue: ");
                display(queueHead);
                break;
            }
            case 6: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice!\n");
                break;
            }
        }
    } while (choice != 6);

    return 0;
}

