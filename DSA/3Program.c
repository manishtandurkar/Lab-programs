#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 5

typedef struct queue {
    int front, rear;
    char data[SIZE][20];
} QUEUE;

void send(QUEUE *q, char item[20]) {
    if(q->front == (q->rear + 1)%SIZE) {
        printf("Queue full\n");
        return;
    }
    q->rear = (q->rear + 1)%SIZE;
    strcpy(q->data[q->rear], item);
    if(q->front == -1)
        q->front = 0;
}

char *receive(QUEUE *q) {
    char *del;
    if(q->front == -1) {
        printf("Queue empty\n");
        return NULL;
    }
    del = q->data[q->front];
    if(q->front == q->rear) 
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1)%SIZE;
    return del;
}

void display(QUEUE *q) {
    int i;
    if(q->front == -1)
        printf("Queue empty\n");
    else {
        printf("\n");
        for(i = q->front; i != q->rear; i = (i + 1)%SIZE)
            printf("%s ", q->data[i]);
        printf("%s\n", q->data[i]);
    }
}

int main() {
    int ch;
    char *del;
    char item[20];
    QUEUE q;
    q.front = q.rear = -1;
    for(;;) {
        printf("\n1. Send\n2. Receive\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        getchar();
        switch(ch) {
            case 1:
                printf("\nRead message to send: ");
                gets(item);
                send(&q, item);
                break;
            case 2:
                del = receive(&q);
                if(del != NULL)
                    printf("\nElement deleted is %s\n", del);
                break;
            case 3:
                display(&q);
                break;
            default:
                printf("Exiting....\n");
                exit(0);
        }
    }
}