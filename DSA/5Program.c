#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int count = 0;

struct node {
    int data;
    struct node *next;
};
typedef struct node *NODE;

NODE insertend(NODE last, int item) {
    NODE temp;
    if(count >= SIZE) {
        printf("\nQueue full\n");
        return last;
    }
    count++;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    if(last == NULL) {
        temp->next = temp;
        return temp;
    }
    temp->next = last->next;
    last->next = temp;
    return temp;
}

NODE deletebegin(NODE last) {
    NODE temp;
    if(last == NULL) {
        printf("\nQueue empty");
        return NULL;
    }
    count--;
    if(last->next == last) {
        printf("\nElement deleted is %d\n", last->data);
        free(last);
        return NULL;
    }
    temp = last->next;
    last->next = temp->next;
    printf("\nElement deleted is %d\n", temp->data);
    free(temp);
    return last;
}

void display(NODE last) {
    NODE temp;
    if(last == NULL) {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nQueue Content are\n");
    temp = last->next;
    while(temp != last) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d\t", temp->data);
    printf("\n");
}

int main() {
    NODE last = NULL;
    int item, ch;
    for(;;) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
        printf("\nRead Choice :");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Read data to be inserted:");
                scanf("%d", &item);
                last = insertend(last, item);
                break;
            case 2:
                last = deletebegin(last);
                break;
            case 3:
                display(last);
                break;
            case 4:
                exit(0);
            default: 
                printf("\nInvalid choice\n");
        }
    }
}