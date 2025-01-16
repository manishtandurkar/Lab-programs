#include<stdio.h>
#include<stdlib.h>

struct node {
    int co, po;
    struct node *addr;
};
typedef struct node *NODE;

NODE insertend(NODE start, int co, int po) {
    NODE temp, curr;
    temp = (NODE)malloc(sizeof(struct node));
    temp->co = co;
    temp->po = po;
    temp->addr = NULL;
    if(start == NULL)
        return temp;
    curr = start;
    while(curr->addr != NULL)
        curr = curr->addr;
    curr->addr = temp;
    return start;
}

void display(NODE start) {
    NODE temp;
    if(start == NULL)
        printf("Polynomial empty\n");
    else {
        temp = start;
        while(temp->addr != NULL){
            printf("%dx^%d + ", temp->co, temp->po);
            temp = temp->addr;
        }
        printf("%dx^%d\n", temp->co, temp->po);
    }
}

NODE addterm(NODE res, int co, int po) {
    NODE temp, curr;
    temp = (NODE)malloc(sizeof(struct node));
    temp->co = co;
    temp->po = po;
    temp->addr = NULL;
    if(res == NULL)
        return temp;
    curr = res;
    while(curr != NULL) {
        if(curr->po == po) {
            curr->co = curr->co + co;
            return res;
        }
        curr = curr->addr;
    }
    if(curr == NULL)
        res = insertend(res, co, po);
    return res;
}

NODE multiply(NODE poly1, NODE poly2) {
    NODE p1, p2, res = NULL;
    for(p1 = poly1; p1 != NULL; p1 = p1->addr)
        for(p2 = poly2; p2 != NULL; p2 = p2->addr)
            res = addterm(res, p1->co*p2->co, p1->po+p2->po);
    return res;
}

int main() {
    NODE poly1 = NULL, poly2 = NULL, poly;
    int co, po;
    int i, n, m;
    printf("Read number of terms of polynomial 1: ");
    scanf("%d", &n);
    for(i=1; i<=n; i++) {
        printf("Read CO and PO of %d term: ", i);
        scanf("%d %d", &co, &po);   
        poly1 = insertend(poly1, co, po);
    }
    printf("First polynomial is: ");
    display(poly1);
    printf("Read number of terms of polynomial 2: ");
    scanf("%d", &m);
    for(i=1; i<=m; i++) {
        printf("Read CO and PO of %d term: ", i);
        scanf("%d %d", &co, &po);   
        poly2 = insertend(poly2, co, po);
    }
    printf("Second polynomial is: ");
    display(poly2);
    poly = multiply(poly1, poly2);
    printf("Resultant polynomial is: ");
    display(poly);
}