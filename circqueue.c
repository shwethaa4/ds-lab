#include <stdio.h>
#include <stdlib.h>
#define size 4

void enqueue(int);
void dequeue();
void display();

int cir_queue[size];
int front = -1, rear = -1;

int isfull()
{
    return (front == (rear + 1) % size);
}

int isempty()
{
    return (front == -1);
}

void enqueue(int value)
{
    if(isfull())
    {
        printf("\nQueue is full...");
        return;
    }
    if(front == -1)
        front = 0;
    rear = (rear + 1) % size;
    cir_queue[rear] = value;
    printf("\n%d inserted.", value);
}

void dequeue()
{
    int element;
    if(isempty())
    {
        printf("\nQueue is empty...");
        return;
    }
    element = cir_queue[front];
    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
    printf("\n%d is deleted..", element);
}

void display()
{
    int i;
    if(isempty())
    {
        printf("\nQueue is empty..");
        return;
    }
    printf("\nThe elements are:\n");
    i = front;
    while(1)
    {
        printf("%d\t", cir_queue[i]);
        if(i == rear)
            break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main()
{
    int choice, value;
    printf("\n-------------- Circular Queue --------------\n");
    printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting...");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}
