#include <stdio.h>
#define SIZE 5
void insert(int q[], int *front, int *rear, int item) {
if((*rear + 1)%SIZE==*front) {
        printf("Queue is full\n");
        return;
    }
    if(*rear==-1&&*front==-1) {
        *rear=0;
        *front=0;
    } else {
        *rear=(*rear + 1)%SIZE;
    }
    q[*rear]=item;
    printf("Inserted: %d\n", item);
}
int delete(int q[], int *front, int *rear) {
    if(*front == -1) {
        printf("Queue is underflow\n");
        return -1;
    }
    int ele_del=q[*front];
    if(*front==*rear){
        *front = -1;
        *rear = -1;
    }else{
        *front =(*front + 1)%SIZE;
    }
    printf("Item deleted:%d\n",ele_del);
    return ele_del;
}
void display(int q[], int *front, int *rear) {
    if (*front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Elements in the queue: ");
    for (int i=*front;; i=(i+1)%SIZE){
        printf("%d ", q[i]);
        if(i== *rear)break;
    }
    printf("\n");
}
int main() {
    int q[SIZE], front = -1, rear = -1, choice;
    while(1){
        printf("Enter the choice number 1.Insert 2.Delete 3.Display 4.Exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                int item;
                scanf("%d", &item);
                insert(q, &front, &rear, item);
                break;
            case 2:
                delete(q, &front, &rear);
                break;
            case 3:
                display(q, &front, &rear);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
