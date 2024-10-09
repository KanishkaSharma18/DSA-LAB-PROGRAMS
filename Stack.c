#include<stdio.h>
#define STACK_SIZE 5

void push(int s[],int item,int *top){
    if(*top == STACK_SIZE-1){
        printf("Stack Overflow.");
    }
    else{
        *top=*top+1;
        s[*top]=item;
    }
}
int pop(int s[],int *top){
    if(*top==-1){
        printf("Stack Underflow.");
        return -1;
    }
    else{
        int item_deleted=s[*top];
        *top=*top-1;
        return item_deleted;
    }
}
void display(int s[],int *top){
    int i;
    if(*top==-1){
        printf("Stack is empty.Can't display.");
    }
    else{
        for(i=*top;i>=0;i--){
            printf("%d\t",s[i]);
        }
    }
}
void main(){
    int s[STACK_SIZE],top,item,choice,del;
    top=-1;
    while(1){
        printf("\nEnter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: {printf("Enter element to be inserted:");
                    scanf("%d",&item);
                    push(s,item,&top);
                    break;
                    }
            case 2: {del=pop(s,&top);
                    if(del!=-1){
                        printf("Item deleted: %d",del);
                    }

                    break;
                    }
            case 3: {display(s,&top);
                    break;
                    }
            default: {printf("Invalid choice.");
                     break;
                     }
        }
    }
}
