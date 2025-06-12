#include<stdio.h>
#include<stdlib.h>
#define max 5
#define true 1
#define false 0



struct stack {
    int tos;
    float data[max];
};
int IsFull(struct stack *s);
int IsEmpty(struct stack *s);
void Push(struct stack *s, float element);
float pop(struct stack *s);

int main() {
    struct stack s;
    s.tos = -1;
    float element;
    int choice;

    while (1) {
        {printf("1. CheckIsFull\n2. CheckIsEmpty\n3. PushElement\n4. PopElement\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        }
        switch (choice) {
            case 1: 
                if (IsFull(&s))
                    printf("Stack is Full.\n");
                else
                    printf("Stack is not Full.\n");
                break;
            case 2:
                if (IsEmpty(&s))
                    printf("Stack is Empty.\n");
                else
                    printf("Stack is not Empty.\n");
                break;
            case 3:
                printf("Enter the Element to Push: ");
                scanf("%f", &element);
                Push(&s, element);
                break;
            case 4:
                if (!IsEmpty(&s)) {
                    element = pop(&s);
                    printf("Popped element: %.2f\n", element);
                } else {
                    printf("Stack Underflow\n");
                }
                break;
            case 5: 
                exit(0);
            default:
                printf("Invalid input\n");
                return 0;
        }
    }

    return 0;
}


int IsFull(struct stack *s) {
    if (s->tos == max - 1) {
        return true;
    } else {
        return false;
    }
}

int IsEmpty(struct stack *s) {
    if (s->tos == -1) {
        return true;
    } else {
        return false;
    }
}

void Push(struct stack *s, float element) {
    if (s->tos==max-1) {
        printf("Stack Overflow\n");
    } else {
        s->tos++;
        s->data[s->tos] = element;
        printf("Pushed: %.2f\n", element);
    }
}

float pop(struct stack *s) {
    if (s->tos == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else { 
        float element = s->data[s->tos];
        s->tos--;
        return element;    
    }
}
