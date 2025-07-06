#include <iostream>
using namespace std;

class Dyanmic_stack {
private:
    int data;
    Dyanmic_stack* next;
    static Dyanmic_stack* Top;

public:
    Dyanmic_stack() : data(0), next(NULL) {}
    ~Dyanmic_stack() {}

    void push(int element) {
        Dyanmic_stack* newnode = new Dyanmic_stack();
        if (newnode == NULL) {
            cout << "Memory allocation failed\n";
            return;
        }
        newnode->data = element;
        newnode->next = Top;
        Top = newnode;
    }

    void pop() {
        if (Top == NULL) {
            cout << "Stack is empty!\n";
            return;
        }
        Dyanmic_stack* temp = Top;
        cout << "The pop data is " << temp->data << endl;
        Top = Top->next;
        delete temp;
    }

    void display() {
        Dyanmic_stack* temp = Top;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout<<"NULL";
        cout << endl;
    }
};

Dyanmic_stack* Dyanmic_stack::Top = NULL;

int main() {
    Dyanmic_stack s;
    s.push(10);
    s.push(20);
    s.push(1);
    s.display();
    s.pop();
    s.display();
    return 0;
}
