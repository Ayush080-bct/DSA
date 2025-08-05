//Circular Queue
#include <stdio.h>
#include <stdlib.h>
#define max 5
#define true 1
#define false 0

struct QUEUE {
    int FRONT;
    int REAR;
    float data[max];
};

int IsFull(struct QUEUE *Q);
int IsEmpty(struct QUEUE *Q);
void EnQueue(struct QUEUE *Q, float element);
float DeQueue(struct QUEUE *Q);
void Display(struct QUEUE *Q);
int Search(struct QUEUE *Q, float key);

int main() {
    struct QUEUE Q = {-1, -1};
    float element;
    int choice;

    while (1) {
        printf(
            "\n1. CheckIsFull\n2. CheckIsEmpty\n3. EnQueue\n4. DeQueueElement\n"
            "5. Display\n6. Search\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (IsFull(&Q))
                    printf("QUEUE is Full.\n");
                else
                    printf("QUEUE is not Full.\n");
                break;
            case 2:
                if (IsEmpty(&Q))
                    printf("QUEUE is Empty.\n");
                else
                    printf("QUEUE is not Empty.\n");
                break;
            case 3:
                printf("Enter the Element to Push: ");
                scanf("%f", &element);
                EnQueue(&Q, element);
                break;
            case 4:
                if (!IsEmpty(&Q)) {
                    element = DeQueue(&Q);
                    printf("DeQueue element: %.2f\n", element);
                } else {
                    printf("QUEUE Underflow\n");
                }
                break;
            case 5:
                Display(&Q);
                break;
            case 6:
                printf("Enter the element to be searched: ");
                scanf("%f", &element);
                if (Search(&Q, element))
                    printf("%.2f Found!\n", element);
                else
                    printf("%.2f Not Found!\n", element);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid input\n");
                break;
        }
    }

    return 0;
}

int IsFull(struct QUEUE *Q) {
    return ((Q->FRONT == (Q->REAR + 1) % max));
}

int IsEmpty(struct QUEUE *Q) {
    return (Q->FRONT == -1);
}

void EnQueue(struct QUEUE *Q, float element) {
    if (IsFull(Q)) {
        printf("QUEUE IS FULL!\n");   
        return;
    }

    if (IsEmpty(Q)) {
        Q->FRONT = Q->REAR = 0;
    } else {
        Q->REAR = (Q->REAR + 1) % max;
    }

    Q->data[Q->REAR] = element;
    printf("EnQueue: %.2f\n", element);
}

float DeQueue(struct QUEUE *Q) {
    if (IsEmpty(Q)) {
        printf("QUEUE Underflow\n");
        return -1;
    }

    float element = Q->data[Q->FRONT];

    if (Q->FRONT == Q->REAR) {
    
        Q->FRONT = Q->REAR = -1;
    } else {
        Q->FRONT = (Q->FRONT + 1) % max;
    }

    return element;
}

void Display(struct QUEUE *Q) {
    if (IsEmpty(Q)) {
        printf("QUEUE is Empty.\n");
        return;
    }

    printf("QUEUE elements: ");
    int i = Q->FRONT;
    while (1) {
        printf("[ %.2f ] ", Q->data[i]);
        if (i == Q->REAR)
            break;
        i = (i + 1) % max;
    }
    printf("\n");
}

int Search(struct QUEUE *Q, float key) {
    if (IsEmpty(Q)) return 0;

    int i = Q->FRONT;
    while (1) {
        if (Q->data[i] == key)
            return 1;
        if (i == Q->REAR)
            break;
        i = (i + 1) % max;
    }

    return 0;
}
