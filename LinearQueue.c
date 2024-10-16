#include <stdio.h>
#define QUEUE_SIZE 5

void insert(int q[], int item, int *rear) {
    if (*rear == QUEUE_SIZE - 1) {
        printf("Queue overflow.\n");
        return;
    }
    (*rear)++;
    q[*rear] = item;
}

int delete(int q[], int *front, int rear) {
    if (*front > rear) {
        printf("Queue is empty.\n");
        return -1;
    }
    int del = q[*front];
    (*front)++;
    return del;
}

void display(int q[], int front, int rear) {
    if (front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

void main() {
    int q[QUEUE_SIZE];
    int front = 0, rear = -1, item, del, choice;

    while (1) {
        printf("\nEnter choice:\n 1) insert\n 2) delete\n 3) display\n 4) exit : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Enter item to be inserted: ");
                scanf("%d", &item);
                insert(q, item, &rear);
                break;
            }
            case 2: {
                del = delete(q, &front, rear);
                if (del != -1) {
                    printf("Item deleted: %d\n", del);
                }
                break;
            }
            case 3: {
                display(q, front, rear);
                break;
            }
            case 4: {
                return;
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    }
}
