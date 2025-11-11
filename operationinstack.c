#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int *arr;
    int size;
};
int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        printf("the stack is empty\n");
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        printf("the stack is full\n");
        return 1;
    }
    else{
        return 0;
    }
}
int push(struct stack *ptr,int val){
    if(isFull(ptr)){
        printf("stack overflow cannot push further items\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
        printf("%d pushed successfully\n",val);
    }
}
int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("stack underflow cannot pop further items\n");
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        printf("%d popped successfully\n ",val);
    }
}
void display(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("The stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = ptr->top; i >= 0; i--) {
            printf("%d ", ptr->arr[i]);
        }
        printf("\n");
    }
}
int main(){
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack ));
    sp->top=-1;
    sp->size=10;
    sp->arr=(int *)malloc(sp->size *sizeof(int));
     int choice, value;

    do {
        printf("\nstack implementation\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if stack is empty\n");
        printf("4. Check if stack is full\n");
        printf("5. Display stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(sp, value);
                break;
            case 2:
                pop(sp);
                break;
            case 3:
                if (isEmpty(sp)) {
                    printf("The stack is empty\n");
                } else {
                    printf("The stack is not empty\n");
                }
                break;
            case 4:
                if (isFull(sp)) {
                    printf("The stack is full\n");
                } else {
                    printf("The stack is not full\n");
                }
                break;
            case 5:
                display(sp);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }while (choice!=6);
}