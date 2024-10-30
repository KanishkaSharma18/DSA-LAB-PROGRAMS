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

NODE delete_beg(NODE first) {
    if (first == NULL) {
        printf("Linked List is empty\n");
        return NULL;
    }
    NODE temp = first;
    first = first->next;
    free(temp);
    return first;
}

NODE delete_last(NODE first) {
    if (first == NULL) {
        printf("Linked List is empty\n");
        return NULL;
    }

    NODE prev = NULL, last = first;

    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }

    if (prev == NULL) {
        free(first);
        return NULL;
    }

    prev->next = NULL;
    free(last);
    return first;
}

NODE delete_pos(NODE first, int valuedel) {
    if (first == NULL) {
        printf("Linked List is empty\n");
        return NULL;
    }

    NODE prev = NULL, current = first;

    while (current != NULL && current->value != valuedel) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Value %d not found in the list\n", valuedel);
        return first;
    }

    if (prev == NULL) {
        first = first->next;
    } else {
        prev->next = current->next;
    }
    free(current);
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

NODE insert_end(NODE first, int value) {
    NODE new_node = getnode();
    if (new_node == NULL) return first;

    new_node->value = value;
    new_node->next = NULL;

    if (first == NULL) {
        return new_node;
    }

    NODE temp = first;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return first;
}

int main() {
    NODE head = NULL;
    int choice, value;

    do {
        printf("1.InsertAtEnd 2.DeleteFromBeginning 3.DeleteFromEnd 4.Deletebyvalue 5.Display 6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insert_end(head, value);
                break;
            case 2:
                head = delete_beg(head);
                break;
            case 3:
                head = delete_last(head);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = delete_pos(head, value);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
