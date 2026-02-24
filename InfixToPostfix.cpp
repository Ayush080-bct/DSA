#include <iostream>
#include <string>
#define MAXSIZE 100

struct stack {
    char data[MAXSIZE];
    int tos;
};

char pop(struct stack *s) {
    if (s->tos == -1) {
        std::cout << "Stack Underflow\n";
        return '\0';
    }
    char element = s->data[s->tos];
    s->tos--;
    return element;
}

void push(struct stack *s, char element) {
    if (s->tos == MAXSIZE - 1) {
        std::cout << "Stack Overflow\n";
        return;
    }
    s->tos++;
    s->data[s->tos] = element;
}

char peek(struct stack *s) {
    if (s->tos == -1) return '\0';
    return s->data[s->tos];
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    else
        return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

std::string InfixToPostfix(std::string Exp) {
    struct stack s;
    s.tos = -1;

    std::string result = "";

    for (int i = 0; i < Exp.length(); i++) {
        char ch = Exp[i];

        if (ch == ' ') continue;

        if (isalnum(ch)) {
            result += ch;
            result += ' ';
        }

        else if (ch == '(') {
            push(&s, ch);
        }

        else if (ch == ')') {
            while (peek(&s) != '(' && s.tos != -1) {
                result += pop(&s);
            }
            if (peek(&s) == '(') pop(&s);
        }

        else if (isOperator(ch)) {
            while (s.tos != -1 && precedence(ch) <= precedence(peek(&s))) {
                result += pop(&s);
                result += ' ';
            }
            push(&s, ch);
        }
    }

    while (s.tos != -1) {
        result += pop(&s);
        result += ' ';
    }

    return result;
}

int main() {
    std::string Exp;
    std::cout << "Enter the Expression of Infix: ";
    getline(std::cin, Exp);
    std::cout << "The Expression is : " << Exp << std::endl;

    std::string Postfix = InfixToPostfix(Exp);
    std::cout << "The PostFix Expression is : " << Postfix << std::endl;

    return 0;
}
