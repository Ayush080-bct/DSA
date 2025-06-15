#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#define maxsize 10
using namespace std;

struct stack {
    int tos;
    float element[maxsize];
};

void push(struct stack*, float);
float pop(struct stack*);
bool isfull(struct stack*);
bool isempty(struct stack*);
void operate(struct stack*, char);

int main() {
    struct stack s = {-1};
    string input;
    cout << "Enter the postfix expression by seprating space : ";
    getline(cin, input);
    stringstream ss(input);
    string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "$") {
            operate(&s, token[0]);  // operator
        } else {
            try {
                float operand = stof(token);
                push(&s, operand);
            } catch (...) {
                cout << "Invalid token: " << token << endl;
                return 1;
            }
        }
    }

    cout << "The Resulting Output is: " << pop(&s) << endl;
    return 0;
}

void push(struct stack* s, float element) {
    if (!isfull(s)) {
        s->tos += 1;
        s->element[s->tos] = element;
    } else {
        cout << "Stack is Full. Can't push." << endl;
    }
}

float pop(struct stack* s) {
    if (!isempty(s)) {
        float element = s->element[s->tos];
        s->tos -= 1;
        return element;
    } else {
        cout << "Stack Underflow!" << endl;
        return 0;
    }
}

bool isfull(struct stack* s) {
    return s->tos == maxsize - 1;
}

bool isempty(struct stack* s) {
    return s->tos == -1;
}

void operate(struct stack* s, char oper) {
    float operand2 = pop(s);
    float operand1 = pop(s);

    switch (oper) {
        case '+': push(s, operand1 + operand2); break;
        case '-': push(s, operand1 - operand2); break;
        case '*': push(s, operand1 * operand2); break;
        case '/': push(s, operand1 / operand2); break;
        case '$': push(s, pow(operand1, operand2)); break;  // '$' for exponentiation
        default: cout << "Unknown operator: " << oper << endl;
    }
}
