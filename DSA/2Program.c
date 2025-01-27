#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

#define SIZE 20

typedef struct stack {
    int top;
    float data[SIZE];
} STACK;

void push(STACK *s, float item) {
    s->data[++(s->top)] = item;
}

float pop(STACK *s) {
    return s->data[(s->top)--];
}

float operate(float op1, float op2, char symbol) {
    switch(symbol) {
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '*': return op1*op2;
        case '/': return op1/op2;
        case '^': return pow(op1,op2);
    }
}

float eval(STACK *s, char prefix[]) {
    int i;
    char symbol;
    float res, op1, op2;
    for(i = strlen(prefix)-1; i>=0; i--) {
        symbol = prefix[i];
        if(isdigit(symbol))
           push(s, symbol - '0');
        else {
            op1 = pop(s);
            op2 = pop(s);
            res = operate(op1, op2, symbol);
            push(s, res);
        }
    }
    return pop(s);
}

int main() {
    char prefix[SIZE];
    STACK s;
    float ans;
    s.top = -1;
    printf("Enter prefix expression: ");
    scanf("%s", prefix);
    ans = eval(&s, prefix);
    printf("The final answer is %f\n", ans);
}