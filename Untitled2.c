#include<stdio.h>
#define max 5

int queue[max];
int front=-1;
int rear=-1;

void enqueue();
void dequeue();
void display();

int main(){
    int choice;
    while(1){
        printf("menu");
        printf("1.enqueue");
        printf("2.dequeue");
        printf("3.display");
        printf("4.exit");
        printf("enter choice(1-4)");
        scanf("%d",&choice);

        switch(choice){
            case 1:enqueue();
                    break;
            case 2:dequeue();
                    break;
            case 3:display();
                    break;
            case 4:return 0;

            default:printf("Invalid choice");
         }
}
}
void enqueue(){
    int x;
    if (rear== max-1){
        printf("queue overflow");
    }
    else {
        if (front==-1){
            front=0;
        }
        printf("enter elements ");
        scanf("%d",&x);
        rear++;
        queue[rear]=x;
        printf("enqueued elements: ",x);
        }
}

void dequeue(){
    if (front==-1 || front>rear){
        printf("queue underflow");
    }
    else{
        queue[front++];
    }
}

void display(){
    if (rear==-1){
        printf("queue is empty");
    }
    else{
        int i;
        for (i=front;i<=rear;i++){
            printf("%d",queue[i]);
    }
    printf("\n");
    }
}


