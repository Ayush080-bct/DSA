
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
int Search(struct QUEUE *Q,float key);

int main() {
    struct QUEUE Q = {0, -1};
    float element;
    int a;
    int choice;

    while (1) {
        {
            printf(
                "1. CheckIsFull\n2. CheckIsEmpty\n3. EnQueue\n4. "
                "DeQueueElement\n5. Display \n6.Search\n7. Exit\n");
            printf("\nEnter your choice: ");
            scanf("%d", &choice);
        }
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
                a=Search(&Q, element);
                if(a==1)
                    printf("%f Found!\n ", element);
                else
                    printf("%f Not Found!\n ", element);
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
    if (Q->REAR == max - 1) {
        return true;
    } else {
        return false;
    }
}

int IsEmpty(struct QUEUE *Q) {
    if (Q->FRONT >Q->REAR) {
        return true;
    } else {
        return false;
    }
}

void EnQueue(struct QUEUE *Q, float element) {
    if (Q->REAR == max - 1) {
        printf("QUEUE IS FULL!\n");
    } else {
        Q->REAR++;
        Q->data[Q->REAR] = element;
        printf("EnQueue: %.2f\n", element);
    }
}

float DeQueue(struct QUEUE *Q) {
    if (IsEmpty(Q)) {
        printf("QUEUE Underflow\n");
        return -1;
    } else {
        float element = Q->data[Q->FRONT];
        Q->FRONT++;
        return element;
    }
}
void Display(struct QUEUE *Q) {
    if (IsEmpty(Q)) {
        printf("QUEUE is Empty.\n");
    } else {
        printf("QUEUE elements: ");
        for (int i = Q->FRONT; i <= Q->REAR; i++) {
            printf(" [ %.2f ] ", Q->data[i]);
        }
        printf("\n");
    }
}
int Search(struct QUEUE *Q, float key) {
    
    for (int i = Q->FRONT; i<Q->REAR; i++) {
        if (Q->data[i] == key) {
            return 1;
        }
        }

        return 0;
}