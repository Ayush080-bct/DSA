#include <stdio.h>
#include <ctype.h>  // for isdigit()
#include <math.h>   // for pow()
#include <stdlib.h> 
#include<string.h>
#define MAXSIZE 10

struct stack {
    float data[MAXSIZE];
    int tos;
};

float pop(struct stack *s) {
    if (s->tos == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    float element = s->data[s->tos];
    s->tos--;
    return element;
}

void push(struct stack *s, float element) {
    if (s->tos == MAXSIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->tos++;
    s->data[s->tos] = element;
}

float evaluate_postfix(char *expression) {
    struct stack s;
    s.tos = -1;
    int i = 0;
    float op1, op2, result;

    while (expression[i] != '\0') {
        if (isdigit(expression[i])) {
            
            float num = 0;
            while (isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;  
            push(&s, num);
        } else if (expression[i] == ' ') {
          
            i++;
            continue;
        } else {
            op1 = pop(&s);
            op2 = pop(&s);

            switch (expression[i]) {
                case '+':
                    result = op2 + op1;
                    break;
                case '-':
                    result = op2 - op1;
                    break;
                case '*':
                    result = op2 * op1;
                    break;
                case '/':
                    if (op1 != 0) {
                        result = op2 / op1;
                    } else {
                        printf("Division by zero error!\n");
                        return -1;  
                    }
                    break;
                case '^': 
                    result = pow(op2, op1);
                    break;
                default:
                    printf("Invalid operator: %c\n", expression[i]);
                    return -1;  
            }


            push(&s, result);
        }
        i++;
    }

    
    return pop(&s);
}

int main() {
    char expression[100];

    printf("Enter the postfix expression: ");
    fgets(expression, sizeof(expression), stdin);

   
    expression[strcspn(expression, "\n")] = 0;

    float result = evaluate_postfix(expression);
    if (result != -1) {
        printf("Result of postfix expression: %.2f\n", result);
    }

    return 0;
}
