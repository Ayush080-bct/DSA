
#include <cstdlib>
#include <iostream>
#include <string>
#include"Stack.h"
void eval(std::string A, Stack *s) {
    float op1;
    float op2, result;
    for (int i = A.length() - 1; i >= 0; i--) {
        if (A[i] == ' ')
            continue;
        else if (isdigit(A[i]) || A[i] == '.') {
            std::string num;
            while (i >= 0 && (isdigit(A[i]) || A[i] == '.')) {
                num = A[i] + num;

                i--;
            }
            i++;

            float n = stof(num);  // Convert string to float
            s->push(s, n);

        } else {
            op1 = s->pull(s);
            op2 = s->pull(s);
            switch (A[i]) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    if (op2 == 0) {
                        std::cerr << "Not divisable By zero ! " << std::endl;
                        exit(0);
                    } else {
                        result = op1 / op2;
                    }
                    break;
                default:
                    std::cout << "unidentifed !" << std::endl;
                    break;
            }
            s->push(s, result);
        }
    }
    std::cout << "The evaluated value is " << result << std::endl;
}


int main() {
    Stack s = {-1};
    std::string Equation;
    std::cout << "Enter the Equation : ";
    std::getline(std::cin, Equation);
    eval(Equation, &s);
    return 0;
}