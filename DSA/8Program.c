#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node {
    char data;
    struct node *left, *right;
};
typedef struct node *NODE;

struct stack {
    int top;
    NODE data[10];
};
typedef struct stack STACK;

void push(STACK *s, NODE item) {
    s->data[++(s->top)] = item;
}

NODE pop(STACK *s) {
    return s->data[(s->top)--];
}

int preced(char symbol) {
    switch(symbol) {
        case '^':return 5;
        case '*':
        case '/':return 3;
        case '+':
        case '-':return 1;
    }
}

NODE createnode(char item) {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void preorder(NODE root) {
    if(root != NULL) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

void postorder(NODE root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

NODE create_expr_tree(NODE root, char infix[10]) {
    STACK TS, OS;
    TS.top = OS.top = -1;
    int i;
    char symbol;
    NODE temp, t;
    for(i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];
        temp = createnode(symbol);
        if(isalnum(symbol))
            push(&TS, temp);
        else {
            if(OS.top == -1)
                push(&OS, temp);
            else {
                while(OS.top != -1 && preced(OS.data[OS.top]->data) >= preced(symbol)) {
                    t = pop(&OS);
                    t->right = pop(&TS);
                    t->left = pop(&TS);
                    push(&TS, t);
                }
                push(&OS, temp);
            }
        }
    }
    while(OS.top != -1) {
        t = pop(&OS);
        t->right = pop(&TS);
        t->left = pop(&TS);
        push(&TS, t);
    }
    return pop(&TS);
}

int main() {
    char infix[10];
    NODE root = NULL;
    printf("Read the infix expression :");
    scanf("%s", infix);
    root = create_expr_tree(root, infix);
    printf("\nThe preorder traversal is: ");
    preorder(root);
    printf("\nThe inorder traversal is: ");
    inorder(root);
    printf("\nThe postorder traversal is: ");
    postorder(root);
}