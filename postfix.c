#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAXSIZE 100

struct stack {
    float data[MAXSIZE];
    int tos;
};

void push(struct stack *s, float element) {
    if (s->tos == MAXSIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->tos++;
    s->data[s->tos] = element;
}

float pop(struct stack *s) {
    if (s->tos == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[s->tos--];
}

int main() {
    struct stack s;
    s.tos = -1;
    char expression[200];

    printf("Enter postfix expression (space separated): ");
   
    fgets(expression,sizeof(expression),stdin);
 
    expression[strcspn(expression, "\n")] = '\0'; 

    char *token = strtok(expression, " ");//just like python function spilt ,it spilit the expression
    while (token != NULL) {
        if (isdigit(token[0]) || 
            (token[0] == '-' && isdigit(token[1]))) { 
            push(&s, atof(token));
        } else if (strlen(token) == 1) {
            float op1 = pop(&s);
            float op2 = pop(&s);
            float result;

            switch (token[0]) {
                case '+': result = op2 + op1; break;
                case '-': result = op2 - op1; break;
                case '*': result = op2 * op1; break;
                case '/': result = op2 / op1; break;
                case '^':
                case '$': result = pow(op2, op1); break;
                default:
                    printf("Invalid operator: %s\n", token);
                    return 1;
            }
            push(&s, result);
        } else {
            printf("Invalid token: %s\n", token);
            return 1;
        }

        token = strtok(NULL, " ");
    }

    printf("Result of postfix expression: %.2f\n", pop(&s));
    return 0;
}
