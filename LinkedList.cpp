#include <iostream>
using namespace std;

struct sll {
    int data;
    sll* Next; 
};


sll* first = NULL;
sll* last = NULL;

void insertion(int a) {
    sll* newnode = new sll();
    newnode->data = a;
    newnode->Next = NULL;

    if (first == NULL) {
        first = last = newnode;
    } else {
        newnode->Next = first;
        first = newnode;
    }
}

void display() {
    sll* temp = first;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->Next;
    }
    cout << "NULL" << endl;
}

int main() {
    insertion(5);

    display();

    return 0;
}
