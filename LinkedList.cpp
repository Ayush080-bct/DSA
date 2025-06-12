#include <iostream>
using namespace std;

struct sll {
    int data;
    sll* Next; // Self-referential structure
};

// Declare global pointers
sll* first = NULL;
sll* last = NULL;

// Insertion at the beginning
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

// Traversal function to see the list
void display() {
    sll* temp = first;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->Next;
    }
    cout << "NULL" << endl;
}

int main() {
    int a;
    char ch;

    cout << "Enter data into the linked list:\n";

    do {
        cout << "Enter value: ";
        cin >> a;
        insertion(a);

        cout << "Add another node? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    cout << "Linked list contents:\n";
    display();

    return 0;
}
